/* 
 * File:   main.cpp
 * Author: melbster
 *
 * Created on February 4, 2013, 2:33 PM
 */

#include <cstdlib>
#include <iostream>
#include "Oving2.h"
using namespace std;

/*
 * 
 */
int main() {
    int a,b;
    a=5;
    b=5;
    byValue(a);
    byReference(b);
    
    cout<<a<<endl;
    cout<<b<<endl;
    
}