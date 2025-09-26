#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Arduino.h"
#include "LoRaWan_APP.h"
#include <GPS_Air530Z.h>
#include "types.h"
#include "idals.h"

const bool DEBUG = true;
extern Air530ZClass gps;
extern bool panic;
extern packetLoraWan packet;

// Logs
void logSerial(const String& mensagem);
void logSerial(const char* mensagem);
void logSerial(float value, int decimais = 6);
void logSerial(int value);

// Monta pacote
void prepareTxFrame(enum MqttMessageType type, uint8_t port);

// Mostra dados do GPS no Serial Monitor
void printGpsData();

// Converte bateria de volts para porcentagem
uint16_t getBatteryPercentage();
#endif
