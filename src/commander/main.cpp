//
//  main.cpp
//  Commander
//
//  Created by Harry O'Brien on 04/02/2020.
//  Copyright © 2020 SociaDevLtd. All rights reserved.
//

#include <commander/SwarmHandler.hpp>
#include <commander/UserInterface.hpp>
#include <common/Logger.hpp>
#include <cstring>

// TODO: Modify address locator to test that a found node is actually real and not some junk IP
// TODO: Add More commands
// TODO: Implement sending commands
// TODO: Create user interface through command line
// TODO: Implement better handling of packet reception
// TODO: override '=' and 'copy' operators for message packet to make assignment easier
// TODO: Fix LIKELY Seg fault when assigning a message that is too long to mPkt.message
// TODO: Clean up include/common/Packet.hpp and include/common/packets/* to use inheretance instead of the current jank

int main(int argc, const char * argv[]) {

	Logger::getInstance("commander-log.txt").write("BEGIN: Commander");

	SwarmHandler swarmHandler;
	UserInterface ui(&swarmHandler);

	//launch ui
	ui.init();
	swarmHandler.init();

	while(!ui.shouldExit())
		ui.run();

	Logger::getInstance("commander-log.txt").write("QUITTING NOW");

	return 0;
}
