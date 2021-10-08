#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

enum Command { Toggle, TurnOn, TurnOff };

bool OperateLight(Command command, bool light)
{
    // cout << "command: ";
    switch (command){
        case Toggle:
            // cout << "toggle\n";
            return !light;
        case TurnOn:
            // cout << "TurnOn\n";
            return true;
        case TurnOff:
            // cout << "TurnOff\n";
            return false;
    }

    return false;
}

// Command GetCommand(string command)
// {
    
// }

int main()
{
    ifstream input("2015/day6/day6input.txt");
    
    int litCount = 0;

    if(!input) 
    {
        cout<<"Error opening output file"<<endl;
        return -1;
    }

    vector<vector<bool>> lights(1000, vector<bool>(1000, false));

    while(!input.eof())
    {    
        string part;
        Command command;
        getline(input, part,' ');
        if (part.compare("toggle") == 0)
        {
            cout << "toggle: '" << part << "\'\n";
            command = Toggle;
        }
        else if (part.compare("turn") == 0)
        {
            cout << "turn: " << part << '\n';
            getline(input, part,' ');
            cout << "on/off: " << part << '\n';

            if (part.compare("on") == 0)
                command = TurnOn;
            if (part.compare("off") == 0)
                command = TurnOff;
        }

        getline(input, part,',');
        cout << "idx1: " << part << '\n';
        int idx1 = stoi(part);

        getline(input, part,' ');
        cout << "idx2: " << part << '\n';
        int idx2 = stoi(part);
        
        // Skip through
        getline(input, part,' ');
        cout << "space: " << part << '\n';

        getline(input, part,',');
        cout << "idx3: " << part << '\n';
        int idx3 = stoi(part);

        getline(input, part,'\n');
        cout << "idx4: " << part << '\n';
        int idx4 = stoi(part);
        
        for (int row = idx1; row <= idx3; row++)
        {
            for (int col = idx2; col <= idx4; col++)
            {
                lights[row][col] = OperateLight(command, lights[row][col]);
            }
        }
    }

    vector<vector<bool>>::iterator itRow;
    vector<bool>::iterator itCol;

    for (itRow = lights.begin(); itRow != lights.end(); itRow++)
    {
        for (itCol = itRow->begin(); itCol != itRow->end(); itCol++) 
        {
            if ((*itCol) == true)
                litCount++;
        }

    }

    cout << "Lit Count: " << litCount;

    return 0;
}