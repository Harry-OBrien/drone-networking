//
//  NodeAddressLocator.hpp
//  SwarmCommander
//
//  Created by Harry O'Brien on 30/01/2020.
//  Copyright © 2020 Harry O'Brien. All rights reserved.
//

#ifndef NODE_ADDRESS_LOCATOR_HPP
#define NODE_ADDRESS_LOCATOR_HPP

#include "Node.hpp"
#include <string>
#include <vector>

// TODO: Locator will upate when new IP is assigned
// TODO: Locator will alert nodeHandler of new IP

class NodeAddressLocator {

public:
	std::vector<Node> getNodes();

private:
	std::string getMockLeases();
	std::string getLeases();
};

#endif /* defined NODE_ADDRESS_LOCATOR_HPP */
