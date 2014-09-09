#include "hand.h"
#include <iostream>


/* Your code here */

using namespace std;
/*
 * Function to check if the cards are Four
 * of a kind
 * @param _cards is the cards to be checked
 * @return bool retruns 1 if the cards are
 * four of a kind
 */
bool CheckFourOfKind(vector<Card>&_cards)
{
    int count;   //count is the number of cards of same type
    bool flag=false;    //set the flag to false
    /*
     * Check if there are four cards of the same value
     */
    for(int i=0;i<2;i++)
    {
        count=1;    //Initialize the count to 1

        /*
         * Check if four cards have same value
         */
        for(int j=i+1;j<_cards.size();j++)
        {
            if(_cards[i].getValue()==_cards[j].getValue())
            {
                count++;
            }
        }
        if(count==4)
        {
            flag=true;
        }
    }
   return flag;
}
/*
 * Check if all the five cards belong to the same suit
 * if the cards are of the same suit print Flush
 * @param _cards is the cards to checked
 * @return returns true if all the cards belong to the same suit
 */
bool CheckFlush(vector<Card>&_cards)
{
    bool flag=false;    //Initialize flag to false
    int count=1;        //Initialize the count to 1
    for(int i=1;i<_cards.size();i++)
    {
        /*
         * Compare the suits of the cards
         */
        if(_cards[0].getSuit()==_cards[i].getSuit())
        {
            count++;
        }
        /*If all 5 cards are of the same suit,
         * then print Flush
         */
        if(count==5)
        {
            flag=true;
        }
    }
    return flag;
}
/*Check if three of the cards have the same value
 * @param _cards is the cards to be checked
 * @return returns true if three of the cards are of the same value
 */
bool CheckThreeOfKind(vector<Card>&_cards)
{
    int count;
    bool flag=false;      //Initialize the flaf to false

    /*Check if the cards have the same value*/

    for(int i=0;i<3;i++)
    {
     count=1;      //Initialize the count to 1
        for(int j=i+1;j<_cards.size();j++)
        {
            if(_cards[i].getValue()==_cards[j].getValue()) //Compare the values of the cards
            {
                count++;       //Increment the counter if there`s a match
            }
        }
        /*
         * Return true if three cards of the same value are found
         */
        if(count==3)
        {
            flag=true;
        }

    }
    return flag;
}
/*
 * Check if there are two pairs of same value
 * @param _cards is the cards to be checked
 * @return returns true if two pairs of the same vale are found
 */
bool CheckTwoPair(vector<Card>&_cards)
{
    int pair=0;      //Initialize the pair to zero
    int count;
    bool flag=false;    //Initialize the flag to false

 /*
     * Check if the cards have the same value
     */
    for( int i=0;i<(_cards.size()-1);i++)
    {
        count=1;   //Initialize the count to 1
        for(int j=i+1;j<_cards.size();j++)
        {
            //Check if the value is same
            if(_cards[i].getValue()==_cards[j].getValue())
            {
                count++;     //Increment the count if a match is found

                if(count==2)
                {
                pair++;      //Increment the pair value if a match is found
                }
            }
        }

        //Return true if there are two pairs
        if(pair==2)
        {
            flag=true;
        }
    }
    return flag;
   }

/*
 * Check if the cards contain one pair
 * @param _cards is the cards to checked
 * @return returns true if one pair is found
 */
bool CheckOnePair(vector<Card>&_cards)
{
    int count;
    int pair=0;     //Initialize the value of pair to 0

    /*Check if cards of the same pair are present*/
    for(int i=0;i<(_cards.size()-1);i++)
    {
        count=1;       //Initialize the count to 1
        for(int j=i+1;j<_cards.size();j++)
        {
            /*
             * Check if the value of the cards is same
             */
            if(_cards[i].getValue()==_cards[j].getValue())
            {
                count++;        //If two cards of the saem value is found,
                                //increment the count
                /*
                 * If there are two cards of the same value increment the value
                 * of pair
                 */
                if(count==2)
                {
                    pair++;
                }

            }
        }
    }
    /*
     * Return true if the value of pair is one
     */
    if(pair==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*
 * Add in an individual card to players hand
 */
void Hand::add(Card card)
{
    cards.push_back(card);
}

/*
 * Print out the player`s hand
 */
void Hand::showHand()
{
    string Hd;
    for(int i=0;i<cards.size();i++)
    {
        Hd=cards[i].str();
        cout<<" "<<Hd;
    }
}
/*
 * Check the player`s hand in the order of
 * Four of a kind, Flush,Three of a kind, two pair and one pair
 */
void Hand::check()
{
  /*
   * If there are four cards of the same value return true
   */
    if(CheckFourOfKind(cards))
    {
        cout<<"  Four of a kind";
    }

    /*
     * If all cards belong to the same suit print Flush
     */
    else if(CheckFlush(cards))
    {
        cout<<"  Flush";
    }
    /*
     * If there are three cards of the same value print Three of a kind
     */
    else if(CheckThreeOfKind(cards))
    {
        cout<<"  Three of a kind";
    }

    /*
     * If there are two pairs of the same value, print two pair
     */
    else if(CheckTwoPair(cards))
    {
        cout<<"  Two Pair";
    }

    /*
     * If there is just one pair of hte same value print one pair
     */
    else if(CheckOnePair(cards))
    {
        cout<<"  One Pair";
    }

    //Clear the cards vector
     cards.clear();


}

