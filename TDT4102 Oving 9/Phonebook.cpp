#include "Phonebook.h"
#include <iostream>
#include <set>
#include <map>

void Phonebook::add(PhonebookEntry &addMe) {
    std::set<PhonebookEntry>::const_iterator lhsit;
    std::string name = addMe.getName();
    PhonebookEntry entry(name);
    bool insert = true;

    if (entries.size() == 0)
        entries.insert(addMe);
    else {
        for (lhsit = entries.begin(); lhsit != entries.end(); ++lhsit) {
            if (name == lhsit->getName()) {
                entry.add(addMe);
                entries.erase(lhsit);
                entries.insert(entry);
                insert = false;
                break;
            }
        }
        if (insert == true)
            entries.insert(addMe);
    }
}

std::ostream &operator <<(std::ostream &str, const Phonebook &book) {
    std::set<PhonebookEntry>::const_iterator it;

    for (it = book.entries.begin(); it != book.entries.end(); it++) {
        str << *it;
        str << std::endl;
    }
}
bool Phonebook::find(std::string name, std::string label, Phonebook& ret) const {
    std::set<PhonebookEntry>::const_iterator it;
    
    std::string s;
    for (it = this->entries.begin(); it != this->entries.end(); it++) {
        PhonebookEntry entry;
        s = it->getName();
        if (s.find(name) != std::string::npos) {
            if (it->find(label, entry) == true) {
              //  it->find(label, entry);
                entry.setName(s);
                ret.add(entry);
            }
        }
    }
}