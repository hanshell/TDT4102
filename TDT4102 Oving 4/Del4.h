/* 
 * File:   Del4.h
 * Author: melbster
 *
 * Created on February 18, 2013, 8:01 PM
 */
#ifndef DEL4_H
#define	DEL4_H
#include <iostream>
#include <string>
using namespace std;

class Card{
private:
    int value;
    string suit;
public:
    int getValue();
    string getSuit();
    void setValue(int i);
    void setSuit(string s);
    std::string getFace();
};
#endif	/* DEL4_H */