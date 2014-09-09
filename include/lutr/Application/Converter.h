/*
 *  Converter.h
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 *  @description: A class that creates a lookup table given a color table source
 *    and a desired output format.
 */

#ifndef __pal2cube__Converter__
#define __pal2cube__Converter__

#include <vector>

#include "IColorTable.h"
#include "IOutputFormat.h"

class Converter {
public:
    Converter(IColorTablePtr& colorTable, IOutputFormatPtr outputFormatPtr);
    virtual ~Converter ();
    
    void Convert();
    
private:
    IColorTablePtr colorTable;
    IOutputFormatPtr outputFormat;
    
    std::vector<Color> lut;
};

#endif
