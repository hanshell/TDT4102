#include "Line.h"
#include "Image.h"
#include <iostream>

Line::Line(unsigned int sX, unsigned int sY, unsigned int eX, unsigned int eY, Color col) {
    this->sX = sX;
    this->sY = sY;
    this->eX = eX;
    this->eY = eY;
    setColor(col);
}

void Line::Draw(Image& img) {
    double quotient = double(eY - sY) / double(eX - sX);
    if(quotient<=1)
        drawHorizontalGradient(img);
    else{
        drawVerticalGradient(img);
    }
}

void Line::drawHorizontalGradient(Image& img) {
    int y;
    for (int x = sX; x < eX; x++) {
        double quotient = double(eY - sY) / double(eX - sX);
        y = (quotient)*((x - sX)) + sY;

        img.SetColor(x, y, this->getColor());
    }
}

void Line::drawVerticalGradient(Image& img) {
    int x;
    for (int y = sY; y < eY; y++) {
        double quotient = double(eX - sX) / double(eY - sY);
        x = (quotient)*((y - sY)) + sX;

        img.SetColor(x, y, this->getColor());
    }
}