#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int totalRibbon = 0;
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

        int dims[3] = { lengthval, widthval, heightval };

        sort(begin(dims), end(dims));

        int ribbonperim = 0;
        ribbonperim =   (2 * dims[0])
                      + (2 * dims[1]);

        int ribbonbow = 0;
        ribbonbow =   lengthval 
                    * widthval
                    * heightval;

        totalRibbon += (ribbonbow + ribbonperim);

        i++;
    }
    cout << i << '\n';
    cout << totalRibbon;
}