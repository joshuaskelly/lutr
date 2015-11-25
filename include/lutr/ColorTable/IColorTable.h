/*
 *  IColorTable.h
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 *  @description: The interface for color table objects.
 */

#ifndef pal2cube_IColorTable_h
#define pal2cube_IColorTable_h

#include "Color.h"

class IColorTable {
public: 
    virtual int Count() = 0;
    virtual ColorPtr At(int index) = 0;
    virtual bool Load(std::string filepath) = 0;
    virtual std::string FileName() = 0;
    virtual void FileName(std::string fileName) = 0;
    
};

using IColorTablePtr = IColorTable*;

#endif
