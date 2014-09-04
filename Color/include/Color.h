//
//  Color.h
//  pal2cube
//
//  Created by Joshua on 8/28/14.
//  Copyright (c) 2014 Joshua Skelton. All rights reserved.
//

#ifndef __pal2cube__Color__
#define __pal2cube__Color__

#include <string>

class Color {
public:
    Color(int r, int g, int b);
    Color(float r, float g, float b);
    virtual ~Color();
    
    const int R() { return this->r; }
    const int G() { return this->g; }
    const int B() { return this->b; }
    
    float Rf() { return this->r / 255.0f; }
    float Gf() { return this->g / 255.0f; }
    float Bf() { return this->b / 255.0f; }
    
    friend bool operator== (const Color& lhs, const Color& rhs);
    
private:
    int r;
    int g;
    int b;
};

typedef Color* ColorPtr;

#endif
