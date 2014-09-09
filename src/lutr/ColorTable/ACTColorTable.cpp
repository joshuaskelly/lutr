/*
 *  ACTColorTable.cpp
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 */

#include <iostream>
#include <fstream>

#include "ACTColorTable.h"

ACTColorTable::ACTColorTable() {

}

ACTColorTable::~ACTColorTable() {
    
}

bool ACTColorTable::Load(std::string filepath) {
    // Determine file size.
    std::ifstream file(filepath);
    file.seekg(0, file.end);
    size_t len = file.tellg();
    
    // ACT palettes should always be length 772.
    if (len != 772) {
        return false;
    }
    
    // Read all the data into a buffer.
    char* buf = new char[len];
    file.seekg(0, file.beg);
    file.read(buf, len);
    
    file.close();
    
    // Bytes 768 and 769 represent the color count. Traditionally this will
    // be either 16 or 256.
    int colorCount = ((unsigned char)buf[768] << 8) + (unsigned char)buf[769];
    
    // Load the color data.
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
