/**
 * main.cpp
 */
#include "deck.h"
#include "hand.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{
    vector< Hand > hands;     //Create an object of the class Hands
    Deck deck;                //Create an object of the class Deck
    int players;              //players is the number of players
    int seed;                 //Declare the seed
    int sizeOfHand = 5;       //Initialize the size of the hand to 5

   cout << "Enter seed: ";
   cin >> seed;
   srand(unsigned(seed));

   cout << "Enter number of players: ";
   cin >> players;

   /*Shuffle the deck
    */
   deck.Shuffle();

   /* Your code here */
   /* Deal cards from the deck and do a round robin distribution to the
    * players.  Thus, if you had 5 players, and they each needed 5 cards you
    * would pull 5 cards off the deck and assign the first card to player one,
    * the second to player 2, etc.. Then you would deal 5 more and repeat the
    * process until 25 cards are dealt
    */

   /**
    * Create a vector DistriCards that stores the shuffled cards
    * to be distributed. i.e if 2 players are playing then
    * DistriCards will contain 2*5=10 cards from the shuffled deck,
    *  where 5 is the size of the hand,
    *
    */
   vector<Card>DistriCards;
   int count=players*sizeOfHand;      //Calculate the total number of cards to be distributed

   hands.resize(players);            //Initialize the vector hands to the number of players 

   /*
    * Deal the cards
    * @param count is the total number of cards to be distributed
    *
    */
   DistriCards=deck.Deal(count);

   /*Distribute the cards in round-robin fashion and check
    *the cards.
    */

   for(int i=0;i<hands.size();i++)
   {
       for(int j=0;j<count;j++)
       {
           if(j%players==i)
           {
               hands[i].add(DistriCards[j]);
            }
       }
       cout<<"Player "<<i+1<<" hand:  ";
       hands[i].showHand();     //Print the hands of the players
       hands[i].check();        //Check the players` hands
       cout<<endl;
   }
   /*
    * Dump out the content of the current deck minus the already dealt cards
    */
   deck.ShowDeck();
}
