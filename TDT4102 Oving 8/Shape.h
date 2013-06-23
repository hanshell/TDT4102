/* 
 * File:   Shape.h
 * Author: melbster
 *
 * Created on April 9, 2013, 10:12 AM
 */

#ifndef SHAPE_H
#define	SHAPE_H

#include "Image.h"


class Shape{
private:
    Color col;
public:
    Shape();
    Shape(Color col);
    virtual void Draw(Image& img)=0;
    Color getColor();
    void setColor(Color col);
};


#endif	/* SHAPE_H */

