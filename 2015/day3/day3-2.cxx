#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <tuple>
#include <string>

using namespace std;
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;

string readFileIntoString(const string& path) {
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

int main() {

    string filename("2015/day3/day3input.txt");
    string file_contents;

    file_contents = readFileIntoString(filename);
    
    map<tuple<int, int>, int> houses_visited;
    
    int santaloc [4] = {0, 0, 0, 0};
    
    int numhousesvisited = 0;

    for (string::size_type i = 0;  i < file_contents.size(); i++ )
    {
        int santaIndx = 0;
        if (i % 2 != 0)
            santaIndx = 2;

        if (file_contents[i] == '<')
            santaloc[0 + santaIndx]--;
        else if (file_contents[i] == '>')
            santaloc[0 + santaIndx]++;
        else if (file_contents[i] == '^')
            santaloc[1 + santaIndx]++;
        else
            santaloc[1 + santaIndx]--;

        if (houses_visited.find({santaloc[0 + santaIndx], santaloc[1 + santaIndx]}) == houses_visited.end())
        {
            houses_visited.insert(pair<tuple<int, int>, int>({santaloc[0 + santaIndx], santaloc[1 + santaIndx]}, 1));
            numhousesvisited++;
        }
    }


    std::cout << numhousesvisited;
    return 0;
}