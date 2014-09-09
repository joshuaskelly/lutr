/*
 *  PNGColorTable.h
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 *  @description: A class for working with PNG files as color tables.
 */

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
