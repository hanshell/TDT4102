#include "Circle.h"
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
Circle::Circle(int x0, int y0, int radius, Color col) {
    this->radius = radius;
    this->x0 = x0;
    this->y0 = y0;
    setColor(col);
}
void Circle::Draw(Image& img) {
    int x;
    int y;

    for (int i = x0 - radius; i < radius + x0; i++) {
        y = y0 + sqrt(double(-pow(i - x0, 2) + pow(radius, 2)));
        x = x0 + sqrt(double(-pow(y - y0, 2) + pow(radius, 2)));
        int diff = y - y0;

        img.SetColor(i, y, getColor());
        img.SetColor(i, y0 - diff, getColor());
        
    }
    for (int i = y0 - radius; i < radius + y0; i++) {
        x = x0 + sqrt(double(-pow(i - y0, 2) + pow(radius, 2)));
        
        int diff=x-x0;
        img.SetColor(x, i, getColor());
        img.SetColor(x0-diff, i, getColor());
        
        std::cout<<"y: "<<i<<"   "<<"x:  "<<x<<std::endl;
    }
}
int Circle::getRadius() {
    return radius;
}
Circle Circle::operator+(Circle circle){
    
}