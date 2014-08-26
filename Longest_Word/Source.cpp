#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::istringstream;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line, word, longest_word;
	// Get a line from input file
	while (getline(ifs, line))
	{
		istringstream iss(line);
		// Cycle through each word in line and determine longest word
		while (iss >> word)
		{
			if (word.size() > longest_word.size())
			{
				longest_word = word;
			}
		}
		cout << longest_word << endl;
		// Clear out longest_word for next line
		longest_word.clear();
	}

	return 0;
}