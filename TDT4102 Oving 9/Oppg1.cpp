#include <stdlib.h>
#include <iostream>
#include <list>
#include <map>
#include "Phonebook.h"
#include "Iteratorer.h"
#include "vector"
#include "Person.h"


using namespace std;

template<typename T>

void shuffle(T array[], int size) {
    T temp;
    T value;
    int random;
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        random = rand() % size;
        value = array[i];
        temp = array[random];
        array[i] = temp;
        array[random] = value;
    }
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << ", ";
    }
}

template<typename T>
T maximum(T t1, T t2) {
    if (t1 > t2)
        return t1;
    return t2;
}

void insertOrdered(std::list<Person> &l, Person p) {
    std::list<Person>::iterator it;
    string s1, s2;
    bool keepGoing = true;
    if (l.size() == 0) {
        l.push_back(p);
        cout << "THIS WORKS" << endl;
    } else {
        int size = 1;
        int i;
        for (it = l.begin(); it != l.end(); it++) {
            cout << it->getName() << endl;
            cout << p.getName() << endl;
            s1 = it->getName();
            s2 = p.getName();

            i = 0;
            while (i < s2.size()) {
                cout << s1.at(i) << endl;
                cout << s2.at(i) << endl;
                if (s1.at(i) > s2.at(i)) {
                    l.insert(it, p);
                    keepGoing = false;
                    break;
                } else if (s1.at(i) < s2.at(i))
                    break;
                i++;
            }
            if (!keepGoing) break;

            if (size == l.size()) {
                l.push_back(p);
                break;
            }
            size++;
        }
    }
}

int main() {
    srand(time(0));
    //OPPG1
    //    std::string array[] = {"one","two","three","four","five",};
    //    shuffle(array, 5);
    //    
    //    std::cout<<maximum(5.11,2.55);
    //    
    //OPPG2
    //    stringVector();
    //    reverseIterator();
    //    std::vector<string> vect;
    //    vect.push_back("Test");
    //    vect.push_back("Test");
    //    vect.push_back("Test");
    //    vect.push_back("Test");
    //    replace(vect, "Test", "newTest");
    //OPPG3    
    //    Person person("Hans Melby", 22, 175);
    //    cout<<person;
    
        Person p3("Eivind Palm", 22, 175);
        Person p1("Hans Melby", 22, 175);
        Person p2("Magnus Skeide", 22, 175);
        Person p4("Martin Ervik", 22, 175);
        Person p5("Albert Aaberg", 22, 175);
        list<Person> plist;
    
        insertOrdered(plist, p5);
        insertOrdered(plist, p1);
        insertOrdered(plist, p3);
        insertOrdered(plist, p4);
        insertOrdered(plist, p5);
    
        list<Person>::iterator it;
        for (it = plist.begin(); it != plist.end(); it++) {
            cout << *it << endl;
        }

//    PhonebookEntry p3("Eivind Palm");
//    p3.add("Work", "123456789");
//    p3.add("Home", "987654321");
//
//    PhonebookEntry p2("Ivar Melby");
//    p2.add("Work", "11112222");
//    p2.add("Home", "22221111");
//
//    PhonebookEntry p1("Hans Melby");
//    
//    PhonebookEntry p4("Test");
//    p4.add("testnumber", "test");
//    p4.add("testnumber2", "test");
//    
//    Phonebook phonebook;
//    phonebook.add(p2);
//    phonebook.add(p3);
//    phonebook.add(p4);
//    
//    Phonebook testPhonebook;
//    PhonebookEntry testPhonebookentry;
//    
//    
//    phonebook.find("", "test", testPhonebook);
//    
//    cout<<testPhonebook;
    
    
    
    //PART 4
    
    
}