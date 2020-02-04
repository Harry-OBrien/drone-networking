//
//  main.cpp
//  Commander
//
//  Created by Harry O'Brien on 04/02/2020.
//  Copyright © 2020 SociaDevLtd. All rights reserved.
//

#include <commander/SwarmHandler.hpp>
#include <common/Logger.hpp>
#include <cstring>

// TODO: Add More commands
// TODO: Implement sending commands
// TODO: Create user interface through command line
// TODO: Implement better handling of packet reception
// TODO: override '=' and 'copy' operators for message packet to make assignment easier

int main(int argc, const char * argv[]) {

	Logger::getInstance("commander-log.txt").write("BEGIN: Commander");

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



//TODO: Change all instances of std::cout to logger.write
