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

int main() {

	// start up a server
	NodeServer server;

	Logger::getInstance().write("BEGIN: Listener");
	Logger::getInstance().write("Server began on port " + std::to_string(Config::COMMAND_PORT));

	while(true){
		Logger::getInstance().write("Waiting for connection!");
	  server.handleClientSocket();
		Logger::getInstance().write("Handled client.");
	}

	return 0;
}
