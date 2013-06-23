#include "Shape.h"

Shape::Shape(){}
Shape::Shape(Color col){
    this->col.red=col.red;
    this->col.green=col.green;
    this->col.blue=col.blue;
}
Color Shape::getColor(){
    return col;
}
void Shape::setColor(Color col){
    this->col=col;
}