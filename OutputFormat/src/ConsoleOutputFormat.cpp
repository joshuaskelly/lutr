//
//  ConsoleOutputFormat.cpp
//  pal2cube
//
//  Created by Joshua on 9/2/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#include <iostream>

#include "ConsoleOutputFormat.h"

ConsoleOutputFormat::ConsoleOutputFormat() {
    
}

ConsoleOutputFormat::~ConsoleOutputFormat() {
    
}

void ConsoleOutputFormat::Begin() {
    std::cout << "LUT_3D_SIZE 8" << std::endl << std::endl;
}

void ConsoleOutputFormat::End() {
    std::cout << std::endl;
}

void ConsoleOutputFormat::Write(Color c) {
    std::cout << c.Rf() << " " << c.Gf() << " " << c.Bf() << std::endl;
}