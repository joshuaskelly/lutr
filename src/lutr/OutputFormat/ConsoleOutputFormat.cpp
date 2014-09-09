/*
 *  ConsoleOutputFormat.cpp
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 */

#include <iostream>

#include "ConsoleOutputFormat.h"

ConsoleOutputFormat::ConsoleOutputFormat() {
    this->colorTable = nullptr;
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