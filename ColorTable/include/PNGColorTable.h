//
//  PNGColorTable.h
//  lutr
//
//  Created by Joshua on 9/4/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#ifndef __lutr__PNGColorTable__
#define __lutr__PNGColorTable__

#include <vector>

#include "IColorTable.h"

class PNGColorTable : public IColorTable {
public:
    PNGColorTable();
    virtual ~PNGColorTable();
    
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
