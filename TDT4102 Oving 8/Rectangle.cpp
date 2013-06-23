#include "Rectangle.h"
#include "Line.h"

Rectangle::Rectangle(int x1, int y1, int x4, int y4, Color col) {
    this->x1 = x1;
    this->y1 = y1;
    this->x4 = x4;
    this->y4 = y4;
    setColor(col);
}

void Rectangle::Draw(Image& img) {
    Line line1(x1, y1, x4, y1, getColor());
    Line line2(x1, y1, x1, y4, getColor());
    Line line3(x1, y4, x4, y4, getColor());
    Line line4(x4, y1, x4, y4, getColor());
    
    line1.Draw(img);
    line2.Draw(img);
    line3.Draw(img);
    line4.Draw(img);    
}