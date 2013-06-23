#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;
const int ALLOWED_TRIES=10;

void getFile(vector<string>& wordvector) {
    ifstream infile;
    ofstream outfile;
    infile.open("//home//melbster//Desktop//C++Files//hangman.txt");
    string line, word;

    while (infile.good()) {
        while (infile >> word) {
            for (int i = 0; i < word.size(); i++) {
                word[i] = tolower(word[i]);
                if (!isalpha(word[i]))
                    word.erase(word.begin() + i);
            }
            wordvector.push_back(word);
        }
    }
    infile.close();
}

void hangman() {
    vector<string> gameVector;
    getFile(gameVector);

    int r = rand() % gameVector.size();
    string gameWord = gameVector[r];
    bool victory = false;
    char guess;
    char* word = new char[gameWord.size()];
    int correctGuesses = 0;
    int numberOfGuesses = 0;
    for (int i = 0; i < gameWord.size(); i++) {
        word[i] = '_';
    }
    int size = gameWord.size();

    for (int i = 0; i < size; i++) {
        cout << word[i] << " ";
    }

    while (!victory) {
        cout << endl<<"Skriv in bokstav " << endl;
        cin >> guess;
        for (int i = 0; i < size; i++) {
            cout << word[i] << " ";
        }

        for (int i = 0; i < size; i++) {
            if (gameWord[i] == guess) {
                cout << endl << endl << "Correct! " << endl;
                correctGuesses++;
                word[i] = gameWord[i];

                gameWord[i]=NULL;
            }
        }
        numberOfGuesses++;
        cout << "Tries: " << numberOfGuesses << endl;
        cout << "Allowed tries: " << ALLOWED_TRIES<<endl<<endl;
        cout << "Current word: ";
        for (int i = 0; i < size; i++) {
            cout << word[i] << " ";
        }
        if (correctGuesses >= size) {
            victory = true;
        }
        if(numberOfGuesses>ALLOWED_TRIES){
            cout<<endl<<"Sorry! Too many guesses! You lost :(";
            exit(0);
        }
    }
    cout << endl << "Gratulerer! Du har vunnet!" << endl;

    delete[] word;
}