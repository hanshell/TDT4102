/* 
 * File:   Line.h
 * Author: melbster
 *
 * Created on April 9, 2013, 10:24 AM
 */

#ifndef LINE_H
#define	LINE_H

#include "Shape.h"


class Line: public Shape{
    private:
        unsigned int sX, sY, eX, eY;
        
    public:
        Line(unsigned int sX, unsigned int sY, unsigned int eX, unsigned int eY, Color col);
        void Draw(Image& img);
        void drawHorizontalGradient(Image& img);
        void drawVerticalGradient(Image& img);
};

#endif	/* LINE_H */

