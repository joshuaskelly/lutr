//
//  ConsoleOutputFormat.h
//  pal2cube
//
//  Created by Joshua on 9/2/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

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
};

#endif
