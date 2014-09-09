#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Time.h"

using namespace std;

Time::Time(void) {
   seconds = 0;
}

Time::Time(int _seconds) {
    seconds = _seconds;
}

Time::Time(string t) {
   setTime(t);
}

Time Time::add(Time t) {
   return seconds += t.seconds;
}

Time Time::subtract(Time t) {
   return seconds -= t.seconds;
}

std::string Time::str() const {
   /* Use ostringstream to convert from int to string. This will be covered in
    * detail in week 8
    */
   ostringstream oss;
   oss << seconds / 3600 << ":" << setfill('0') << setw(2) << ( seconds % 3600 ) / 60;
   return oss.str();
}

void Time::setTime(std::string t) {
   /* Your code here */

    /*Find the position of the colon
     * and convert the part before colon
     * to seconds by multiplying it by 3600
     * and the part after colon by multiplying
     * it by 60
     */
    int ans = 0, colon;    //Initialize the ans to zero and
                        //colon is the variable that stores the
                        //position of the colon in string
    string min;         //stores the part after colon as a string
    ans = atoi(t.c_str());        //Convert the part before
                                //colon to integer
    colon = t.find(':');          //Find the position of the colon
    for(int i = colon+1; i < t.length(); i++) {
        min = min + t[i];           //Copy the part after colon i.e minutes
                                //to the variable min
    }

    int MinInInt = 0;             //Variable that stores the minutes
                                //in integer format
    MinInInt = atoi(min.c_str());//Convert the  minutes to integer
    seconds = ans * 3600 + MinInInt * 60;       //Convert the time to seconds
    //Time(seconds);
}
