#ifndef IDALS_H
#define IDALS_H

#include "Arduino.h"
#include "LoRaWan_APP.h"
#include "types.h"
//#include "esp_random.h"

#define GPS_RX 29
#define GPS_TX 30
#define CRACHA_ID 30





/** Definições usados no wifi v3
RTC_DATA_ATTR bool firstrun = true;

#define CRACHA_ID 16
//#define GPS_RX 30 
//#define GPS_TX 34
#define DEBUG 0
#define GPS_RX 48
#define GPS_TX 47

#define VBAT_PIN 1      // GPIO1 para leitura da bateria na V3.2
#define ADC_CTRL_PIN 37  // GPIO37 para controle do ADC na V3.2
*/
/*
enum PacketSituation {
  ALL_NORMAL = 0,
  PANIC_SITUATION = 4,
  WITHOUT_GPS_SIGNAL = 5,
  OUT_OF_WORK_AREA = 6,
  NO_MOVING = 7,
  DUMP_TIME = 8
};PacketSituation packetstate;

enum MqttMessageType {
  EV
  ENT, //cancela e cracha
  VERIFY, //cancela e cracha
  TRACK, //cancela e cracha
  EMERGENCY_XPOINT, //botao. 
  TRACK_XPOINT, //posição
  PM
};
*/

#pragma pack(push, 1)
struct packetLoraWan {
  uint8_t type;        // 1 byte
  uint8_t packetid;    // 1 byte
  uint8_t crachaID;    // 1 byte
  uint8_t emergency;   // 1 byte
  float lat;           // 4 bytes
  float lon;           // 4 bytes
  float alt;           // 4 bytes
  float course;        // 4 bytes
  float speed;         // 4 bytes
  float sats;          // 4 bytes
  uint32_t hdop;       // 4 bytes
  uint32_t timeStamp;  // 4 bytes
  uint8_t packetstate; // 1 byte (enum como uint8_t)
  uint16_t batteryVoltage; // 2 bytes
};
#pragma pack(pop)

//packetLoraWan packet;
extern packetLoraWan packet;



/*
void log(String msg){
  #if (DEBUG == 1)
    Serial.println(msg);
  #endif
}
*/
/*
uint32_t getTimestamp() {
  if (gps.time.isValid() && gps.date.isValid()) {
    // Cálculo manual do timestamp Unix
    // Baseado em: https://stackoverflow.com/questions/7960318/math-to-convert-seconds-since-1970-into-date-and-vice-versa
    
    uint16_t year = gps.date.year();
    uint8_t month = gps.date.month();
    uint8_t day = gps.date.day();
    uint8_t hour = gps.time.hour();
    uint8_t minute = gps.time.minute();
    uint8_t second = gps.time.second();
    
    // Cálculo do dia juliano
    if (month <= 2) {
      year--;
      month += 12;
    }
    
    uint32_t a = year / 100;
    uint32_t b = a / 4;
    uint32_t c = 2 - a + b;
    uint32_t d = 365.25 * (year + 4716);
    uint32_t e = 30.6001 * (month + 1);
    
    uint32_t jd = d + e + day + c - 1524;
    uint32_t daysSinceEpoch = jd - 2440588;  // 1/1/1970 em juliano
    
    uint32_t unixTime = (daysSinceEpoch * 86400UL) + 
                       (hour * 3600UL) + 
                       (minute * 60UL) + 
                       second;
    
    return unixTime;
  }
  
  // Fallback
  return millis() / 1000;
}
*/
/*
uint16_t readBatteryVoltage() {
  // Configurar pino de controle - INVERTIDO na V3.2!
  pinMode(ADC_CTRL_PIN, OUTPUT);
  digitalWrite(ADC_CTRL_PIN, HIGH);  // HIGH para habilitar leitura na V3.2
  delay(10);
  
  // Fazer média de várias leituras
  const int numReadings = 10;
  uint32_t sum = 0;
  
  for (int i = 0; i < numReadings; i++) {
    sum += analogRead(VBAT_PIN);
    delay(2);
  }
  
  // Desabilitar circuito de medição
  digitalWrite(ADC_CTRL_PIN, LOW);
  
  int analogValue = sum / numReadings;
  
  // Calcular tensão (divisor 220K+100K = 3.2:1)
  float pinVoltage = analogValue * (3.3 / 4095.0);
  float batteryVoltage = pinVoltage * 4.8;
  
  #if (DEBUG == 1)
    Serial.print("ADC Value: ");
    Serial.println(analogValue);
    Serial.print("Battery Voltage: ");
    Serial.print(batteryVoltage, 2);
    Serial.println("V");
  #endif
  
  return (uint16_t)(batteryVoltage * 1000.0);
}
*/





#define sendLoraWan(struct_type, packet) do { \
  appDataSize = sizeof(struct_type); \
  memcpy(appData, packet, appDataSize); \
} while(0)

/*
void debugV32Battery() {
  Serial.println("=== DIAGNÓSTICO V3.2 ===");
  
  // Testar diferentes configurações
  pinMode(ADC_CTRL_PIN, OUTPUT);
  
  // Teste 1: ADC_Ctrl LOW (deveria desabilitar)
  digitalWrite(ADC_CTRL_PIN, LOW);
  delay(100);
  Serial.print("ADC_Ctrl LOW: ");
  Serial.println(analogRead(VBAT_PIN));
  
  // Teste 2: ADC_Ctrl HIGH (deveria habilitar)
  digitalWrite(ADC_CTRL_PIN, HIGH);
  delay(100);
  Serial.print("ADC_Ctrl HIGH: ");
  Serial.println(analogRead(VBAT_PIN));
  
  // Teste 3: Múltiplas leituras com HIGH
  digitalWrite(ADC_CTRL_PIN, HIGH);
  delay(10);
  for (int i = 0; i < 5; i++) {
    Serial.print("Leitura ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(analogRead(VBAT_PIN));
    delay(100);
  }
  
  digitalWrite(ADC_CTRL_PIN, LOW); // Desabilitar
}
*/
/*
void calibrateBattery() {
  Serial.println("=== CALIBRAÇÃO ===");
  
  pinMode(ADC_CTRL_PIN, OUTPUT);
  digitalWrite(ADC_CTRL_PIN, HIGH);
  delay(10);
  
  int raw = analogRead(VBAT_PIN);
  float pinVoltage = raw * (3.3 / 4095.0);
  
  // Testar diferentes fatores
  for (float factor = 1.0; factor <= 2.0; factor += 0.1) {
    float batteryVoltage = pinVoltage * factor;
    Serial.print("Factor ");
    Serial.print(factor, 1);
    Serial.print(": ");
    Serial.print(batteryVoltage, 2);
    Serial.println("V");
  }
  
  digitalWrite(ADC_CTRL_PIN, LOW);
}
*/





#endif
