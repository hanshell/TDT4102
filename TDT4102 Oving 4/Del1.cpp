#include <iostream>
#include <cassert>
#include <string>
#include "Del3.h"
#include <ctime>
#include <stdlib.h>
#include "Del4.h"
#include "Del5.h"

using namespace std;
//
//int totalBeardLength();
//struct Musician;
//struct Band;
//bool isAlive();

const int BAND_SIZE=4;

enum Beatle{JOHN, PAUL, GEORGE, RINGO};

struct Musician{
    string name;
    int weight;
    int height;
    int beardLength;
};
struct Band{
    string name;
    bool rockBand;
    int releases;
    Musician musicians[BAND_SIZE];
};
bool isAlive(Beatle b){
    switch(b){
        case JOHN:
            return false;
        case PAUL:
            return true;
        case GEORGE:
            return false;
        case RINGO:
            return true;
        default:
            return false;
    }
}
int totalBeardLength(Band band){
    int lengthOfBeard=0;
    if(band.rockBand==true){
        for(int i=0; i<BAND_SIZE;i++){
            lengthOfBeard+=band.musicians[i].beardLength;
        }
        return lengthOfBeard;
    }
    return -1;
}
void runStuff(){
    Musician hans;
    hans.name="Hans";
    hans.weight=74;
    hans.height=175;
    hans.beardLength=3;
    Musician eivind;
    eivind.name="Eivind";
    eivind.weight=74;
    eivind.height=175;
    eivind.beardLength=2;
    Musician magnus;
    magnus.name="Hans";
    magnus.weight=74;
    magnus.height=175;
    magnus.beardLength=5;
    Musician tormod;
    tormod.name="Hans";
    tormod.weight=74;
    tormod.height=175;
    tormod.beardLength=4;
    Band band;
    band.name="The waffles";
    band.releases=11;
    band.rockBand=true;
    
    band.musicians[0]=hans;
    band.musicians[1]=eivind;
    band.musicians[2]=magnus;
    band.musicians[3]=tormod;
    
    cout << totalBeardLength(band)<<endl;
}

int main(){
    srand(time(0));    
    CardDeck cd;
}