#include <iostream>
using namespace std;
void hangman(vector<string>& wordvector){
    ifstream infile;
    ofstream outfile;
    infile.open("//home//melbster//Desktop//C++Files//hangman.txt");
    string line, word;

    int numberOfLines=0;
    while (infile.good()) {
        while (infile >> word) {
            for(int i=0; i<word.size(); i++){
                word[i]=tolower(word[i]);
                if(!isalpha(word[i]))
                    word.erase(word.begin()+i);
            }
            wordvector.push_back(word);
        }
    }
    infile.close();
}
