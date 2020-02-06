//
//  UserInterface.hpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 04/02/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <commander/SwarmHandler.hpp>
#include <string>

// TODO: Put commands executed by the user interface in another thread UI is not sharing main thread
// TODO: Refactor into common classes -> Polymorphism

class UserInterface {
  enum State {
    UNINITIALISED,
    MODE_SELECT,
    MESSAGE_READ,
    SHOULD_EXIT,
    TARGET_SELECT,
    PACKET_CONSTRUCTION,
    MESSAGE_CONSTRUCTION,
    COMMAND_CONSTRUCTION,
    PACKET_SEND,
  };

  struct
  {
    const char* operator()(State s)
    {
      const char* state[] = {
        "UNINITIALISED",
        "MODE_SELECT",
        "MESSAGE_READ",
        "SHOULD_EXIT",
        "TARGET_SELECT",
        "PACKET_CONSTRUCTION",
        "MESSAGE_CONSTRUCTION",
        "COMMAND_CONSTRUCTION",
      };

      return state[s];
    }
  } stateNameInverse;

  State currentState = State::UNINITIALISED;
  SwarmHandler* swarmHandler;

  int targetNodeIndex = -1;

public:
  UserInterface(SwarmHandler* _swarmHandler);
  void init();
  void run();
  bool shouldExit();

private:
  // Choice selection
  void printOptions();
  bool optionsAreAvailable();
  void printModeSelectOptions();
  void printTargetSelectionOptions();
  void printPacketConstuctionOptions();
  void printMessageConstructionOptions();
  void printCommandConstructionOptions();


  // Taking Input
  std::string getInput();

  //handle choice selection
  void handleUserInput(std::string input);
  void handleModeSelectInput(std::string input);
  void handleTargetSelectInput(std::string input);
  void handlePacketConstructionInput(std::string input);
  void handleMessageConstructionInput(std::string input);
  void handleCommandConstructionInput(std::string input);

  //Helper functions
  int numericalInputForString(std::string input, int choiceCount);
  void invalidChoiceSelected();

};

#endif /* defined USER_INTERFACE_HPP */


	// STEP 1
  // Read packet rec
  // Send message

  // STEP 2
	// choose node
		// -> node 1
		// -> node 2
		// -> ALL nodes

	// STEP 3
	// opt 1 -> send message
		// -> Enter message
	// opt 2 -> send command
		// -> Select command
			// -> Take off
			// -> Land
			// -> Shutdown
