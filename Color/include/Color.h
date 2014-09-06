/*
 *  Color.h
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 *  @description: A simple class representing color as an RGB triple.
 */

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
    
    const float Rf() { return this->r / 255.0f; }
    const float Gf() { return this->g / 255.0f; }
    const float Bf() { return this->b / 255.0f; }
    
    friend bool operator== (const Color& lhs, const Color& rhs);
    
private:
    int r;
    int g;
    int b;
};

typedef Color* ColorPtr;

#endif
