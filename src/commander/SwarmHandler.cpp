//
//  SwarmHandler.cpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include <commander/SwarmHandler.hpp>
#include <common/Logger.hpp>
#include <cstring>

SwarmHandler::SwarmHandler() {
  // Get all nodes on network
  nodes = locator.getNodes();
}

void SwarmHandler::init() {
  //
}

std::size_t SwarmHandler::getNodeCount() {
  return nodes.size();
}

void SwarmHandler::sendMessageToNode(int nodeIndex, std::string message){
  Packet pkt;
  pkt.type = Packet::Type::MESSAGE;
  strcpy(pkt.msg.message, message.c_str());
  sendToNode(&nodes[nodeIndex], pkt);
}

void SwarmHandler::sendMessageToAll(std::string message){
  Packet pkt;
  pkt.type = Packet::Type::MESSAGE;
  strcpy(pkt.msg.message, message.c_str());
  sendToAll(pkt);
}

void SwarmHandler::sendCommandToNode(int nodeIndex, Command cmd){
  Packet pkt;
  pkt.type = Packet::Type::COMMAND;
  pkt.cmd = cmd;
  sendToNode(&nodes[nodeIndex], pkt);
}

void SwarmHandler::sendCommandToAll(Command cmd){
  Packet pkt;
  pkt.type = Packet::Type::COMMAND;
  pkt.cmd = cmd;
  sendToAll(pkt);
}

void SwarmHandler::sendToNode(Node* node, Packet const& pkt) {
	Logger::getInstance().write("Sending packet to node at " + node->ipAddr);
  coms.sendPacketTo(node, pkt);
}

void SwarmHandler::sendToAll(Packet const& pkt) {
  for(size_t i = 0; i < nodes.size(); i++)
    sendToNode(&nodes[i], pkt);
}
