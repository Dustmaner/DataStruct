#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <assert.h>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
	//Set input
	std::string filename = "input=textcase.txt;operations=commands.txt";
	//string filename = argv[1];
	filename.erase(0, 6);

	std::string s = filename;
	std::string delimiter = "=";

	size_t pos = 0;// Get Operations.txt per node
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
	}

	string operations = s;//obtain DigitsPerNode

	std::string f = filename;//get correct filename
	std::string cutoff = ";";
	std::string file = f.substr(0, f.find(cutoff)); //correct filename 

	ifstream instream(file);//Obtain Input Stream
	ifstream opstream(s);// Obtain Operation Stream


	system("pause");
	return 0;
}
