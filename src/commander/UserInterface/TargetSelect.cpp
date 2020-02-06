//
//  TargetSelect.cpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 05/02/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include <commander/UserInterface.hpp>
#include <iostream>

void UserInterface::printTargetSelectionOptions() {
  size_t nodeCount = swarmHandler->getNodeCount();

  switch(nodeCount) {
    case 0:
      std::cout << "\nThere are no valid nodes on the network. Sorry." << std::endl;
      currentState = State::MODE_SELECT;
      return;

    case 1:
      std::cout << "\n\e[1mSelect target:\e[0m"  << std::endl;
      std::cout << "\t1: Node 1" << std::endl;
      return;

    default:
      std::cout << "\n\e[1mSelect target:\e[0m"  << std::endl;
      std::cout << "\t1: Broadcast to all" << std::endl;
      std::cout << "\t2 -> " << nodeCount + 1 << ": Node [n]" << std::endl;
      return;
  }
}

void UserInterface::handleTargetSelectInput(std::string input) {
  size_t nodeCount = swarmHandler->getNodeCount();
  int choice;
  switch(nodeCount) {
    case 0:
      return;

    case 1:
      choice = numericalInputForString(input, (int) nodeCount);
      if(choice < 0) {
        invalidChoiceSelected();
        return;
      }
      targetNodeIndex = 0;
      break;

    default:
      choice = numericalInputForString(input, (int) nodeCount + 1);
      if(choice < 0) {
        invalidChoiceSelected();
        return;
      }
      if(choice == 1) targetNodeIndex = -1;
      else targetNodeIndex = choice - 2;
      break;
  }

  currentState = State::PACKET_CONSTRUCTION;
}
