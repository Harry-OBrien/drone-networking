//
//  Node.hpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <netinet/in.h>

struct Node {
  std::string ipAddr;
  std::string macAddr;
  std::string hostname;

	int associatedSocket = -1;
	sockaddr_in* server;

  ~Node() {
    if(server != nullptr) {
      delete server;
    }
  }
};

#endif /* defined NODE_HPP */
