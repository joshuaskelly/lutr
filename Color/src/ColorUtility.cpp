/*
 *  ColorUtility.cpp
 *
 *  @author: Joshua Skelton joshua.skelton@gmail.com
 */

#include "ColorUtility.h"

/*
 * Distance
 *
 * @description: Calculates the distance between two points in three space.
 * @param lhs: A color
 * @param rhs: A color
 * @returns: The distance between two colors in squared space.
 */
const int ColorUtility::Distance(Color& lhs, Color& rhs) {
    int dr = lhs.R() - rhs.R();
    int dg = lhs.G() - rhs.G();
    int db = lhs.B() - rhs.B();
    
    return (dr * dr) + (dg * dg) + (db * db);
}
