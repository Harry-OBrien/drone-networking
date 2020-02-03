//
//  main.cpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 05/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include <commander/SwarmHandler.hpp>
#include <common/Logger.hpp>

//TODO: Change all instances of std::cout to logger.write

int main() {

	Logger::getInstance().write("BEGIN: Commander");

	SwarmHandler SwarmHandler;
	//TODO: Properly handle message sending
	Packet pkt;
	pkt.type = PacketType::MESSAGE;

	MessagePacket mPkt;
	strcpy(mPkt.message, "Hello from the controller!");
	mPkt.shouldLogMessage = true;

	pkt.msg = mPkt;

	SwarmHandler.sendToAll(pkt);

	return 0;
}
