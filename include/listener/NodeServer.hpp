//
//  NodeServer.hpp
//  SwarmListener
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef NODE_SERVER_HPP
#define NODE_SERVER_HPP

#include <netinet/in.h>

class NodeServer {

  const int maxBacklog;
  int serverSocket;
  sockaddr_in serverAddr;

public:
  NodeServer();
  void handleClientSocket();
};

#endif /* defined NODE_SERVER_HPP */
