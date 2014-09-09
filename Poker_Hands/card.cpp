#include "card.h"
#include <sstream>
#include<iostream>
using namespace std;

Card::Card()
{
}

Card::Card( Card::SUITS _suit, Card::COUNT _val )
{
    suit=_suit;     //Set the suit value
    value=_val;     //Set the value of the card

}

Card::COUNT Card::getValue()
{
    return this->value;       //Return the value of the card
}

 Card::SUITES Card::getSuit()
 {
     return this->suit;       //Return the value of the suit
 }

/*
 * Function that converts the value of the card to string
 * For example if the value of the card is 2, 2 will be printed
 */
string Card::valToStr()
 {
     Card::COUNT Value;
     Value=getValue();        //Get the value of  the card

     /*Check if the values are between 2 to 14 and print the
      * values accordingly. If the value is 11 'J' will be
      * printed and so on
      */

     if(Value==2)
     {
         return " 2";
     }
     else if(Value==3)
     {
         return " 3";
     }
     else if(Value==4)
     {
         return " 4";
     }
     else if(Value==5)
     {
         return " 5";
     }
     else if(Value==6)
     {
         return " 6";
     }
     else if(Value==7)
     {
         return " 7";
     }
     else if(Value==8)
     {
         return " 8";
     }
     else if(Value==9)
     {
         return " 9";
     }
     else if(Value==10)
     {
         return "10";
     }
     else if(Value==11)
     {
         return " J";
     }
     else if(Value==12)
     {
         return " Q";
     }
     else if(Value==13)
     {
         return " K";
     }
     else if(Value==14)
     {
         return " A";
     }
 }

/*
 * Function that prints the value of the suits in string format
 * For example if the suit is of the type Diamond, then it will print
 * 'D' and so on
 */
string Card::suitToStr()
 {
     Card::SUITES s;
     s=getSuit();        //Get the value of the suit

     /*Check if the values and print the
      * value of the suits. If the value is
      * 1 the card belongs to the suit Clubs and therefore
      * 'C' is printed.Similarly,'D' for diamonds,
      * 'S' is for spades and 'H' is for Hearts.
      */
     if(s==1)
     {
         return "C";
     }
     else if(s==2)
     {
         return "D";
     }
     else if(s==3)
     {
         return "H";
     }
     else if (s==4)
     {
         return "S";
     }
}

/*Get a string representation of cards
 */
std::string Card::str()
{
   ostringstream os;
   os << valToStr() << suitToStr();
   return os.str();
}

/* Your code here */



