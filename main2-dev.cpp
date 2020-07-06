#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;
using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
using namespace std;

int main()
{
    string path = "/home/r34p3r/tempdir/fromdir";
    char sep = '/';
    vector<string> filenames;
    string folder_name;
    folder_name = fs::current_path().filename();
    for (const auto & entry : recursive_directory_iterator(path)) {
    	string s = (entry.path());
    	size_t i = s.rfind(sep, s.length());
   		if (i != string::npos) {
      		filenames.push_back(s.substr(i+1, s.length() - i));
   		}
    }
    string new_path = "/home/r34p3r/tempdir";
    for (const auto & i : filenames) {
      string command_mkdir = "mkdir " + new_path + "/" + i;
      system(command_mkdir.c_str());

      string command_mv = "cp " + path + "/" + i + " " + new_path + "/" + i + "/";
      system(command_mv.c_str());  
    }

}
