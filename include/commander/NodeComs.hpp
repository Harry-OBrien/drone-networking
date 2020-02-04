//
//  NodeComs.hpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef NODE_COMMUNICATIONS_HPP
#define NODE_COMMUNICATIONS_HPP

#include "../common/Packet.hpp"
#include "./Node.hpp"

class NodeComs {
	// TODO: Make multithreaded
	// TODO: Make encrypted with openssl
public:
	bool sendPacketTo(Node* node, Packet const& pkt);

private:
	bool connectToNode(Node* node);

	//TODO: register callback for recieved data
};


#endif /* defined NODE_COMMUNICATIONS_HPP */
