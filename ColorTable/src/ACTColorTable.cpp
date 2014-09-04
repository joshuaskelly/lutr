//
//  ACTColorTable.cpp
//  pal2cube
//
//  Created by Joshua on 8/27/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "ACTColorTable.h"

ACTColorTable::ACTColorTable() {

}

ACTColorTable::~ACTColorTable() {
    
}

bool ACTColorTable::Load(std::string filepath) {
    std::ifstream file(filepath);
    file.seekg(0, file.end);
    size_t len = file.tellg();
    
    if (len != 772) {
        return false;
    }
    
    char* buf = new char[len];
    file.seekg(0, file.beg);
    file.read(buf, len);
    
    file.close();
    
    int colorCount = ((unsigned char)buf[768] << 8) + (unsigned char)buf[769];
    
    for (int i = 0; i < colorCount; i++) {
        
        int r = (unsigned char)buf[i];
        int g = (unsigned char)buf[i + 1];
        int b = (unsigned char)buf[i + 2];
        
        this->colors.push_back(new Color(r, g, b));
    }
    
    return true;
}

int ACTColorTable::Count() {
    return static_cast<int>(this->colors.size());
}

ColorPtr ACTColorTable::At(int index)  {
    return this->colors.at(index);
}
