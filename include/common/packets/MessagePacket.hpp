//
//  MessagePacket.hpp
//  SwarmCommon
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef MESSAGE_PACKET_HPP
#define MESSAGE_PACKET_HPP

struct MessagePacket {
  char message[512];
  bool shouldLogMessage = false;
};

#endif /* defined MESSAGE_PACKET_HPP */
