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
    string length;
    int lengthval;
    string width;
    int widthval;
    string height;
    int heightval;

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
        getline(input, length,'x');
        lengthval = atoi(length.c_str());
        getline(input, width,'x');
        widthval = atoi(width.c_str());
        getline(input, height,'\n');
        heightval = atoi(height.c_str());

        int side1 = lengthval * widthval;
        int side2 = widthval * heightval;
        int side3 = lengthval * heightval;
        
        int smallestSide = side3;

        if (side1 < side2)
        {
            if (side1 < side3)
                smallestSide = side1;

            // else side 3 is smallest
        }
        // then side 2 is smaller than side 1
        else if (side2 < side3)
            smallestSide = side2;

        // else side 3 is smallest
        

        
        int boxPaper =  (2 * side1) 
                      + (2 * side2)
                      + (2 * side3)
                      + (smallestSide);

        totalPaper += boxPaper;

        i++;
    }
    cout << i << '\n';
    cout << totalPaper;
}