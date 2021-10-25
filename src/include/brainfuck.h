#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class Brainfuck {
public:
	Brainfuck(unsigned int array_size);
	string decode(string brainfuckString);
	string encode(string asciiString);
	void workSubstring(string subString);
	void init();
private:
	unsigned int pointer;
	unsigned int array_size;
	vector<int> memory;
};