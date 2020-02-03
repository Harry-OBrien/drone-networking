//
//  CmdPacket.hpp
//  SwarmCommon
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef CMD_PACKET_HPP
#define CMD_PACKET_HPP

enum Command {
  TAKE_OFF,
  LAND
};

struct CmdPacket {
  Command cmd;
};

#endif /* defined CMD_PACKET_HPP */
