#include <string>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include<iostream>
#include<algorithm>
#include<exception>
#include<stdexcept>
#include "Time.h"

using namespace std;

Time::Time()
{
   secs = 0;      //Set seconds to zero
}

Time::Time(std::string t)
{
    setTime(t);         //Call the setTime fuction

}

Time::Time(int seconds)
{
     secs = seconds;      //Set the secs to the converted seconds
}

void Time::setTime(string t)

{
    int hours = 0,minutes = 0,seconds = 0;    //Initialize the hours,minutes and seconds to zero
    int colon1 = -1,colon2 = -1;            //Set the position of colon1 and colon2 to -1

    colon1 = t.find(':');                 //Find the position of first colon
    colon2 = t.find(':', colon1 + 1);        //Find the position of the second colon
    hours = atoi(t.substr(0, colon1).c_str());     //convert the hours from string to integer
   if(colon1 != -1)
    {
        minutes = atoi(t.substr(colon1+1, colon2).c_str()); //Convert the minutes from string to integer
    }

    else
    {
        minutes = 0;
    }
    if(colon2 != -1)
    {
        seconds = atoi(t.substr(colon2 + 1).c_str());       //Convert the seconds from string to integer
   }
    else
    {
        seconds = 0;
    }

    /*Throw exceptions if the number of hours is less than zero,
     * if the number of minutes is greater than 60 and the number of
     * seconds is greater than 60
     */
        if(hours < 0)
        {
            throw range_error("Invalid Time entry");
        }

         if(minutes > 60)
         {
             throw range_error("Invalid Time entry");

         }

        if(seconds > 60)
        {
			throw range_error("Invalid Time Entry");
		}
        secs = hours * 3600 + minutes * 60 + seconds;     //Convert the hours and minutes to seconds
}


string Time::getTimeinHHMMSS() const
{
     ostringstream osstr ;

     /*
      * Return the seconds in the form HH:MM:SS
      */
     osstr <<secs / 3600 << ":" <<setw(2)<< setfill('0') << ( secs % 3600 ) / 60<<":"<<setw(2)<<(secs%3600)%60;
	 return osstr.str();
}


istream& operator>>(istream& stream, Time& t)
{
   string s;
   stream >> s;
   t.setTime( s );
   return stream;
}


ostream& operator<<(ostream& os, const Time& t )
{
    os <<t.getTimeinHHMMSS();
    return os;
}

bool Time::operator <(const Time& rhs)const
{
    /*
     * check if the operand on  the left hand side is less
     * than the operand on the right hand side
     *
     */
    if(secs < rhs.secs)
        return true;
    else
        return false;
}


Time Time::operator +(Time& rhs)
{
    //Add the operands
    return(secs + rhs.secs);
}


Time Time::operator /(const Time& rhs) const
{
    //Divide the operands
    return(secs / rhs.secs);
}


bool Time::operator ==(const Time& rhs) const
{
    //Compare the operands and reurn true if they are equal
    if(secs == rhs.secs)
    {
        return true;
    }
    else
        return false;
}