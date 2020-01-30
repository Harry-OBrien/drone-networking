//
//  main.cpp
//  SwarmCommander
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

int main(int argc, const char * argv[]) {

  //create socket
  int networkSocket;
  networkSocket = socket(AF_INET, SOCK_STREAM, 0);

  //specify address structure for socket
  struct sockaddr_in serverAddr;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(9090);
  serverAddr.sin_addr.s_addr = in6_addr("172.16.20.9");

  //connect
  int connectionStatus = connect(networkSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  //Check for error in connection
  if(connectionStatus != 0){
    printf("There was an error in connecting to the server!\n");
    return connectionStatus;
  }

  //recieve data from server
  char serverResponse[256];
  recv(networkSocket, &serverResponse, sizeof(serverResponse), 0);

  //print out server's response and close socket
  printf("The server sent the data: %s\n", serverResponse);
  close(networkSocket);


	return 0;
}



















// Wait for network access

// Try and connect to all devices on network

// Send a command (e.g. "take off now")

// Recieve data from swarm network

// print receieved data to consoles
