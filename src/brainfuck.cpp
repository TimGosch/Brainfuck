#include "include/brainfuck.h"

Brainfuck::Brainfuck(unsigned int array_size) {
	//Initialise Object with default params to avoid unpredictable behavior.
	pointer = 0;
	//Initialize Memory Array with all 0.
	this->memory = new int[array_size] {};
}

void Brainfuck::run(string brainfuckString) {
	string returnString = "";
	//Input and output char
	char out = 0;
	char in = 0;
	// run over brainfuck code
	for (size_t i = 0; i < brainfuckString.length(); i++) {
		switch (brainfuckString[i]) {
		case '>':
			pointer++;
			break;
		case '<':
			pointer--;
			break;
		case '+':
			memory[pointer]++;
			break;
		case '-':
			memory[pointer]--;
			break;
		case '.':
			out = memory[pointer];
			cout << out;
			break;
		case ',':
			cout << "Enter Letter: ";
			cin >> in;
			memory[pointer] = in;
			break;
		case '[':
			if (memory[pointer] == 0) {
				//find matching closing bracket
				//Set counter and Step to 1 to start with the symbol behind the opening bracket
				int counter = 1;
				int step = 1;
				while (counter > 0) {
					if (brainfuckString[i+ step] == ']') {
						counter--;
					}
					else if (brainfuckString[i + step] == '[') {
						counter++;
					}
					step++;
				}
				//Set Pointer to new Position
				i += step;
			}
			break;
		case ']':
			if (memory[pointer] > 0) {
				int counter = 1;
				int step = 1;
				while (counter > 0) {
					if (brainfuckString[i - step] == '[') {
						counter--;
					}
					else if (brainfuckString[i - step] == ']') {
						counter++;
					}
					if (counter > 0) {
						step++;
					}
				}
				i -= step;
			}
			break;
		default:
			break;
		}
	}
}
