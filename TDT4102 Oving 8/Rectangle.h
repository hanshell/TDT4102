/* 
 * File:   Rectangle.h
 * Author: melbster
 *
 * Created on April 10, 2013, 10:44 AM
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H

#include "Shape.h"
#include "Image.h"

class Rectangle :public Shape {
    int x1, y1, x4, y4;
public:
    Rectangle(int x1,int y1, int x4,int y4, Color color);
    void Draw(Image& img);
};

#endif	/* RECTANGLE_H */

