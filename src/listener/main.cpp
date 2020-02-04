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
