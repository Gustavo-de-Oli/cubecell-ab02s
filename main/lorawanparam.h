#ifndef LORAWAN_PARAM_H
#define LORAWAN_PARAM_H

#include "LoRaWan_APP.h"

/*Parte dos parametros*/

//--OTAA
//94 f6 e9 be cd 8d 58 25
uint8_t devEui[] = {0x94, 0xf6, 0xe9, 0xbe, 0xcd, 0x8d, 0x58, 0x25};
uint8_t appEui[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t appKey[] = { 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x66, 0x01 };

//--ABP

/** cubecell#01 
//00D4DEDF cubecell#01
//uint8_t nwkSKey[] = 9258499F7D86941FEC561B998D09EEBB
uint8_t nwkSKey[] = {0x92, 0x58, 0x49, 0x9F, 0x7D, 0x86, 0x94, 0x1F, 0xEC, 0x56, 0x1B, 0x99, 0x8D, 0x09, 0xEE, 0xBB};
//uint8_t appSKey[] = 42A7093DB4377F0D6A8417E191E001E5
uint8_t appSKey[] = {0x42, 0xA7, 0x09, 0x3D, 0xB4, 0x37, 0x7F, 0x0D, 0x6A, 0x84, 0x17, 0xE1, 0x91, 0xE0, 0x01, 0xE5};
uint32_t devAddr = (uint32_t)0x00D4DEDF;
**/

/** cubecell#02 
 *  Nome: Amanda
 *  deveui: fcb1e302faba9840 
 *  nwk 9a 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
 *  awk 9b 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
 *  devAddr 9a 00 00 00
 *  AMANDA_09
 *  
 
 uint8_t nwkSKey[] = {0x9a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
 uint8_t appSKey[] = {0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint32_t devAddr = (uint32_t)0x9a000000;
*/

/** cubecell#03 
 *  Nome: Fabiano
 *  deveui: 6e61d507c6284b80 
 *  nwk 2a 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
 *  awk 2b 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
 *  devAddr 2a 00 00 00
 *  TEIXEIRA_02
 *  Fabiano
*//*
 uint8_t nwkSKey[] = {0x2a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
 uint8_t appSKey[] = {0x2b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint32_t devAddr = (uint32_t)0x2a000000;
*/

 /** cubecell#11 
 *  Nome: Lucas
 *  deveui: 1d3c8331958c1cf6 
 *  nwk 11 a0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
 *  awk 11 b0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
 *  devAddr 11 a0 00 00
 *  VSB_2
 */  /*
 
uint8_t nwkSKey[] = {0x11, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t appSKey[] = {0x11, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint32_t devAddr = (uint32_t)0x11a00000;
*/

/** cubecell#31
 *  Nome: Davison
 *  deveui: d5078d6a5210db1f
 *  nwk 31 a0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
 *  awk 31 b0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
 *  devAddr 31 a0 00 00
 *  Elisa_31
 */  
 
uint8_t nwkSKey[] = {0x31, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t appSKey[] = {0x31, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint32_t devAddr = (uint32_t)0x31a00000;


/** cubecell#24
 *  Nome: Vanderlei
 *  deveui: 46f69363bc9eddfc
 *  nwk 24 a0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
 *  awk 24 b0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
 *  devAddr 24 a0 00 00
 *  Dada_24
 */  
/* 
uint8_t nwkSKey[] = {0x24, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint8_t appSKey[] = {0x24, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
uint32_t devAddr = (uint32_t)0x24a00000;
*/

/** 32v3#02 
//000f0a67 32v3#02
//uint8_t nwkSKey[] = 6ce69afd888a4f754ac69138240812ed
uint8_t nwkSKey[] = {0x6c, 0xe6, 0x9a, 0xfd, 0x88, 0x8a, 0x4f, 0x75, 0x4a, 0xc6, 0x91, 0x38, 0x24, 0x08, 0x12, 0xed} ;
//uint8_t appSKey[] = 9e4c63b2e142a2c834bfc3a29ecc68b4
uint8_t appSKey[] = {0x9e, 0x4c, 0x63, 0xb2, 0xe1, 0x42, 0xa2, 0xc8, 0x34, 0xbf, 0xc3, 0xa2, 0x9e, 0xcc, 0x68, 0xb4};
uint32_t devAddr = (uint32_t)0x000f0a67;

/*LoraWan channelsmask, default channels 0-7*/
uint16_t userChannelsMask[6]={ 0x00FF,0x0000,0x0000,0x0000,0x0000,0x0000 };

/*LoraWan region, select in arduino IDE tools*/
LoRaMacRegion_t loraWanRegion = ACTIVE_REGION;

/*LoraWan Class, Class A and Class C are supported*/
DeviceClass_t loraWanClass = LORAWAN_CLASS;

/*the application data transmission duty cycle. value in [ms].*/
uint32_t appTxDutyCycle = 15000;

/*OTAA or ABP*/
bool overTheAirActivation = LORAWAN_NETMODE;

/*ADR enable*/
bool loraWanAdr = LORAWAN_ADR;

/* set LORAWAN_Net_Reserve ON, the node could save the network info to flash, when node reset not need to join again */
bool keepNet = LORAWAN_NET_RESERVE;

/* Indicates if the node is sending confirmed or unconfirmed messages */
bool isTxConfirmed = LORAWAN_UPLINKMODE;

/* Application port */
uint8_t appPort = 2;

/*!
 * Number of trials to transmit the frame, if the LoRaMAC layer did not
 * receive an acknowledgment. The MAC performs a datarate adaptation,
 * according to the LoRaWAN Specification V1.0.2, chapter 18.4, according
 * to the following table:
 *
 * Transmission nb | Data Rate
 * ----------------|-----------
 * 1 (first)      | DR
 * 2              | DR
 * 3              | max(DR-1,0)
 * 4              | max(DR-1,0)
 * 5              | max(DR-2,0)
 * 6              | max(DR-2,0)
 * 7              | max(DR-3,0)
 * 8              | max(DR-3,0)
 *
 * Note, that if NbTrials is set to 1 or 2, the MAC will not decrease
 * the datarate, in case the LoRaMAC layer did not receive an acknowledgment
 */
uint8_t confirmedNbTrials = 4;

#endif
