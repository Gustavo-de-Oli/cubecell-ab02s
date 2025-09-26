#include "functions.h"

PacketSituation packetstate;
//extern HardwareSerial GPS_Serial;

// Funções de log
void logSerial(const String& mensagem) { if (DEBUG) Serial.println(mensagem); }
void logSerial(const char* mensagem) { if (DEBUG) Serial.println(mensagem); }
void logSerial(float value, int decimais) { if (DEBUG) Serial.println(value, decimais); }
void logSerial(int value) { if (DEBUG) Serial.println(value); }

// Monta pacote (39 bytes)
void prepareTxFrame(enum MqttMessageType type, uint8_t port) {
  // Atualiza GPS antes de capturar
  while (gps.available() > 0) {
    gps.encode(gps.read());
  }

  /*device info*/
  packet.type = PM; //mqtt type
  packet.packetid = int(millis()); //esp_random();  // packet id                  
  packet.crachaID = CRACHA_ID;      //     pm id                 
  packet.emergency = 0;  //TODO implementar a regra de pânico/prioridade

  // --- GPS ---
  packet.lat    = gps.location.isValid() ? gps.location.lat() : 0.0;
  packet.lon    = gps.location.isValid() ? gps.location.lng() : 0.0;
  packet.alt    = gps.altitude.isValid() ? gps.altitude.meters() : 0.0;
  packet.course = gps.course.isValid() ? gps.course.deg() : 0.0;
  packet.speed  = gps.speed.isValid() ? gps.speed.kmph() : 0.0;
  packet.sats   = gps.satellites.isValid() ? gps.satellites.value() : 0;
  packet.hdop   = gps.hdop.isValid() ? gps.hdop.value() : 0;
  packet.timeStamp = 0;//getTimestamp();
  
  // --- Outros campos ---
  //packet.timeStamp      = millis(); //getTimestamp();
  packet.batteryVoltage = getBatteryPercentage();
  packet.packetstate    = packetstate;
  packet.type           = type;
  packet.packetid       = cubecell_random(0xFF);
  packet.crachaID       = CRACHA_ID;
  packet.emergency      = panic ? 1 : 0;

  // Copia struct para appData (39 bytes)
  memcpy(appData, &packet, sizeof(packet));
  appDataSize = sizeof(packet);

  logSerial("Pacote pronto, size:");
  logSerial((int)appDataSize);
}

uint16_t getBatteryPercentage() {
  uint16_t voltageMV = getBatteryVoltage();
  float batteryVoltage = voltageMV / 1000.0; // Converter para volts
  
  // Curva de descarga para LiPo
  if (batteryVoltage >= 4.20) return 10000;    // 100.00%
  if (batteryVoltage >= 4.15) return 9750;     // 97.50%
  if (batteryVoltage >= 4.10) return 9500;     // 95.00%
  if (batteryVoltage >= 4.05) return 9250;     // 92.50%
  if (batteryVoltage >= 4.00) return 9000;     // 90.00%
  if (batteryVoltage >= 3.95) return 8500;     // 85.00%
  if (batteryVoltage >= 3.90) return 8000;     // 80.00%
  if (batteryVoltage >= 3.85) return 7500;     // 75.00%
  if (batteryVoltage >= 3.80) return 7000;     // 70.00%
  if (batteryVoltage >= 3.75) return 6500;     // 65.00%
  if (batteryVoltage >= 3.70) return 6000;     // 60.00%
  if (batteryVoltage >= 3.65) return 5500;     // 55.00%
  if (batteryVoltage >= 3.60) return 5000;     // 50.00%
  if (batteryVoltage >= 3.55) return 4500;     // 45.00%
  if (batteryVoltage >= 3.50) return 4000;     // 40.00%
  if (batteryVoltage >= 3.45) return 3500;     // 35.00%
  if (batteryVoltage >= 3.40) return 3000;     // 30.00%
  if (batteryVoltage >= 3.35) return 2500;     // 25.00%
  if (batteryVoltage >= 3.30) return 2000;     // 20.00%
  if (batteryVoltage >= 3.25) return 1500;     // 15.00%
  if (batteryVoltage >= 3.20) return 1000;     // 10.00%
  if (batteryVoltage >= 3.15) return 500;      // 5.00%
  return 0;                                    // 0.00%
}


// Exibe dados do GPS no terminal
void printGpsData() {
  Serial.print("Date/Time: ");
  if (gps.date.isValid())
  {
    Serial.printf("%d/%02d/%02d",gps.date.year(),gps.date.day(),gps.date.month());
  }
  else
  {
    Serial.print("INVALID");
  }

  if (gps.time.isValid())
  {
    Serial.printf(" %02d:%02d:%02d.%02d",gps.time.hour(),gps.time.minute(),gps.time.second(),gps.time.centisecond());
  }
  else
  {
    Serial.print(" INVALID");
  }
  Serial.println();
  
  Serial.print("LAT: ");
  Serial.print(gps.location.lat(),6);
  Serial.print(", LON: ");
  Serial.print(gps.location.lng(),6);
  Serial.print(", ALT: ");
  Serial.print(gps.altitude.meters());

  Serial.println(); 
  
  Serial.print("SATS: ");
  Serial.print(gps.satellites.value());
  Serial.print(", HDOP: ");
  Serial.print(gps.hdop.hdop());
  Serial.print(", AGE: ");
  Serial.print(gps.location.age());
  Serial.print(", COURSE: ");
  Serial.print(gps.course.deg());
  Serial.print(", SPEED: ");
  Serial.println(gps.speed.kmph());
  Serial.println();
}
