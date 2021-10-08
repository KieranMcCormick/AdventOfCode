#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool IsNaughtyVowel(string str)
{
    // cout << str << '\n';
    if (str.compare("ab") == 0
        || str.compare("cd") == 0
        || str.compare("pq") == 0
        || str.compare("xy") == 0)
        return true;

    return false;
}

int main()
{
    ifstream input("2015/day5/day5input.txt");
    int niceCount = 0;
    int naughtyCount = 0;
    if(!input) 
    {
        cout<<"Error opening output file"<<endl;
        return -1;
    }
    while(!input.eof())
    {    
        string line;
        char prevChar = ' ';
        char char2charsAgo = ' ';
        bool isNaughty = false;
        string lastIdxNaughty = " ";
        bool has2LetInARow = false;
        bool has2CharThatMatch = false;

        // map of chars to index of second char
        // where first char is the char before second char in string
        map<string, int> dict;
 
        getline(input, line,'\n');
        
        int i = 0;
        for(char& c : line)
        {
            if (prevChar != ' ')
            {
                // TO FIND TWO LETTERS THAT APPEAR TWICE BUT DONT OVERLAP
                    // add current and last chars to map
                    // on colis, if indexes dont overlap, we have found match,
                    // if index overlap, then naughty
                string currPair = string() + prevChar + c;
                map<string, int>::iterator it = dict.find(currPair);
                if (it == dict.end())
                {
                    dict.insert(pair<string, int>(currPair, i));
                }
                else
                {
                    // Detect naughty
                    if (i - 1 == it->second)
                    {
                        isNaughty = true;
                        lastIdxNaughty = currPair;
                    }
                    else
                    {
                        if (currPair.compare(lastIdxNaughty))
                        {
                            isNaughty = false;
                            
                        }
                        lastIdxNaughty = " ";
                        
                        
                        has2LetInARow = true;
                    }
                }
                // TO FIND TWO CHARS THAT MATCH WITH 1 CHAR INBETWEEN THEM
                    // compare current char to char -2 index ago
                if (char2charsAgo != ' ')
                {
                    if (char2charsAgo == c)
                        has2CharThatMatch = true;
                }
                char2charsAgo = prevChar;
            }
            prevChar = c;
            i++;
        }

        if (has2CharThatMatch && has2LetInARow)
            niceCount++;
        else
            naughtyCount++;
        
    }

    cout << "Nice Count: " << niceCount << ", Naughty Count: " << naughtyCount;

    return 0;
}