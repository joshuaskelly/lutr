/*
 *  ColorTableFactory.h
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 *  @description: A factory class that handles the creation of color tables.
 */

#ifndef __pal2cube__ColorTableFactory__
#define __pal2cube__ColorTableFactory__

#include <string>

#include "IColorTable.h"

class ColorTableFactory {
public:
    static IColorTablePtr GetColorTable(std::string path);
};

#endif
