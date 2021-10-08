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
    int x = 0;
    int y = 0;
    int numhousesvisited = 0;

    for (string::size_type i = 0;  i < file_contents.size(); i++ )
    {
        if (file_contents[i] == '<')
            x--;
        else if (file_contents[i] == '>')
            x++;
        else if (file_contents[i] == '^')
            y++;
        else
            y--;

        if (houses_visited.find({x, y}) == houses_visited.end())
        {
            houses_visited.insert(pair<tuple<int, int>, int>({x, y}, 1));
            numhousesvisited++;
        }
    }


    std::cout << numhousesvisited;
    return 0;
}