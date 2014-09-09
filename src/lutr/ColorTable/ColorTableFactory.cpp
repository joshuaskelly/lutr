/*
 *  ColorTableFactory.cpp
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 */

#include <iostream>

#include "ColorTableFactory.h"
#include "ACTColorTable.h"
#include "PALColorTable.h"
#include "PNGColorTable.h"
#include "Utility.h"

/*
 *  GetColorTable
 *  @description: Constructs a color table from the give filepath.
 *  @param path: A filepath to a file that can be used as a color table.
 *  @returns: A pointer to the newly constructed color table.
 */
IColorTablePtr ColorTableFactory::GetColorTable(std::string path) {
    std::string fileExtension = "";
    std::string fileName = "";
    
    // Figure out the filename and extension.
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