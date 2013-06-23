/* 
 * File:   main.cpp
 * Author: melbster
 *
 * Created on February 25, 2013, 9:18 PM
 */

#include <cstdlib>
#include "Matrix2x2.h"
#include <iostream>
using namespace std;
#include "Matrix2x2.h"
#include "Vector2.h"
/*
 * 
 */
void input(){
    int a,b,c,d,p,q;
    
    cout<<"Skriv inn a, b, c, d, p, og q"<<endl;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>p;
    cin>>q;

    Matrix2x2 matrix(a,b,c,d); 
    Vector2 vector(p,q);
    
    Matrix2x2 inv=matrix.inverse();
    Vector2 solution=inv*vector;
    cout<<"X1 og X2:  "<<endl<<solution;
    
}

int main() {
    input();
    
    Matrix2x2 B(8,6,5,4);
    Matrix2x2 C(9,7,11,10);
    Matrix2x2 E=B.inverse();
    Vector2 vector(2,-1);
//    Vector2 vector1=B*vector;
//    
//    B-=C;
//    cout <<B;
    
    
//    vector = A*vector;
//    cout<<vector;
//    Vector2 vector1(5,9);
//    Vector2 vector2(9,5);
//    Vector2 vector;
//    cout<< vector2.dot(vector1);
}