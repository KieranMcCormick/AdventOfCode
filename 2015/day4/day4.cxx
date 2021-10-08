#include "md5.h"
#include <inttypes.h>
#include <stdio.h>
#include <string> 

using namespace std;

int main()
{
    string input = "ckczppom";
    string target = "000000";
    int i = 0;

    while(md5(input + to_string(++i)).compare(0, 6, target) != 0);
    cout << i;

    return 0;
}

// string input = "<input>";
// string target = "000000";
// int i = 0;
// while(md5(input + to_string(++i)).compare(0, 6, target) != 0);
// cout << i;