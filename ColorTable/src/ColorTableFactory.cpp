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
    
    for (std::string::reverse_iterator rit = path.rbegin(); rit != path.rend(); rit++) {
        char current = *rit;
        
        if (current == '.') {
            break;
        }
        
        fileExtension = current + fileExtension;
    }
    
    if (fileExtension == "act" || fileExtension == "ACT") {
        ACTColorTable* colorTable = new ACTColorTable();
        
        if (colorTable->Load(path)) {
            return colorTable;
        }
        
        return nullptr;
    }
    else if (fileExtension == "pal" || fileExtension == "PAL") {
        PALColorTable* colorTable = new PALColorTable();
        
        if (colorTable->Load(path)) {
            return colorTable;
        }
        
        return nullptr;
    }
    else if (fileExtension == "png" || fileExtension == "PNG") {
        PNGColorTable* colorTable = new PNGColorTable();
        
        if (colorTable->Load(path)) {
            return colorTable;
        }
        
        return nullptr;
    }
    
    else {
        
    }
    
    return nullptr;
}