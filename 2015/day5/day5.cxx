#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool IsVowel(char c)
{
    switch(c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

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
        int vowelCount = 0;
        bool hasTwiceInARow = false;
        bool isNaughty = false;
        
        getline(input, line,'\n');

        for(char& c : line)
        {
            if (IsVowel(c))
                vowelCount++;

            if (prevChar != ' ')
            {
                if (c == prevChar)
                    hasTwiceInARow = true;
                
                if (IsNaughtyVowel(string() + prevChar + c))
                {
                    isNaughty = true;
                    break;
                }
            }
            prevChar = c;
        }
        if (isNaughty)
        {
            naughtyCount++;
            continue;
        }

        if (vowelCount >= 3 && hasTwiceInARow)
            niceCount++;
        else
            naughtyCount++;
    }

    cout << "Nice Count: " << niceCount << ", Naughty Count: " << naughtyCount;

    return 0;
}


    // string target = "000000";
    // int i = 0;

    // while(md5(input + to_string(++i)).compare(0, 6, target) != 0);