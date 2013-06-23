#include <iostream>
using namespace std;

void printTime(int hour, int minute, int second){
    cout << hour << " hours, ";
    cout << minute << " minutes, ";
    cout << second << " seconds"<<endl;
}

void getTime(){
    int sec;
    cout << "Skriv inn antall sekunder"<<endl;
    cin>>sec;
    int hours=(sec/3600);
    int remainingSec=sec-(3600*hours);
    int minutes=(remainingSec/60);
    remainingSec-=(minutes*60);
    int seconds=remainingSec;
    
    printTime(hours, minutes, seconds);
}
