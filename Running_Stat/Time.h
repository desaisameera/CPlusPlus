/*
 * Time.h
 *
 */
#ifndef TIME_H
#define	TIME_H
#include<vector>
/*Class that converts the time from the string format to integer, converts the time to seconds,
 * outputs the time in HH:MM:SS format and overloads the operators +,<,/,==,>> and <<
 *
 */

class Time {

public:
    /*
     * Default Constructor that sets the time to zero
     */
    Time();

    /*
     * Time constructor that reads the time in the
     * string format which is of the form HH:MM:SS
     *
     * @param time is the time entered in the string format
     */
    Time(std::string time);

    /*
     * Constructor that sets the time to seconds
     *
     * @param seconds is the number of seconds
     */
    Time(int seconds);

    /*
     * Function that converts the string time to integer time and
     * converts the time in the format HH::MM:SS to seconds
     *
     * @param time is the time entered in the string format
     */
    void setTime(std::string time);

    /*
     * Function that converts the seconds to HH:MM:SS
     *     * @return time in the string format HH:MM:SS
     */
    std::string getTimeinHHMMSS()const;

    /*
     * Function that overloads the operator <
     *
     * @param rhs is the operand on the right hand side
     *
     * @return true if the left hand side is less than the right hand side
     * else false
     */
    bool operator<(const Time& rhs)const;

    /*
     * Function that overloads the + operator
     *
     * @param rhs is the operand on the right hand side
     * @return returns the addition of the time
     */
    Time operator+(Time& rhs);

    /*
     * Function that overloads the operator /
     *
     * @param rhs is the operand on the right hand side
     * @return returns the division of the time
     */
    Time operator/(const Time& rhs)const;

    /*
     * Function that overloads the == operator
     *
     * @param rhs is the operand on the right hand side
     * @return returns true if both the operands are equal else
     * it returns false
     */
    bool operator==(const Time& rhs)const;

    /*
     * Function that overloads the >> operator
     *
     * @param stream is the object on which the insertion is performed and t is the time
     */
    friend std::istream& operator>>(std:: istream& stream,Time& t);

    /*
     * Function that overloads the << operator
     *
     * @param os is the object on which extraction is performed and t is the time
     */
    friend std::ostream& operator<<(std::ostream& os, const Time& t );

private:
    int secs;
};
#endif	/* TIME_H */

