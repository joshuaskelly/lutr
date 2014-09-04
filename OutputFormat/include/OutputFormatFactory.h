//
//  OutputFormatFactory.h
//  pal2cube
//
//  Created by Joshua on 8/27/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#ifndef __pal2cube__OutputFormatFactory__
#define __pal2cube__OutputFormatFactory__

#include <string>

#include "IOutputFormat.h"

class OutputFormatFactory {
public:
    static IOutputFormatPtr GetOutputFormat(std::string format);
    const static std::string CommandLineFlag;
};

#endif