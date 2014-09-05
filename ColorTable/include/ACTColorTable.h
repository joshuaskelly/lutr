//
//  ACTColorTable.h
//  pal2cube
//
//  Created by Joshua on 8/27/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#ifndef __pal2cube__ACTColorTable__
#define __pal2cube__ACTColorTable__

#include <vector>

#include "IColorTable.h"

class ACTColorTable : public IColorTable {
public:
    ACTColorTable();
    virtual ~ACTColorTable();
    
    int Count();
    ColorPtr At(int index);
    
    bool Load(std::string filepath);
    
    std::string FileName() { return this->fileName; }
    void FileName(std::string fileName) { this->fileName = fileName; }
    
private:
    std::vector<ColorPtr> colors;
    std::string fileName;
};

#endif
