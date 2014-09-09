/*
 *  Converter.cpp
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 */

#include <iostream>

#include "Converter.h"
#include "ColorUtility.h"

Converter::Converter(IColorTablePtr& colorTable, IOutputFormatPtr outputFormat) {
    this->colorTable = colorTable;
    this->outputFormat = outputFormat;
    
    this->outputFormat->ColorTable(this->colorTable);
}

Converter::~Converter() {
    delete this->colorTable;
    this->colorTable = nullptr;
    
    delete this->outputFormat;
    this->outputFormat = nullptr;
}

/*
 *  Convert
 *  @description: Produces a color lookup table from the given color table
 */
void Converter::Convert() {
    int lutSize = 8;
    int level = lutSize - 1;
    
    this->outputFormat->Begin();
    
    // Map a nearest neighbor function over an identity lookup table.
    for (int b = 0; b <= level; b++) {
        for (int g = 0; g <= level; g++) {
            for (int r = 0; r <= level; r++) {
                int distance = 99999;
                int minDistance = 99999;
                int minIndex = -1;
                
                float rf = r / (float)level;
                float gf = g / (float)level;
                float bf = b / (float)level;
                
                Color color(rf, gf, bf);
                ColorPtr palColor;
                
                // Nearest neighbor match.
                for (int i = 0; i < this->colorTable->Count(); i++) {
                    palColor = this->colorTable->At(i);
                    distance = ColorUtility::Distance(color, *palColor);
                    
                    if (distance < minDistance) {
                        minDistance = distance;
                        minIndex = i;
                    }
                }
                this->outputFormat->Write(this->colorTable->At(minIndex));
            }
        }
    }
    
    this->outputFormat->End();
}