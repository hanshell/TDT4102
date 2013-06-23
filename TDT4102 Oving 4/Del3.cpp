#include <iostream>
#include <string>
using namespace std;

string nameFixer(string name){
    unsigned int nameSpace=name.find(' ');
    return name.substr(nameSpace+1)+", " + name.substr(0, nameSpace);
}
