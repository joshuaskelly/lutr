/*
 *  PALColorTable.cpp
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "PALColorTable.h"
#include "Utility.h"

PALColorTable::PALColorTable() {
    
}

PALColorTable::~PALColorTable() {
    
}

int PALColorTable::Count() {
    return static_cast<int>(this->colors.size());
}

ColorPtr PALColorTable::At(int index) {
    return this->colors.at(index);
}

/*
 *  Load
 *  @description: Loads a .PAL file. There are two types of PAL file. One is the
 *    JASC palette format, the other is a Microsoft RIFF format.
 *  @param filepath: The path to a .PAL file.
 *  @returns: True if able to load the color data.
 */
bool PALColorTable::Load(std::string filepath) {
    std::ifstream file(filepath);
    
    std::string line;
    std::getline(file, line);
    file.close();
    
    line = trim(line);

    // Determine which type of .PAL file we are working with.
    if (line == "JASC-PAL") {
        return LoadJASC(filepath);
    }
    else {
        return LoadMicrosoft(filepath);
    }
    
    return false;
}

/*
 *  LoadJASC
 *  @description: Loads the color data for a JASC format palette file.
 *  @param filepath: The filepath to the JASC format PAL file.
 *  @returns: Whether the loading of color data was successful.
 */
bool PALColorTable::LoadJASC(std::string filepath) {
    std::string line;
    
    std::ifstream file(filepath);
    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);
    
    // The color count is always the fourth line.
    size_t colorCount = atoi(line.substr(0, line.length() - 1).c_str());
    
    // Load the color data.
    for (int i = 0; i < colorCount; i++) {
        std::getline(file, line);
        line = trim(line);
        
        std::vector<std::string> triple = split(line, " ");
        
        if (triple.size() == 3) {
            ColorPtr c = new Color(atoi(triple[0].c_str()),
                                   atoi(triple[1].c_str()),
                                   atoi(triple[2].c_str()));
            
            this->colors.push_back(c);
        }
        
    }
    
    file.close();
    
    return true;
}

/*
 *  LoadMicrosoft
 *  @description: Loads the color data for a Microsoft RIFF format palette file.
 *  @param filepath: The filepath to the file.
 *  @returns: True if able to load the color data.
 *  @todo: Support this file format
 */
bool PALColorTable::LoadMicrosoft(std::string filepath) {
    std::cout << "Microsoft Palette format is currently not supported." << std::endl;
    return false;
}