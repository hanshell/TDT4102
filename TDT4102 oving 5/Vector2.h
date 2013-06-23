/* 
 * File:   Vector2.h
 * Author: melbster
 *
 * Created on February 27, 2013, 1:36 PM
 */
#include <vector>
#ifndef VECTOR2_H
#define	VECTOR2_H
class Vector2{
private:
    double mathVector[2];
public:
    Vector2();
    Vector2(double, double);
    double getVectorElement(int) const;
    void setVectorELement(int,double);
    
    double dot(const Vector2 &rightHandSide) const;
    double lengthSquared() const;
    double length() const;
//    Vector2 operator*(Matrix2x2&);
    friend std::ostream& operator<<(std::ostream&, Vector2&);
};


#endif	/* VECTOR2_H */

