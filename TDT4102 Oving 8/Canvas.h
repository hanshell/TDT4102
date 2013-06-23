/* 
 * File:   Canvas.h
 * Author: melbster
 *
 * Created on April 10, 2013, 10:50 PM
 */

#ifndef CANVAS_H
#define	CANVAS_H
#include "Shape.h"
#include "Image.h"
#include <vector>
using namespace std;

class Canvas {
private:
    std::vector<Shape*> vect;
public:
    void AddShape(Shape* shape);
    void RasterizeTo(Image& img);
};
#endif	/* CANVAS_H */