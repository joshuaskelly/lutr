/*
 *  PALColorTable.h
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 *  @description: A class for working with PAL palette files.
 *  @todo: Add support for Microsoft Palette files.
 */

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