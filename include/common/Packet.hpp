//
//  Packet.hpp
//  SwarmCommon
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef PACKETS_HPP
#define PACKETS_HPP

#include "packets/MessagePacket.hpp"
#include "packets/CmdPacket.hpp"

struct Packet {
  enum Type {
    COMMAND,
    MESSAGE
  };

  Packet() {}

  ~Packet() {}

  char* timeSent = nullptr;
  char* recipientIp = nullptr;
  char* senderIp = nullptr;

  Type type;

  union {
    MessagePacket msg;
    CmdPacket cmd;
  };

};

#endif /* defined PACKETS_HPP */
