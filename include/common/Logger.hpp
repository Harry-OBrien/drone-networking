//
//  Logger.hpp
//  SwarmCommon
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>

class Logger {
  std::ofstream logFile;

public:
  //Singleton design patter
  static Logger& getInstance()
  {
      static Logger instance;
      return instance;
  }

  Logger(Logger const&) = delete;
  void operator=(Logger const&) = delete;

  void write(std::string message);

  // Close file on destruction
  ~Logger() {
    logFile.close();
  }

private:
  //private constructor to force singleton design pattern
  Logger() {
    logFile.open("log.txt", std::ios::app | std::ios::out);

    write("\n\n======================= LOG FILE RESTART =======================");
  }

};

#endif /* defined LOGGER_HPP */
