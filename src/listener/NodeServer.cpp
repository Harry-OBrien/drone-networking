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

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

NodeServer::NodeServer() :
maxBacklog(18),
serverSocket(socket(AF_INET, SOCK_STREAM, 0)) {

  //define the server address
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(Config::COMMAND_PORT);
  serverAddr.sin_addr.s_addr = INADDR_ANY;

  //Bind to client and listen for incomming connections
  bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
}

void NodeServer::handleClientSocket() {
  listen(serverSocket, maxBacklog);

  int clientSocket = accept(serverSocket, nullptr, nullptr);
  if (clientSocket < 0) std::cerr << "ERROR on accept" << std::endl;

  // std::cout << "Got connection from " << inet_ntoa(serverAddr.sin_addr) << " on port " << ntohs(serverAddr.sin_port) << std::endl;

  Packet recievedPacket;
  read(clientSocket, (void*) &recievedPacket, sizeof(recievedPacket));

  //do something with the packet
  if(recievedPacket.type != PacketType::MESSAGE) close(clientSocket);

  std::cout << "Recieved message: " << recievedPacket.msg.message << std::endl;

  //Construct the packet to reply with
  Packet pktToSend;
  pktToSend.type = PacketType::MESSAGE;
  char response[512] = "Server recieved your message of: ";
  strcat(response, recievedPacket.msg.message);
  strcpy(pktToSend.msg.message, response);
  pktToSend.msg.shouldLogMessage = true;

  //send message to client
  send(clientSocket, (void *) &pktToSend, sizeof(pktToSend), 0);

  //close socket
  close(clientSocket);
}
