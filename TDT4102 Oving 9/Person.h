/* 
 * File:   Person.h
 * Author: melbster
 *
 * Created on April 16, 2013, 11:30 AM
 */
#pragma once

#ifndef PERSON_H
#define	PERSON_H
#include <iostream>
#include <list>

class Person{
private:
    std::string name;
    int age;
    int height;
public:
    Person(std::string name, int age, int height);
    friend std::ostream& operator<<(std::ostream& out, Person& person);
    std::string getName();
    int getAge();
    int getHeight();
};


#endif	/* PERSON_H */

