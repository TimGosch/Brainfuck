#include <iostream>
#include <string>
#include <cstdint>
#include <set>

using namespace std;

class Brainfuck {
public:
	Brainfuck(unsigned int array_size);
	void run(string brainfuckString);
private:
	unsigned int pointer;
	int* memory;
};