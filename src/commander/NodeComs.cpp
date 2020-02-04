//
//  NodeCommunications.cpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <string>

#include "commander/NodeComs.hpp"
#include "common/Config.hpp"
#include "common/Logger.hpp"

bool NodeComs::sendPacketTo(Node* node, Packet const& pkt) {
	//check if node has alive socket
	if(node->server == nullptr) {
		if(!connectToNode(node)) {
			return false;
		}
	}
	
	//send some data
	if(send(node->associatedSocket, (void *) &pkt, sizeof(pkt), 0) < 0) return false;
	
	Logger::getInstance().write("Packet sent to node at " + node->ipAddr);
	
	//TODO: Move recv into own function
	Packet recievedPacket;
	read(node->associatedSocket, (void*) &recievedPacket, sizeof(recievedPacket));
	Logger::getInstance().write("Server response: " + std::string(recievedPacket.msg.message));
		
	return true;
}

bool NodeComs::connectToNode(Node* node) {
	//connection is not alive, create one now
	
	Logger::getInstance().write("Attempting connection to " + node->ipAddr);
	
	node->associatedSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (node->associatedSocket < 0) {
		Logger::getInstance().write("Socket initialisation FAILED for not at " + node->ipAddr);
		return false;
	}
	
	node->server = new sockaddr_in;
	node->server->sin_family = AF_INET;
	node->server->sin_port = htons(Config::COMMAND_PORT);
	node->server->sin_addr.s_addr = inet_addr(node->ipAddr.c_str());
	
	//connect
	if(connect(node->associatedSocket, (struct sockaddr *) node->server, sizeof(*node->server)) < 0) {
		Logger::getInstance().write("Connection FAILED for node at " + node->ipAddr);

		return false;
	}
	
	Logger::getInstance().write("Connection SUCCEEDED for node at " + node->ipAddr);
	return true;
}
