//
//  Logger.cpp
//  SwarmCommon
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include "common/Logger.hpp"
#include <iostream>

void Logger::write(std::string message) {
	
	if(logFile.is_open()) {
		logFile << message << std::endl;
		std::cout << message << std::endl;
	}
	else
		std::cerr << "ERROR: Failed writing to log file" << std::endl;
}
