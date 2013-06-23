#include <iostream>
#include <fstream>
using namespace std;

void storeWords() {
    ofstream output;
    output.open("//home//melbster//Desktop//C++Files//oppg1.txt");
    string input;
    cout << "Skriv inn tekst" << endl;
    getline(cin, input);
    while (input != "exit") {
        for (int i = 0; i < input.size(); i++) {
            output << input[i];
        }
        output << "\n";
        cout << "Skriv inn tekst" << endl;
        getline(cin, input);
    }
    output.close();
}

void readAndStore() {
    ifstream inputfile;
    ofstream outputfile;


    inputfile.open("//home//melbster//Desktop//C++Files//inputfile.txt");
    outputfile.open("//home//melbster//Desktop//C++Files//outputfile.txt");

    string input;

    int i = 1;
    if (inputfile) {
        while (inputfile.good()) {
            getline(inputfile, input);
            outputfile << i << "   " << input << "\n";
            i++;
        }
    }
    else{
        cerr<<"No such input file exists"<<endl;
    }
    inputfile.close();
    outputfile.close();
}
void charStats(){
    const int LETTERS=26;
    int letters[LETTERS];
    
    for(int i=0; i<LETTERS; i++){
        letters[i]=0;
    }
    
    ifstream infile;
    infile.open("//home//melbster//Desktop//C++Files//characterStatistics.txt");
    string line;
    char c;
    int numberofcharacters=0;
    while(infile.good()){
        getline(infile, line);
        for(int i=0; i<line.size(); i++){
            c=tolower(line[i]);
            if(c==' ')
                continue;
            letters[int(c)-97]++;
            numberofcharacters++;
        }
    }
    infile.close();
    cout<<numberofcharacters<<endl;
    for(int i=0; i<LETTERS; i++){
        cout<<char(97+i)<<": ";
        cout<<letters[i]<<endl;
    }
}
//int main() {
//    storeWords();
//}