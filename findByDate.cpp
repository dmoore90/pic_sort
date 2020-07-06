#include <iostream>
#include <fstream>

using namespace std;

int main() {
	string command = "find ~/Pictures -newerct \"2020-01-15 00:00:00\" -not -newerct \"2020-01-19 00:00:00+1\" > ~/env_c++/pic_sort/tempfile.txt";
	system(command.c_str());
	ifstream infile("tempfile.txt");

}