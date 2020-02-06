//
//  PacketConstruction.cpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 05/02/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include <commander/UserInterface.hpp>
#include <common/Packet.hpp>
#include <iostream>

//Option printing
void UserInterface::printPacketConstuctionOptions() {
  std::cout << "\n\e[1mSelect Message or Command:\e[0m"  << std::endl;
  std::cout << "\t1: Message" << std::endl;
  std::cout << "\t2: Command" << std::endl;
}

void UserInterface::printMessageConstructionOptions() {
  std::cout << "\n\e[1mEnter message:\e[0m"  << std::endl;
}

void UserInterface::printCommandConstructionOptions() {
  std::cout << "\n\e[1mSelect Command:\e[0m"  << std::endl;
  std::cout << "\t1: Take Off" << std::endl;
  std::cout << "\t2: Land" << std::endl;
}


//Choice Handling
void UserInterface::handlePacketConstructionInput(std::string input) {
  int choice = numericalInputForString(input, (int) 2);
  switch(choice) {
    case 1:
      currentState = State::MESSAGE_CONSTRUCTION;
      return;

    case 2:
      currentState = State::COMMAND_CONSTRUCTION;
      return;

    default:
      invalidChoiceSelected();
  }
}

void UserInterface::handleMessageConstructionInput(std::string input) {
  if(targetNodeIndex < 0)
    swarmHandler->sendMessageToAll(input);

  else
    swarmHandler->sendMessageToNode(targetNodeIndex, input);

  std::cout << "Message sent!" << std::endl;
  currentState = State::MODE_SELECT;
}

void UserInterface::handleCommandConstructionInput(std::string input) {
  int choice = numericalInputForString(input, (int) 2);
  Command cmd;
  switch(choice) {
    case 1:
      cmd = Command::TAKE_OFF;
      break;

    case 2:
      cmd = Command::LAND;
      break;

    default:
      invalidChoiceSelected();
      return;
  }

  if(targetNodeIndex < 0)
    swarmHandler->sendCommandToAll(cmd);

  else
    swarmHandler->sendCommandToNode(targetNodeIndex, cmd);

  std::cout << "Command sent!" << std::endl;
  currentState = State::MODE_SELECT;
}
