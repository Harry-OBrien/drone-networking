//
//  UserInterface.cpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 04/02/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include <commander/UserInterface.hpp>
#include <common/Logger.hpp>

#include <iostream>

//TODO: Implement 'back' option

UserInterface::UserInterface(SwarmHandler* _swarmHandler) {
  swarmHandler = _swarmHandler;
}

void UserInterface::init() {
  if(swarmHandler == nullptr){
    Logger::getInstance().write("FATAL: UI must have a valid reference to a swarm handler object.");
    currentState = State::SHOULD_EXIT;
    return;
  }

  //Set state to active
  currentState = State::MODE_SELECT;
}

void UserInterface::run() {
  // Make sure the ui is initialised first
  if(currentState == State::UNINITIALISED) {
    Logger::getInstance().write("FATAL: Attempting to run UI before initialising!");
    currentState = State::SHOULD_EXIT;
    return;
  }

  //List options
  printOptions();

  if(!optionsAreAvailable()) {
    currentState = State::MODE_SELECT;
    return;
  }

  // get input
  std::string input = getInput();

  // handle state based on input
  handleUserInput(input);
}

bool UserInterface::shouldExit() {
  return currentState == State::SHOULD_EXIT;
}

// Choice selection
void UserInterface::printOptions() {
  switch (currentState) {
    case State::MODE_SELECT:
      printModeSelectOptions();
      return;

    case State::TARGET_SELECT:
      printTargetSelectionOptions();
      return;

    case State::PACKET_CONSTRUCTION:
      printPacketConstuctionOptions();
      return;

    case State::MESSAGE_CONSTRUCTION:
      printMessageConstructionOptions();
      return;

    case State::COMMAND_CONSTRUCTION:
      printCommandConstructionOptions();
      return;

    default:
      std::cout << "The mode " << stateNameInverse(currentState) << " is currently not implemented" << std::endl;
      return;
  }
}

bool UserInterface::optionsAreAvailable() {
  switch(currentState) {
    case State::MODE_SELECT:
      return true;

    case State::TARGET_SELECT:
      return swarmHandler->getNodeCount() > 0;

     case State::PACKET_CONSTRUCTION:
      return true;

    case State::MESSAGE_CONSTRUCTION:
     return true;

    case State::COMMAND_CONSTRUCTION:
      return true;

    default:
      return false;
  }
}

// Taking Input
std::string UserInterface::getInput() {
  std::string userInput;
  std::getline(std::cin, userInput);

  return userInput;
}

//handle choice selection
void UserInterface::handleUserInput(std::string input) {
  switch(currentState) {
    case State::MODE_SELECT:
      handleModeSelectInput(input);
      break;

    case State::TARGET_SELECT:
      handleTargetSelectInput(input);
      break;

    case State::PACKET_CONSTRUCTION:
      handlePacketConstructionInput(input);
      break;

    case State::MESSAGE_CONSTRUCTION:
      handleMessageConstructionInput(input);
      break;

    case State::COMMAND_CONSTRUCTION:
      handleCommandConstructionInput(input);
      break;

    default:
      return;
  }
}

//Convert string to number -> handle invalid inputs
int UserInterface::numericalInputForString(std::string input, int choiceCount) {
  try {
    int choice = std::stoi(input);
    if (choice <= 0 || choice > choiceCount)
      return -1;
    else
      return choice;

  } catch(std::invalid_argument) {
    return -1;
  } catch(std::out_of_range) {
    return -1;
  }
}

//invalid choice
void UserInterface::invalidChoiceSelected() {
  std::cout << "Invalid choice selected. Please try again..." << std::endl;
}
