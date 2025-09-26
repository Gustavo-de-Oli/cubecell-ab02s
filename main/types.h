#ifndef TYPES_H
#define TYPES_H

enum MqttMessageType {
  EVENT,
  VERIFY,
  TRACK,
  EMERGENCY_XPOINT,
  TRACK_XPOINT,
  PM
};

enum PacketSituation {
  ALL_NORMAL = 0,
  PANIC_SITUATION = 4,
  WITHOUT_GPS_SIGNAL = 5,
  OUT_OF_WORK_AREA = 6,
  NO_MOVING = 7,
  DUMP_TIME = 8
};

#endif