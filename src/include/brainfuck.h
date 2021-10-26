#include <iostream>
#include <string>
#include <cstring>
#include <cstdint>
#include <fstream>
#include <sstream>

using namespace std;

class Brainfuck {
public:
	Brainfuck(unsigned int array_size);
	void run(string brainfuckString);
private:
	unsigned int pointer;
	int* memory;
};