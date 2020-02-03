//
//  SwarmHandler.cpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include <commander/SwarmHandler.hpp>
#include <iostream>

SwarmHandler::SwarmHandler() {
  // Get all nodes on network
  nodes = locator.getNodes();
}

std::size_t SwarmHandler::getNodeCount() {
  return nodes.size();
}

void SwarmHandler::sendToNode(Node* node, Packet const& pkt) {
  coms.sendPacketTo(node, pkt);
}

void SwarmHandler::sendToAll(Packet const& pkt) {
  for(size_t i = 0; i < nodes.size(); i++)
    sendToNode(&nodes[i], pkt);

}
