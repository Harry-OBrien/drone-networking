//
//  main.cpp
//  SwarmListener
//
//  Created by Harry O'Brien on 05/01/2020.
//  Copyright © 2020 SociaDevLtd. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

int maxBacklog = 18;
char serverMessage[] = "Zuck on this!";

int main(int argc, const char * argv[]) {

	  //create socket
	  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	  //define the server address
	  struct sockaddr_in serverAddr;
	  serverAddr.sin_family = AF_INET;
	  serverAddr.sin_port = htons(9090);
	  serverAddr.sin_addr.s_addr = INADDR_ANY;

	  //Bind to client and listen for incomming connections
	  bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	  while(true){
	    listen(serverSocket, maxBacklog);

	    int clientSocket = accept(serverSocket, nullptr, nullptr);

	    //send message to client
	    send(clientSocket, serverMessage, sizeof(serverMessage), 0);

	    //close socket
	    close(clientSocket);
	  }

	return 0;
}


















	// start up a server

	//forever:
		// wait for a command

		// execute command

		// return response to client
