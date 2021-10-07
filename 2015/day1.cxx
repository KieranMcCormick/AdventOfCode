#include <iostream>
#include <fstream>
#include <sstream>

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
    int floor = 0;

    string filename("2015/day1input.txt");
    string file_contents;

    file_contents = readFileIntoString(filename);

    for (string::size_type i = 0;  i < file_contents.size(); i++ )
    {
      if (file_contents[i] == ')')
      {
          floor--;
      }
      else
      {
          floor++;
      }   
    }

    std::cout << floor;
    return 0;
}