/*
 *  ACTColorTable.h
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 *  @description: A class for working with ACT palette files.
 */

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
