#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int totalPaper = 0;
    int i = 0;
    string side1;
    int side1val;
    string side2;
    int side2val;
    string side3;
    int side3val;

    ifstream input("2015/day2/day2input.txt");

    int a = 0;
    int b = 0;
    if(!input) 
    {
        cout<<"Error opening output file"<<endl;
        return -1;
    }
    while(!input.eof())
    {        
        getline(input, side1,'x');
        side1val = atoi(side1.c_str());
        getline(input, side2,'x');
        side2val = atoi(side2.c_str());
        getline(input, side3,'\n');
        side3val = atoi(side3.c_str());

        int smallestSide = side3val;

        if (side1val < side2val)
        {
            if (side1val < side3val)
                smallestSide = side1val;

            // else side 3 is smallest
        }
        // then side 2 is smaller than side 1
        else if (side2val < side3val)
            smallestSide = side2val;

        // else side 3 is smallest
        
        int boxPaper =  (2 * (side1val * side1val)) 
                      + (2 * (side2val * side2val))
                      + (2 * (side3val * side3val))
                      + (smallestSide * smallestSide);

        totalPaper += boxPaper;

        i++;
    }
    cout << i << '\n';
    cout << totalPaper;
}