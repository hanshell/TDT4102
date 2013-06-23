#include <assert.h>
#include <math.h>
#include <ctype.h>

#include "Oving2.h"

bool sameCase(char a, char b){
    return (isupper(a)==isupper(b)) && (isalpha(a)&&isalpha(b));
}
int numberOfDigits(int n){
    if(n==0)
        return 1;
    int i=0;
    while(n>1){
        n=n/10;
        i++;
    }
    return i+1;
}
float avg(float n1, float n2){
    return (n1+n2)/2.0;
}
void testFunction(){
    assert(sameCase('a', 'b'));
    assert(!(sameCase('a', 'B')));
    assert(sameCase('A','B'));
    assert(numberOfDigits(123)==3);
    assert(numberOfDigits(123456)==6);
    assert(!(numberOfDigits(123)==5));
    assert(fabs(avg(30, 40)-((30+40)/2)<0.0000001));
}