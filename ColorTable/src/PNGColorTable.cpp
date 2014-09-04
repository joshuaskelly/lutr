//
//  PNGColorTable.cpp
//  lutr
//
//  Created by Joshua on 9/4/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#include <set>
#include <iostream>

#include "Color.h"
#include "lodepng.h"
#include "PNGColorTable.h"

PNGColorTable::PNGColorTable() {
    
}

PNGColorTable::~PNGColorTable() {
    
}

int PNGColorTable::Count() {
    return static_cast<int>(this->colors.size());
}

ColorPtr PNGColorTable::At(int index) {
    return this->colors.at(index);
}

bool PNGColorTable::Load(std::string filepath) {
    std::vector<Color> colorSet;
    
    std::vector<unsigned char> image;
    unsigned width;
    unsigned height;
    
    lodepng::decode(image, width, height, filepath);
    
    for (std::vector<unsigned char>::iterator it = image.begin(); it != image.end();) {
        unsigned char r = *it; it++;
        unsigned char g = *it; it++;
        unsigned char b = *it; it++;
        it++;
        
        ColorPtr c = new Color(r, g, b);
        
        if (std::find(colorSet.begin(), colorSet.end(), *c) == colorSet.end()) {
            colorSet.push_back(*c);
            this->colors.push_back(c);
        }
    }
    
    return true;
}
