//
//  PALColorTable.cpp
//  pal2cube
//
//  Created by Joshua on 8/30/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "PALColorTable.h"
#include "Utility.h"

PALColorTable::PALColorTable() {
    
}

PALColorTable::~PALColorTable() {
    
}

int PALColorTable::Count() {
    return static_cast<int>(this->colors.size());
}

ColorPtr PALColorTable::At(int index) {
    return this->colors.at(index);
}

bool PALColorTable::Load(std::string filepath) {
    std::ifstream file(filepath);
    
    std::string line;
    std::getline(file, line);
    file.close();
    
    line = trim(line);

    if (line == "JASC-PAL") {
        return LoadJASC(filepath);
    }
    
    return false;
}

bool PALColorTable::LoadJASC(std::string filepath) {
    std::string line;
    
    std::ifstream file(filepath);
    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);
    
    size_t colorCount = atoi(line.substr(0, line.length() - 1).c_str());
    
    for (int i = 0; i < colorCount; i++) {
        std::getline(file, line);
        line = trim(line);
        
        std::vector<std::string> triple = split(line, " ");
        
        if (triple.size() == 3) {
            ColorPtr c = new Color(atoi(triple[0].c_str()),
                                   atoi(triple[1].c_str()),
                                   atoi(triple[2].c_str()));
            
            this->colors.push_back(c);
        }
        
    }
    
    file.close();
    
    return true;
}

bool PALColorTable::LoadMicrosoft(std::string filepath) {
    return true;
}