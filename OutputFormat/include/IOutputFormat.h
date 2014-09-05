//
//  IOutputFormat.h
//  pal2cube
//
//  Created by Joshua on 8/26/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#ifndef pal2cube_IOutputFormat_h
#define pal2cube_IOutputFormat_h

#include "Color.h"
#include "IColorTable.h"

class IOutputFormat {
public:
    virtual void Begin() = 0;
    virtual void End() = 0;
    virtual void Write(Color c) = 0;
    void Write(ColorPtr c) { Write(*c); }
    
    virtual IColorTablePtr ColorTable() = 0;
    virtual void ColorTable(IColorTablePtr colorTable) = 0;
};

typedef IOutputFormat* IOutputFormatPtr;

#endif
