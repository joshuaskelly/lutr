//
//  ColorTableFactory.h
//  pal2cube
//
//  Created by Joshua on 8/27/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#ifndef __pal2cube__ColorTableFactory__
#define __pal2cube__ColorTableFactory__

#include <string>

#include "IColorTable.h"

class ColorTableFactory {
public:
    static IColorTablePtr GetColorTable(std::string path);
};

#endif
