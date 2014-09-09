/**Statistics.h
 *
 * A .h file that calculates the
 * mean,median,mode,minimum and the maximum
 * element.
 *
 */
#ifndef _STATISTICS_H_
#define _STATISTICS_H_
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<set>
#include<map>
#include<exception>
#include<stdexcept>
#include"Time.h"

template< class T >
class Statistics
{
public:
    typedef T value_type;
    /**
    * Calculate the mean (average) of the data entered.
    *
    * @return the mean of the data pushed into our data set
    */
   T mean()
   {
       /*Check if there is enough data
        * to calculate the mean. If there is not enough data
        * throw an exception
        */
       if(TimeinSecs.size() < 1)
       {
           throw std::underflow_error("Not enough data");
       }
       else
       {
           T sum = 0;                    //Initialize the sum to zero
           sum=std::accumulate(TimeinSecs.begin(), TimeinSecs.end(),T(0));       //Add all the elements using the accumulator
           int size1 = TimeinSecs.size();         //Find the number of elements
           T mean1 = sum / size1;                   //Compute mean using sum/Number of elements
           return mean1;                        //Return mean
       }
   }


   /**
    * Calculate the median (middle element when the data is sorted)
    *
    * @return the mode of the data pushed into our data set
    */
   T median()
   {
       /*Check if there is enough data
        * to calculate the median. If there is not enough data
        * throw an exception
        */
       if(TimeinSecs.size() == 0)
       {
           throw std::underflow_error("Not enough data");
       }
       else
       {
           T median = 0;          //Initilaize the median to zero
           std::sort(TimeinSecs.begin(), TimeinSecs.end());      //Sort the elements
           int SizeOfVector = TimeinSecs.size();                  //Compute the size of the vector
           int mid = (SizeOfVector) / 2;                            //Calculate the mid value

           /*If the number of elements is odd return the
            * middle element else return the average of the
            * middle two values
            */
           if(SizeOfVector % 2 != 0)
           {
               median = TimeinSecs[mid];
               return median;
           }
           else
           {
               median = (TimeinSecs[mid - 1] + TimeinSecs[mid]) / 2;
               return median;
           }
       }
   }

   /**
    * Calculate the mode (most common element).
    *
    * @return a set of the most common elements.  This can be the empty set if
    * there is a uniform distribution
    */
   std::set<T> mode()
   {
       std::set<T>_Mode;
       /*Check if there is enough data
        * to calculate the mode. If there is not enough data
        * throw an exception
        */
       if(TimeinSecs.size() == 0)
       {
           throw std::underflow_error("Not enough data");
       }
       else
       {
           int max = 1;           //Initialize max to 1
           int VectorSize = TimeinSecs.size();            //Compute the size of the vector
           for(int i = 0; i < VectorSize; i++)
           {
               T Element = TimeinSecs.at(i);              //Element is the element at every position
               int Count = std::count(TimeinSecs.begin(), TimeinSecs.end(),Element);       //Find the count of each element

               //If Count is greater than the max change max to
               //that value and clear the mode set
               if(Count > max)
               {
                   max = Count;
                   _Mode.clear();
                   _Mode.insert(Element);       //Insert the element
               }

               //Check if the distribution is normal then return an empty set
               else if(Count == 1 && max == 1)
               {
                   _Mode.clear();
               }

               //Check if more than one element are of the
               //same count. If there is more than one element
               //return that element also
               else if(Count == max)
               {
                   _Mode.insert(Element);
               }
           }
       }
       return _Mode;
   }

   /**
    * Get the value of the smallest element
    *
    * @return the minimum value of the data pushed in
    */
   T min()
   {
       /*Check if there is enough data
        * to calculate the minimum value. If there is not enough data
        * throw an exception and return zero.
        */
       if(TimeinSecs.size() == 0)
       {
           return T(0);
           throw std::underflow_error("Not enough data");
       }
       else
       {
           return *(std::min_element(TimeinSecs.begin(), TimeinSecs.end()));    //Return the minimum element
       }

   }


   /**
    * Get the value of the largest element
    *
    * @return the maximum value of the data pushed in
    */
   T max()
   {
       /*Check if there is enough data
        * to calculate the maximum value. If there is not enough data
        * throw an exception and return zero
        */
       if(TimeinSecs.size() == 0)
       {
           return T(0);
           throw std::underflow_error("Not enough data");
       }
       else
       {
           return *(std::max_element(TimeinSecs.begin(), TimeinSecs.end()));             //Return the maximum element
       }

   }

   /**
    * Add an element to our data set
    *
    * @param t Element to add to our data
    */
   void push( T t )
   {
       TimeinSecs.push_back(t);                //Insert the elements in the vector
   }

   /**
    * Removes all elements from the data
    */
   void clear()
   {
       TimeinSecs.clear();              //Clear the vector
   }


   private:
       std::vector<T>TimeinSecs;
};

#endif // _STATISTICS_H_


