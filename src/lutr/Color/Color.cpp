/*
 *  Color.cpp
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 */

#include "Color.h"

Color::Color(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Color::Color(float r, float g, float b) {
    this->r = static_cast<int>(r * 255);
    this->g = static_cast<int>(g * 255);
    this->b = static_cast<int>(b * 255);
}

Color::~Color() {
    
}

bool operator== (const Color& lhs, const Color& rhs) {
    return lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b;
}
