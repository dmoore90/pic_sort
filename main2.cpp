#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
using namespace std;

int main()
{
    string path = "/home/r34p3r/tempdir/fromdir";
    char sep = '/';
    // for (const auto & entry : fs::directory_iterator(path)) 
    // {
    // 	cout << entry.path() << endl;
    // }
    for (const auto & entry : recursive_directory_iterator(path)) {
    	string s = (entry.path());
    	size_t i = s.rfind(sep, s.length());
   		if (i != string::npos) {
      		cout << (s.substr(i+1, s.length() - i)) << endl;
   		}
    }
    	cout << fs::current_path().filename() << endl;
}
