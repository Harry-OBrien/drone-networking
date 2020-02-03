//
//  NodeCommunications.cpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include <iostream>

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <commander/NodeComs.hpp>
#include <common/Config.hpp>

bool NodeComs::sendPacketTo(Node* node, Packet const& pkt) {
  //check if node has alive socket
  if(node->server == nullptr) {
    if(!connectToNode(node)) return false;
  }

  //send some data
  if(send(node->associatedSocket, (void *) &pkt, sizeof(pkt), 0) < 0) return false;
  std::cout << "Packet sent to node at " << node->ipAddr << std::endl;

  //TODO: Move recv into own function
  Packet recievedPacket;
  read(node->associatedSocket, (void*) &recievedPacket, sizeof(recievedPacket));
  std::cout << "Server response:\n\t" << recievedPacket.msg.message << std::endl;

  return true;
}

bool NodeComs::connectToNode(Node* node) {
  //connection is not alive, create one now
  node->associatedSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (node->associatedSocket < 0) return false;

  node->server = new sockaddr_in;
  node->server->sin_family = AF_INET;
  node->server->sin_port = htons(Config::COMMAND_PORT);
  node->server->sin_addr.s_addr = inet_addr(node->ipAddr.c_str());

  //connect
  if(connect(node->associatedSocket, (struct sockaddr *) node->server, sizeof(*node->server)) < 0) {
    std::cout << "Connection to node at " << node->ipAddr << " FAILED!" << std::endl;
    return false;
  }

  std::cout << "Connection to node at " << node->ipAddr << " SUCCEEDED!" << std::endl;
  return true;
}
