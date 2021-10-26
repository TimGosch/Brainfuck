#include "include/brainfuck.h"

string usageString =
"===========================================\n\n"
"Usage:										\n"
" ./brainfuck								\n"
"											\n"
"	OR										\n"
"											\n"
" ./brainfuck -e <brainfuck String>			\n"
"											\n"
"	OR										\n"
"											\n"
" ./brainfuck -f <file name>				\n"
"=============================================";

int main(int argc, char const* argv[]) {
	Brainfuck bf(1024);
	string workString = "";
	//If no further arguments are provided, ask the user to input a BF String
	if (argc == 1) {
		cout << "Enter a Brainfuck String:" << endl;
		cin >> workString;
	}
	else if (argc == 2 && strcmp(argv[1],"-h")) {
		cout << usageString << endl;
	}//If a flag is set
	else if (argc == 3) {
		//Check for -e or -f flag
		if (strcmp(argv[1], "-e") == 0) {
			//set argv2 as workString
			workString = argv[2];
		}
		else if (strcmp(argv[1], "-f") == 0) {
			//read content from file
			std::ifstream file(argv[2]);
			std::stringstream buffer;
			buffer << file.rdbuf();
			workString = buffer.str();
		}
	}
	else {
		//Print usage explaination.
		cout << usageString << endl;
	}

	//evaluate workString
	if (workString != "") {
		bf.run(workString);
	}
	return 0;
}