//
//  Converter.h
//  pal2cube
//
//  Created by Joshua on 8/26/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

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
