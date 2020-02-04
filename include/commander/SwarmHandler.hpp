//
//  SwarmHandler.hpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef NODE_HANDLER_HPP
#define NODE_HANDLER_HPP

#include <vector>
#include "./NodeAddressLocator.hpp"
#include "./Node.hpp"
#include "./NodeComs.hpp"
#include "../common/Packet.hpp"

class SwarmHandler {

  NodeAddressLocator locator;
  std::vector<Node> nodes;
  NodeComs coms;

public:
  SwarmHandler();
  std::size_t getNodeCount();

  void sendToNode(Node* node, Packet const& pkt);
  void sendToAll(Packet const& pkt);

};

#endif /* defined NODE_HANDLER_HPP */
