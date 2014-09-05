//
//  PALColorTable.h
//  pal2cube
//
//  Created by Joshua on 8/30/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#ifndef __pal2cube__PALColorTable__
#define __pal2cube__PALColorTable__

#include <vector>

#include "IColorTable.h"

class PALColorTable : public IColorTable {
public:
    PALColorTable();
    virtual ~PALColorTable();
    
    int Count();
    ColorPtr At(int index);
    
    bool Load(std::string filepath);
    
    std::string FileName() { return this->fileName; }
    void FileName(std::string fileName) { this->fileName = fileName; }
    
private:
    bool LoadJASC(std::string filepath);
    bool LoadMicrosoft(std::string filepath);
    
    std::vector<ColorPtr> colors;
    std::string fileName;
};

#endif