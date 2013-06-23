#include <iostream>
#include <stdlib.h>
#include "Del4.h"
#include "Del5.h"

using namespace std;
const int TYPES_OF_SUITS = 4;
const int SUIT_AMOUNT = 13;

CardDeck::CardDeck() {
    buildDeck();
    shuffle();
    run();
}
CardDeck::CardDeck(bool shouldShuffle) {
    buildDeck();
    if (shouldShuffle == true)
        shuffle();
}
std::string CardDeck::checkSuit(int i) {
    switch (i) {
        case 0:
            return "S";
        case 1:
            return "D";
        case 2:
            return "H";
        case 3:
            return "C";
        default:
            return NULL;
    }
}
void CardDeck::buildDeck() {
    numberDealt = 0;
    Card card;
    int k = 0;
    for (int i = 0; i < TYPES_OF_SUITS; i++) {
        for (int j = 1; j < SUIT_AMOUNT + 1; j++) {
            card.setSuit(checkSuit(i));
            card.setValue(j);
            cards[k] = card;
            k++;
        }
    }
    //    for (int i = 0; i < 52; i++) {
    //        cout << cards[i].getFace() << endl;
    //    }
}

void CardDeck::shuffle() {
    numberDealt = 0;
    int randIndex;
    Card temp1;
    Card temp2;
    for (int i = 0; i < 50; i++) {
        randIndex = rand() % 52;
        temp1 = cards[i];
        temp2 = cards[randIndex];

        cards[i] = temp2;
        cards[randIndex] = temp1;
    }
    //    for (int i = 0; i < 50; i++) {
    //        cout << cards[i].getFace() << endl;
    //    }
}

void CardDeck::dealHand(int numberOfCards) {
    int randIndex=rand()%50;
    int size = 0;
    while (size < 52) {
        size += numberOfCards;
    }
    size -= numberOfCards;
    Card cardsDealt[size];
    Card card;
    
    for (int i = 0; i < numberOfCards; i++) {
        randIndex = rand() % 50;
        cardsDealt[i] = cards[randIndex];
        card=cards[randIndex];
        numberDealt++;
    }
    cout << numberDealt << endl << endl;
    for (int i = 0; i < numberOfCards; i++) {
        cout << cardsDealt[i].getFace() << endl;
    }
}

void CardDeck::run() {
    int numberOfCards;
    cout << "Skriv inn antall kort" << endl;
    cin >> numberOfCards;
    int input;
    cout<<"Skriv inn 1 for å fortsette"<<endl;
    cin>>input;
    
    while (input == 1 && numberDealt+numberOfCards < 52) {
        dealHand(numberOfCards);

        cout << "Skriv inn 1 " << endl;
        cin >> input;
    }
}
