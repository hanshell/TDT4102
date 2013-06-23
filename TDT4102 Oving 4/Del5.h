/* 
 * File:   Del5.h
 * Author: melbster
 *
 * Created on February 18, 2013, 9:19 PM
 */

#ifndef DEL5_H
#define	DEL5_H
#include <string>

#include "Del4.h"

class CardDeck {
private:
    std::string checkSuit(int i);
    Card cards[52];
    int numberDealt;
public:
    CardDeck();
    CardDeck(bool shouldShuffle);
    void buildDeck();
    void shuffle();
    void dealHand(int numberOfCards);
    void run();
};

#endif	/* DEL5_H */