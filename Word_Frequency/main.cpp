/*
 * Simple main.cpp that read in a text file and output the frequency of each word.
 * This program also eliminates the punctuation marks around the words.
 *
 */
#include <iostream>
#include <fstream>
#include<map>
#include <vector>
#include<algorithm>
#include<string>
#include<libgen.h>

using namespace std;
/*
 * Function that finds the space in the string to output words
 *
 * @param str is the string to be read to find the space
 * @return returns the position of the space
 */
int FindSpace(string str) {

    int position = -1;       //Initialize the posisiton to -1
    position = str.find(' ');     //Find the position of the space
    if(position == -1) {
        return str.size();
	}
    else {
        return position;
	}
}

/*
 * Function that finds the words in the string
 * @param str is the string to be read to find the words,position is the position of the space
 * @return returns the word
 */
string FindWords(string str, int position) {
    string Word = str.substr(0,position); //Extract the word
    return Word;
}

/*
 * Function that finds if there is a new line after a word
 * @param str is the string to be read to find a new line
 * @return returns the position of the string
 */
int FindNewLine(string str) {
    int Position = -1;    //Initialize the position to -1
    Position = str.find('\n');    //Find the position of newline
    return Position;            //Return the position of the newline
}

/*
 * Function that eliminates the punctuation marks in a string
 * @param str is the string to be read to eliminate the punctuation marks
 * @return returns the string without the punctuation marks
 */
string RemovePunctuation(string str) {
    int LastPosition = str.length() - 1;    //Initialize the LastPosition to the last position of the string

    //If the last character is a punctuation mark, return the string without the last character  else return the  string
    if(str[LastPosition] == '!' || str[LastPosition] == '.' || str[LastPosition] == ',' || str[LastPosition] == '?' || str[LastPosition] == ';' || str[LastPosition] == ':' || str[LastPosition] == '-' || str[LastPosition] == '|' || str[LastPosition] == ' ') {
        return str.substr(0,LastPosition);
	}
    else {
        return str;
	}
}

/*
 * Function that removes the punctuation around the words
 * @param str is the string to be read to remove the punctuation around the words
 * @return returns the word after removing the punctuation
 */
string RemovePunctuationAround(string str) {
    int LastPosition = str.length() - 1;    //Initialize the LastPositon to the last character
    int FirstPosition = 0;                //Initialize the first position to the first character

    /*
     * If the last and the first characters are ' return the string without the '
     */
    if(str[LastPosition] == '\'') {
        str = str.substr(0, LastPosition);
    }
    if(str[FirstPosition] == '\'') {
        str = str.substr(1, LastPosition + 1);
    }
    return str;
}

/*
 * Function that checks of the string is already present in the map
 * @param str is the string to check if it exists in the map ,@param map is the map of Words
 * @return returns the number of times the word occurs in the string
 */
int Exists(string str, map<string,int>_map) {
    int _count = 0;       //Initialize the count to zero
    _count = _map.count(str);     //Count the number of times the string is present
    return _count;
}

int main(int argc,char*argv[]) {
    map<string,int>Words ;      //Map of words
    string OriginalWork;        //String of Original words
    ifstream input;
    map<string,int>::iterator it;       //Iterator for the map
    string str1;
    /*
     * Check if a single filename is specified on the commandline argument
     */
    if(argc==2) {
        //Open the file
        input.open(argv[1]);

        //Check if the filename specified by the user can be opened
        if(input.fail()) {
            cerr << basename(argv[0]) << ": " << argv[1] << ": No such file" << endl;
            exit(2);
        }

        /*
         * Read till the end of the file
         */
        while(!input.eof()) {
            while(input.good()) {
                char c;

                //Get the characters from the file
                input.get(c);

                //If the end of file is reached,stop reading
                if(input.eof()) {
                    break;
				}

                //Append every character to form a string of the file
                OriginalWork = OriginalWork + c;
            }

            int pos = -1;         //Initialize the position of the space to -1
            int beg = 0;  //Initialize the beginning of the string to 0
            int end = OriginalWork.size() - 1;      //Initialize the end of the string to the last postiion
            int i = 0;

            //Partial is the string to processed to find words and remove punctuation marks and it
            //is initialized to OriginalWork
            string Partial=OriginalWork;

            /*
             * Till the end of the string find the words, remove the punctuation marks
             * check if the word exists in the map and output the frequency of the word
             */
            while(i < end) {
                /*
                 * copy the string to be processed to Partial
                 */
				if(Partial.size() > (pos + 1)) {
					Partial=Partial.substr(pos+1,Partial.npos);
				}
                /*
                 * Find the position of the space in the string
                 */
                pos = FindSpace(Partial);
                /*
                 * Find the words in from the string
                 */
                str1 = FindWords(Partial,pos);

                /*
                 * Check if there is a new line after a word i.e when a word doesnt fit in
                 * a line, it is entered in a new line
                 */
                int NewLine = 0;
                /*
                 * Find the position of the newline
                 */
                NewLine = FindNewLine(str1);
                 /*
                 *If there`s a newline after a word return the word only till the new line
                 * and set the position to the position of the newline. If theres is no new line
                 * return the string
                 */
                if(NewLine == -1) {
                    str1 = str1;
                }
                else {
                    str1 = str1.substr(0, NewLine);
                    pos = NewLine;
                }

                 //Remove the punctuation marks after the words
                str1 = RemovePunctuation(str1);

                //Remove the punctuation marks around the words
                str1 = RemovePunctuationAround(str1);

                //Check if the word already exists in the map
                int Number = Exists(str1, Words);

                /*
                 * If the number already exists in the map, increase the count of the word in the map else
                 * insert the word in the map with count equal to 1
                 */
                if(Number == 0) {
                    /*Check if the string is empty i.e if there is a new paragraph
                     * the string before the starting of the paragraph will be empty
                    */
					if(str1.empty()) {
						continue;
                    }

                    Words.insert(pair<string,int>(str1,1));
                }
                else {
                    int c = Words[str1];
                    c = c + 1;
                    Words[str1] = c;
                }

                //Increment the value of i to the till the position the string is processed
                i = pos + 1 + i;
            }

            //Print the words and their frequency in alphabetical order
            for(it = Words.begin(); it != Words.end(); it++) {
                cout << it->first << ": " << it->second << endl;
            }
            exit(0);
        }
    }

    //If a single filename was not specified print the following
    else {
        cerr << "Usage: " << endl;
        cerr << endl << "   " << basename(argv[0]) << " filename" << endl;
        cerr << endl;
    }
    return 0;
}
