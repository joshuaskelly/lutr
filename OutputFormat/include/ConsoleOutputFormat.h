/*
 *  ConsoleOutputFormat.h
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 *  @description: A class for outputting lookup table information to the 
 *    console.
 */

#ifndef __pal2cube__ConsoleOutputFormat__
#define __pal2cube__ConsoleOutputFormat__

#include "IOutputFormat.h"

class ConsoleOutputFormat : public IOutputFormat {
public:
    ConsoleOutputFormat();
    virtual ~ConsoleOutputFormat();
    
    void Begin();
    void End();
    void Write(Color c);
    
    IColorTablePtr ColorTable() { return this->colorTable; }
    void ColorTable(IColorTablePtr colorTable) { this->colorTable = colorTable; }
    
private:
    IColorTablePtr colorTable;
};

#endif
