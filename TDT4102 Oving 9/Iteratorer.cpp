#include <iostream>
#include <vector>
#include "Iteratorer.h"

using namespace std;

void stringVector() {
    vector<string> vect;
    vect.push_back("Lorem");
    vect.push_back("Ipsum");
    vect.push_back("Dolor");
    vect.push_back("Sit");
    vect.push_back("Amet");
    vect.push_back("Consectetur");

    vector<string>::iterator it;
    for (it = vect.begin(); it != vect.end(); it++) {
        cout << *it << endl;
    }
}

void reverseIterator() {
    vector<string> vect;
    vect.push_back("Lorem");
    vect.push_back("Ipsum");
    vect.push_back("Dolor");
    vect.push_back("Sit");
    vect.push_back("Amet");
    vect.push_back("Consectetur");

    vector<string>::reverse_iterator r;
    for (r = vect.rbegin(); r != vect.rend(); r++) {
        cout << *r << endl;
    }
}
void replace(vector<string>& vect, string old, string replacement){
    vector<string>::iterator it;
    bool exists=false;
    for(it=vect.begin(); it!=vect.end(); it++){
        if(*it==old){
            it=vect.erase(it);
            it=vect.insert(it, replacement);
            exists=true;
        }
    }
    if(exists)
        cout<<old<<": Value exists"<<endl<<endl;
    else
        cout<<old<<": No such value exists"<<endl<<endl;
    for(it=vect.begin(); it!=vect.end(); it++){
        cout<<*it<<endl;
    }
}