//
//  ModeSelect.cpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 04/02/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include <commander/UserInterface.hpp>
#include <iostream>

void UserInterface::printModeSelectOptions() {
  std::cout << "\n\e[1mSelect mode:\e[0m" << std::endl;
  std::cout << "\t1: Read messages" << std::endl;
  std::cout << "\t2: Send message" << std::endl;
}

void UserInterface::handleModeSelectInput(std::string input) {
  int choice = numericalInputForString(input, 2);
  switch(choice) {
    case 1:
      currentState = State::MESSAGE_READ;
      return;

    case 2:
      currentState = State::TARGET_SELECT;
      return;

    default:
      invalidChoiceSelected();
      return;
  }
}
