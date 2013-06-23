#include "Person.h"
#include <iostream>
#include <list>

Person::Person(std::string name, int age, int height) {
    this->name = name;
    this->age = age;
    this->height = height;
}
std::ostream& operator<<(std::ostream& out, Person& person) {
    out << person.getName() << std::endl;
    out << person.getAge() << std::endl;
    out << person.getHeight() << std::endl;
}
int Person::getAge() {
    return this->age;
}
int Person::getHeight() {
    return this->height;
}
std::string Person::getName() {
    return this->name;
}