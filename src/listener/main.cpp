//
//  main.cpp
//  SwarmListener
//
//  Created by Harry O'Brien on 05/01/2020.
//  Copyright © 2020 SociaDevLtd. All rights reserved.
//

#include <iostream>
#include <common/MyClass.hpp>
#include <listener/MyListenerClass.hpp>

int main(int argc, const char * argv[]) {

	MyClass mc;
	MyListenerClass mlc;

	std::cout << mc.someFunc(9) << std::endl;
	mlc.goodOne("Bruvva");
	return 0;
}
