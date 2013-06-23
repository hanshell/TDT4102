#include "Phonebook.h"
#include <iostream>
#include <vector>
#include <map>

bool operator <(const PhonebookEntry &lhs, const PhonebookEntry &rhs){
    std::string s1=lhs.getName();
    std::string s2=rhs.getName();
    
    int longest;
    if(s1.size()>s2.size())
        longest=s1.size();
    else if(s1.size()==s2.size())
        longest=s1.size();
    else 
        longest=s2.size();
    
    for(int i=0; i<longest; i++){
        if(s1.at(i)>s2.at(i))
            return false;
        else if(s1.at(i)<s2.at(i))
            return true;
        else
            continue;
    }
    return false;
}
void PhonebookEntry::add(const PhonebookEntry &copyFrom){    
    std::map<std::string, std::string>::const_iterator rhsit;
    std::map<std::string, std::string>::iterator lhsit;

    std::string s;
    for(rhsit=copyFrom.numbers.begin(); rhsit!=copyFrom.numbers.end(); rhsit++){
        s=rhsit->first;
        
        lhsit=this->numbers.find(s);
        
        if(lhsit!=this->numbers.end()){
            lhsit->second=rhsit->second;
        }
        else{
            this->numbers[s]=rhsit->second;
        }
    }
}
std::ostream &operator <<(std::ostream &str, const PhonebookEntry &entry){
    std::map<std::string, std::string>::const_iterator it;
            
    str<<entry.getName()<<std::endl;
    
    for(it=entry.numbers.begin(); it!=entry.numbers.end(); it++){
        str<<it->first<<": "<<it->second<<std::endl;
    }
}
bool PhonebookEntry::find(const std::string &label, PhonebookEntry &ret) const{
    std::map<std::string, std::string>::const_iterator it;
    bool found=false;
    for(it=this->numbers.begin(); it!=this->numbers.end(); it++){
        if(it->first.find(label)!=std::string::npos){
            ret.add(it->first, it->second);
            found=true;
        }
    }
    return found;
}