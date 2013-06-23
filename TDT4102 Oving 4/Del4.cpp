#include <iostream>
#include <sstream>
#include <string>
#include "Del4.h"
#include "Del5.h"
using namespace std;

int Card::getValue() {
    return value;
}
std::string Card::getSuit() {
    return suit;
}
void Card::setValue(int i) {
    if (i >= 1 && i <= 13) {
        value = i;
    } else {
        std::cout << "Not valid card value" << std::endl;
    }
}
void Card::setSuit(std::string s) {
    if (s == "S")
        suit=s;
    else if(s=="H")
        suit=s;
    else if(s=="C")
        suit=s;
    else if(s=="D")
        suit=s;
}
std::string Card::getFace() {
    std::string face = getSuit();
    int i = getValue();
    std::stringstream sstr;
    sstr << i;
    face += sstr.str();
    return face;
}