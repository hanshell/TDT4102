/* 
 * File:   Circle.h
 * Author: melbster
 *
 * Created on April 10, 2013, 1:48 PM
 */

#ifndef CIRCLE_H
#define	CIRCLE_H

#include "Shape.h"


class Circle:public Shape {
private:
    int x0, y0;
    int radius;
public:
    Circle(int x0, int y0, int radius, Color col);
    int getRadius();
    void Draw(Image& img);
};



#endif	/* CIRCLE_H */

