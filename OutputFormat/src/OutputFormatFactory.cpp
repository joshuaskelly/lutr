//
//  OutputFormatFactory.cpp
//  pal2cube
//
//  Created by Joshua on 8/27/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#include <string>

#include "OutputFormatFactory.h"
#include "ConsoleOutputFormat.h"
#include "CubeOutputFormat.h"

const std::string OutputFormatFactory::CommandLineFlag = "--output";

IOutputFormatPtr OutputFormatFactory::GetOutputFormat(std::string format) {
    if (format.length() < OutputFormatFactory::CommandLineFlag.length() + 1) {
        // Show usage
        return nullptr;
    }
    if (format.substr(0,OutputFormatFactory::CommandLineFlag.length() + 1) != OutputFormatFactory::CommandLineFlag + "=") {
        // Show usage
        return nullptr;
    }
    
    std::string desiredFormat = format.substr(OutputFormatFactory::CommandLineFlag.length() + 1, format.length() -1);
    
    if (desiredFormat == "console") {
        ConsoleOutputFormat* f = new ConsoleOutputFormat();
        
        return f;
    }
    else if (desiredFormat == "cube" || desiredFormat == "default") {
        CubeOutputFormat* f = new CubeOutputFormat();
        
        return f;
    }
    else {
        // Show usage
        return nullptr;
    }
}