//
//  ColorUtility.cpp
//  pal2cube
//
//  Created by Joshua on 8/28/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#include "ColorUtility.h"

const int ColorUtility::Distance(Color& lhs, Color& rhs) {
    int dr = lhs.R() - rhs.R();
    int dg = lhs.G() - rhs.G();
    int db = lhs.B() - rhs.B();
    
    return (dr * dr) + (dg * dg) + (db * db);
}
