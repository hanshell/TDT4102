/* 
 * File:   Matrix2x2.h
 * Author: melbster
 *
 * Created on February 25, 2013, 9:21 PM
 */

#ifndef MATRIX2X2_H
#define	MATRIX2X2_H
#include <iostream>
#include "Vector2.h"
class Matrix2x2 {
private:
    double matrix[2][2];
public:
    Matrix2x2();
    Matrix2x2(double matrix1[2][2]);
    Matrix2x2(double pos1, double pos2, double pos3, double pos4);
    double getMatrixElement(int posY, int posX)const;
    void setMatrixElement(int posY, int posX, double value);
    Matrix2x2 operator+(Matrix2x2&);
    Matrix2x2 operator-(Matrix2x2&);
    Matrix2x2& operator+=(Matrix2x2&);
    Matrix2x2 operator-=(Matrix2x2&);
    Matrix2x2 operator*(Matrix2x2&);
    Vector2 operator*(Vector2&);
    Matrix2x2 operator*=(Matrix2x2&);
    
    Matrix2x2 inverse() const;
    friend std::ostream& operator<<(std::ostream&, Matrix2x2&);
    double det() const;
    void print();
};

#endif	/* MATRIX2X2_H */

