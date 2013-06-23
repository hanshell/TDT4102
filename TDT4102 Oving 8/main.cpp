/*
 * File:   main.cpp
 * Author: melbster
 *
 * Created on March 23, 2013, 6:13 PM
 */

#include <cstdlib>
#include <iostream>
#include "Image.h"
#include "Line.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Canvas.h"

using namespace std;

/*
 Oppg1
 * a) 512*512
 * b) Svart
 * c) #FF0000
 * d) For å kunne representere et større spekter av farger. 
 *    Fordi lengde/høyde ikke kan være negativ.
 */

int main() {
    Image img(512, 512);

    Color c(100, 213, 123);
    Color c2(255, 255, 255);

    img.Fill(c2);

    //    Rectangle rectangle(0, 0, 300, 300, c);
    Line* line = new Line(100, 170, 400, 170, c);
    Circle* circle1 = new Circle(262, 262, 250, c);
    Circle* circle2 = new Circle(135, 360, 30, c);
    Circle* circle3 = new Circle(375, 360, 30, c);
    Circle* circle4 = new Circle(135, 360, 8, c);
    Circle* circle5 = new Circle(375, 360, 8, c);
    Rectangle* rectangle = new Rectangle(240, 240, 280, 280, c);

    Canvas face;
    face.AddShape(circle1);
    face.AddShape(circle2);
    face.AddShape(circle3);
    face.AddShape(circle4);
    face.AddShape(circle5);
    face.AddShape(line);
    face.AddShape(rectangle);
    face.RasterizeTo(img);

    delete circle1;
    delete circle2;
    delete circle3;
    delete circle4;
    delete circle5;
    delete line;
    delete rectangle;
    //    circle.Draw(img);

    SaveImage(img, "//home//melbster//Desktop//color.bmp");
}