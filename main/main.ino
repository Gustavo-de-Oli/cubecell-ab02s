#include "Arduino.h"
#include "LoRaWan_APP.h"
#include <GPS_Air530Z.h>
#include "types.h"
#include "lorawanparam.h"
#include "functions.h"
#include "idals.h"

// Objetos globais
Air530ZClass gps;
bool panic = false;
packetLoraWan packet;


void setup() {
  Serial.begin(115200);
  gps.begin();       // AIR530Z usa 9600 baud

  logSerial("Começo do funcionamento");
  deviceState = DEVICE_STATE_INIT;
}

void loop() {
  // Alimenta GPS
  while (gps.available()) {
    gps.encode(gps.read());
  }

  // Mostra no terminal os dados do GPS (debug)
  printGpsData();

  switch (deviceState) {
    case DEVICE_STATE_INIT: {
      #if (LORAWAN_DEVEUI_AUTO)
        LoRaWAN.generateDeveuiByChipID();
      #endif
      printDevParam();
      LoRaWAN.init(loraWanClass, loraWanRegion);
      deviceState = DEVICE_STATE_JOIN;
      break;
    }
    case DEVICE_STATE_JOIN: {
      LoRaWAN.join();
      break;
    }
    case DEVICE_STATE_SEND: {
      prepareTxFrame(PM, appPort);   // monta pacote GPS
      LoRaWAN.send();
      deviceState = DEVICE_STATE_CYCLE;
      break;
    }
    case DEVICE_STATE_CYCLE: {
      txDutyCycleTime = appTxDutyCycle + randr(0, APP_TX_DUTYCYCLE_RND);
      LoRaWAN.cycle(txDutyCycleTime);
      deviceState = DEVICE_STATE_SLEEP;
      break;
    }
    case DEVICE_STATE_SLEEP: {
      LoRaWAN.sleep();
      break;
    }
    default: {
      deviceState = DEVICE_STATE_INIT;
      break;
    }
  }
}
