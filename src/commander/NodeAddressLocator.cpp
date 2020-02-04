//
//  NodeAddressLocator.cpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#include "commander/NodeAddressLocator.hpp"
#include "common/Logger.hpp"

#include <regex>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>
#include <sstream>

std::vector<Node> NodeAddressLocator::getNodes() {
  //TODO: Remove mock data
   std::stringstream ss(getMockLeases());
 // std::stringstream ss(getLeases());
  std::string line;

  std::regex ip("[0-9.]{7,15}");
  std::regex mac("[:a-f0-9]{17}");
  std::regex name("HOSTNAME ([a-zA-Z0-9-_.]*)");

  std::vector<Node> nodes;
  while(std::getline(ss,line,'\n')){
    std::smatch sm;

    Node n;
    std::regex_search(line,sm,ip);
    n.ipAddr = sm[0];

    std::regex_search(line,sm,mac);
    n.macAddr = sm[0];

    std::regex_search(line,sm,name);
    n.hostname = sm[1];

    nodes.push_back(n);
		Logger::getInstance().write("New node seen at IP " + n.ipAddr);
  }

  return nodes;
}

std::string NodeAddressLocator::getMockLeases() {
  return "MAC 46:4b:cb:e2:3a:c8 IP 127.0.0.1 HOSTNAME arnold.local BEGIN 2020-01-30 20:44:31 END 2020-01-31 20:44:31 MANUFACTURER AppleInc"; //\nMAC 4a:bc:ba:86:df:51 IP 172.16.20.8 HOSTNAME raspberrypi BEGIN 2020-01-30 20:49:58 END 2020-01-31 20:49:58 MANUFACTURER -NA-\nMAC ca:75:d1:da:91:e9 IP 172.16.20.9 HOSTNAME raspberrypi BEGIN 2020-01-30 20:50:40 END 2020-01-31 20:50:40 MANUFACTURER -NA-
}

std::string NodeAddressLocator::getLeases() {

  std::array<char, 4096> buffer;
  std::string result;
  //read in active dhcp leases from the program 'dhcp-lease-list'
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen("/usr/sbin/dhcp-lease-list --parsable 2>/dev/null", "r"), pclose);
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }

  return result;
}
