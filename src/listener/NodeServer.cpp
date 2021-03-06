//
//  NodeServer.cpp
//  SwarmListener
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include <listener/NodeServer.hpp>
#include <common/Config.hpp>
#include <common/Packet.hpp>
#include <common/Logger.hpp>

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>

NodeServer::NodeServer() :
maxBacklog(18),
serverSocket(socket(AF_INET, SOCK_STREAM, 0)) {

  //define the server address
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(Config::COMMAND_PORT);
  serverAddr.sin_addr.s_addr = INADDR_ANY;

  //Bind to client and listen for incomming connections
  if(bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)
    Logger::getInstance().write("Server FAILED to bind on port " + std::to_string(Config::COMMAND_PORT));
  else
    Logger::getInstance().write("Server bound to port " + std::to_string(Config::COMMAND_PORT));
}

void NodeServer::handleClientSocket() {
  listen(serverSocket, maxBacklog);

  int clientSocket = accept(serverSocket, nullptr, nullptr);
  if (clientSocket < 0) {
    Logger::getInstance().write("ERROR on accepting client");
    return;
  }

  std::cout << "Got connection from " << inet_ntoa(serverAddr.sin_addr) << " on port " << ntohs(serverAddr.sin_port) << std::endl;

  Packet receivedPacket;
  read(clientSocket, (void*) &receivedPacket, sizeof(receivedPacket));

  //do something with the packet
  if(receivedPacket.type != PacketType::MESSAGE) close(clientSocket);

  std::cout << "received message: " << receivedPacket.msg.message << std::endl;

  //Construct the packet to reply with
  Packet pktToSend;
  pktToSend.type = PacketType::MESSAGE;
  char response[512] = "Server received your message of: ";
  strcat(response, receivedPacket.msg.message);
  strcpy(pktToSend.msg.message, response);
  pktToSend.msg.shouldLogMessage = true;

  //send message to client
  send(clientSocket, (void *) &pktToSend, sizeof(pktToSend), 0);

  //close socket
  close(clientSocket);
}
