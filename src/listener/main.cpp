//
//  main.cpp
//  SwarmListener
//
//  Created by Harry O'Brien on 05/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include <listener/NodeServer.hpp>
#include <common/Logger.hpp>
#include <common/Config.hpp>
#include <string>

// TODO: Create command to shut down server gracefully
// TODO: Make server multi-threaded
// TODO: Implement communication to arduino for demo (OPTIONAL)
// TODO: Make Connection between Pi and Raspberry pi
// TODO: Implement 'command not recognised' message
// TODO: Implement better handling of packet on receive
// TODO: Bind functions to recieved commands
// TODO: Command to report data back to commander
// TODO: Drone -> Drone communication for spacial awareness and swarm formation

int main() {
	Logger::getInstance("listener-log.txt").write("BEGIN: Listener");

	// start up a server
	NodeServer server;

	while(true){
		Logger::getInstance().write("Waiting for connection!");
	  server.handleClientSocket();
		Logger::getInstance().write("Handled client.");
	}

	return 0;
}
