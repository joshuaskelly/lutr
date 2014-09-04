//
//  main.cpp
//  pal2cube
//
//  Created by Joshua on 8/26/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#include <iostream>
#include <string>

#include "Converter.h"
#include "ColorTableFactory.h"
#include "OutputFormatFactory.h"

void showUsage() {
    std::cout << "usage: pal2cube [--output-format=format] file ..." << std::endl;
}

int main(int argc, const char* argv[])
{
    std::string filepath;
    std::string formatOption = "default";
    
    if (argc == 1) {
        showUsage();
        
        return 0;
    }
    else if (argc == 2) {
        filepath = std::string(argv[1]);
    }
    else if (argc == 3) {
        formatOption = std::string(argv[1]);
        filepath = std::string(argv[2]);
    }
    else {
        showUsage();
    }
    
    IColorTablePtr colorTable = ColorTableFactory::GetColorTable(filepath);
    IOutputFormatPtr outputFormat = OutputFormatFactory::GetOutputFormat(formatOption);
    
    if (colorTable == nullptr || outputFormat == nullptr) {
        return -1;
    }
    
    Converter converter(colorTable, outputFormat);
    converter.Convert();
    
    return 0;
}
