#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Hangman2.h"
using namespace std;

struct word {
    string name;
    int occurences;
};

int countWords() {
    ifstream infile;
    infile.open("//home//melbster//Desktop//C++Files//inputfile.txt");
    string line;
    int words = 0;
    while (infile.good()) {
        getline(infile, line);
        for (int i = 0; i < line.size(); i++) {
            if (isspace(line[i]))
                words++;
        }
        words++;
    }
    words--;
    infile.close();
    return words;
}

void uniqueWords() {
    vector<string> wordvector;
    vector<int> occurrence;

    ifstream infile;
    ofstream outfile;
    infile.open("//home//melbster//Desktop//C++Files//inputfile.txt");
    string line, word;

    int size = countWords();
    int numberOfLines=0;
    while (infile.good()) {
        while (infile >> word) {
            for(int i=0; i<word.size(); i++){
                word[i]=tolower(word[i]);
                if(!isalpha(word[i]))
                    word.erase(word.begin()+i);
            }
            wordvector.push_back(word);
            occurrence.push_back(1);
        }
    }
    infile.close();
    string lines;
    infile.open("//home//melbster//Desktop//C++Files//inputfile.txt");
    while(infile.good()){
        getline(infile, lines);
        numberOfLines++;
    }
    numberOfLines--;
    
    string longest=wordvector[0];
    int j;
    for (int i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (wordvector[i] == wordvector[j]) {
                wordvector.erase(wordvector.begin() + j);
                
                occurrence[i]++;
                occurrence.erase(occurrence.begin()+j);
                
                size -= 1;
                j--;
            }
        }
        if(wordvector[i].size()>longest.size())
            longest=wordvector[i];
    }
    cout<<"Text stats: "<<endl<<endl;
    cout<<"Longest word: "<<longest<<endl;
    cout<<"Number of words: "<< countWords()<<endl;
    cout<<"Number of lines: "<<numberOfLines<<endl<<endl;

    for (int i = 0; i < wordvector.size(); i++) {
        cout << wordvector[i] << "\t\t";
        cout << occurrence[i]<<endl;
    }
    infile.close();
}
int main() {
    srand(time(0));
    
    hangman();
}