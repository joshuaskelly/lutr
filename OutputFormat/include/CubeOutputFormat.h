//
//  CubeOutputFormat.h
//  lutr
//
//  Created by Joshua on 9/4/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#ifndef __lutr__CubeOutputFormat__
#define __lutr__CubeOutputFormat__

#include <iostream>
#include <fstream>

#include "IOutputFormat.h"

class CubeOutputFormat : public IOutputFormat {
public:
    CubeOutputFormat();
    virtual ~CubeOutputFormat();
    
    void Begin();
    void End();
    void Write(Color c);
    
private:
    std::ofstream file;
};

#endif
