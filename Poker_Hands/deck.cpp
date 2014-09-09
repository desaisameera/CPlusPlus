#include "deck.h"
#include <iostream>
#include <algorithm>

using namespace std;

Deck::Deck()
{
   Shuffle();
}

void Deck::Shuffle()
{
    cards.erase(cards.begin(), cards.end());
    for ( int i = Card::CLUBS; i <= Card::SPADES; i++ )
    {
        for ( int j = Card::TWO; j <= Card::ACE; j++ )
        {
            cards.push_back( Card(Card::SUITS(i),Card::COUNT(j)));
        }
    }
    random_shuffle ( cards.begin(), cards.end() );

}


/* Your code here */
/*Deal returns the number of the cards that are dealt with.
 * @param count is the number of cards to deal with
 * @return a set of cards from the front of the desk
 */
vector<Card> Deck::Deal(int count)
{
    int _count;
    _count=count;       //Initialize count to the number of cards to deal
    vector<Card>CardsToDeal(_count);    //CardsToDeal contains the cards returned 
                                        //from the front of the desk

    for(int i=0;i<_count;i++)
    {
        CardsToDeal[i]=cards[i];      //Copy the cards from the front of the desk
    }
    return CardsToDeal;
}

void Deck::ShowDeck()
{
    cards.clear();         //Clear the cards vector
}
