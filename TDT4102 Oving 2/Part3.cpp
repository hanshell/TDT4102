#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>
using namespace std;

int randomTenToFifty(){
    srand(time(0));
    return (rand() % 41) + 10;
}
float checkTrigonometry(float nr){
    float x=tan(nr);
    float div=sin(nr)/cos(nr);
    
    return fabs(x-div);
}
char changeCase(char c){
    int charValue=c;
    
    if(charValue>='A' && charValue<='Z'){
        charValue+=32;
        return char(charValue);
    }
    else{
        charValue-=32;
        return char(charValue);
    }
}