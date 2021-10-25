#include "include/brainfuck.h"

Brainfuck::Brainfuck(unsigned int array_size) {
	init();
	this->array_size = array_size;
	// initialize output array with all 0
	for (unsigned int i = 0; i < this->array_size; i++) {
		memory.push_back(0);
	}
}

/*
 * Initialise Object with default params to avoid unpredictable behavior.
 */
void Brainfuck::init() {
	pointer = 0;
	array_size = 0;
	memory.clear();
}

string Brainfuck::decode(string brainfuckString) {
	string returnString = "";

	// run over brainfuck code
	for (size_t i = 0; i < brainfuckString.length(); i++) {
		char c;
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
			c = memory[pointer];
			returnString.push_back(c);
			break;
		case ',':
			// TODO: Implement
			break;
		case '[':
			if (memory[pointer] != 0) {
				int counter = 1;
				int step = 1;
				while (counter > 0) {
					if (brainfuckString[i + step] == ']') {
						counter--;
					}
					else if (brainfuckString[i + step] == '[') {
						counter++;
					}if (counter != 0) {
						step++;
					}
					else {
						step--;
					}
				}
				//Create Substring 
				string sub = brainfuckString.substr(i + 1, step);
				//TODO: Recursively call decode on substring
				continue;
			}
			else {
				//TODO Implement skip over loop
			}
			break;
		case ']':
			break;
		default:
			break;
		}
	}
	return returnString;
}
string Brainfuck::encode(string asciiString) {
	string returnString = "";
	return returnString;
}

void Brainfuck::workSubstring(string substring) {

}