/* 
 * File:   main.cpp
 * Author: melbster
 *
 * Created on February 11, 2013, 12:38 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
void printArray(int numbers[], int size);
void printArray(int records[][7], int size);
int randomDayEntry();
int randomPhoneEntry();
void randomizeList(int records[][7], int numOfCalls, int incrementValue);
int countCalls(int records[][7], int day);
/*
 * 
 */
int main() {
    
    srand(time(NULL));
    const int max_value=6;
    int phoneNumbers[max_value]={43534156,324245345,12312,654645,213132,5345};

    
    string days[7]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    int record[max_value][7]={{1,1,1,1,1,1,1},
                              {1,1,1,1,1,1,1},
                              {1,1,1,1,1,1,1},
                              {1,1,1,1,1,1,1},
                              {1,1,1,1,1,1,1},
                              {1,1,1,1,1,2,2}};
    
    cout << countCalls(record, 5);

    printArray(record, max_value);
    randomizeList(record, 10, 3);
    printArray(record, max_value);
    cout<<endl<<endl;
    randomizeList(record, 5);
    printArray(record, max_value);
}
void printArray(int numbers[], int size){
    for(int i=0; i<size; i++){
        cout << i+1<<": "<<numbers[i]<<"   "<<endl;
    }
}
void printArray(int records[][7], int size){
    for (int i = 0; i < size; i++) {
        for(int j=0; j<7; j++){
            cout<<"\t"<<records[i][j];
        }
        cout<<endl;
    }
}
void randomizeList(int records[][7], int numOfCalls, int incrementValue){
    for(int i=0; i<numOfCalls; i++){
        records[randomPhoneEntry()][randomDayEntry()]+=incrementValue;
        cout << randomPhoneEntry() << "   "<<randomDayEntry()<<endl<<endl;
    }
}
int countCalls(int records[][7], int day){
    int counter=0;
    for (int i = 0; i < 7; i++) {
        counter+=records[day][i];
    }
    return counter;
}
int randomDayEntry(){
    return (rand() % 7);
}
int randomPhoneEntry(){
    return (rand()%6);
}