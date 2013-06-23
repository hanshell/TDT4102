#include <iostream>
#include <cmath>
#include "Vector2.h"
#include "Matrix2x2.h"

Vector2::Vector2(){}
Vector2::Vector2(double value1, double value2){
    this->setVectorELement(0,value1);
    this->setVectorELement(1,value2);
}
double Vector2::getVectorElement(int pos) const{
    return mathVector[pos];
}
void Vector2::setVectorELement(int pos, double value){
    mathVector[pos]=value;
}
double Vector2::dot(const Vector2& rightHandSide) const{
    double product=0;
    for(int i=0; i<2; i++){
        product+=(this->getVectorElement(i)*rightHandSide.getVectorElement(i));
    }
    return product;
}
double Vector2::lengthSquared() const{
    double value=pow(this->getVectorElement(0),2)+pow(this->getVectorElement(1),2);
    return value;
}
//Vector2::operator*(Matrix2x2& matrix1) {
//    double value;
//    for (int i = 0; i < 2; i++) {
//        value=matrix1.getMatrixElement(i,0)*getVectorElement(i)
//        setVectorELement(i, matrix1.getMatrixElement(i,0,))
//    }
//    return vector;
//
//}
double Vector2::length() const{
    return sqrt(this->lengthSquared());
}
std::ostream& operator<<(std::ostream& out, Vector2& vect){
    for(int i=0; i<2; i++){
        out << vect.getVectorElement(i)<<std::endl;
    }
}