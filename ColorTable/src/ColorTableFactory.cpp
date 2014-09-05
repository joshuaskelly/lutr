//
//  ColorTableFactory.cpp
//  pal2cube
//
//  Created by Joshua on 8/27/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#include <iostream>

#include "ColorTableFactory.h"
#include "ACTColorTable.h"
#include "PALColorTable.h"
#include "PNGColorTable.h"
#include "Utility.h"

IColorTablePtr ColorTableFactory::GetColorTable(std::string path) {
    std::string fileExtension = "";
    std::string fileName = "";
    
    for (std::string::reverse_iterator rit = path.rbegin(); rit != path.rend(); rit++) {
        char current = *rit;
        
        if (current == '.' && fileExtension == "") {
            fileExtension = fileName;
        }
        if (current == '/' || current == '\\') {
            break;
        }
        
        fileName = current + fileName;
    }
    
    IColorTablePtr colorTable = nullptr;
    
    if (fileExtension == "act" || fileExtension == "ACT") {
        colorTable = new ACTColorTable();
        
        if (!colorTable->Load(path)) {
            return nullptr;
        }
    }
    else if (fileExtension == "pal" || fileExtension == "PAL") {
        colorTable = new PALColorTable();
        
        if (!colorTable->Load(path)) {
            return nullptr;
        }
    }
    else if (fileExtension == "png" || fileExtension == "PNG") {
        colorTable = new PNGColorTable();
        
        if (!colorTable->Load(path)) {
            return nullptr;
        }
    }
    else {
        std::cout << "Unsupported file format: " << fileExtension << std::endl;
        return nullptr;
    }
    
    colorTable->FileName(fileName);
    
    return colorTable;
}