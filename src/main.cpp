#include "include/brainfuck.h"

int main(int argc, char const* argv[]) {
	Brainfuck bf(1024);
	string helloWorld =
		"++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.+++.";
	//Print "A" to console
	string test = "++++++++++[>++++++<-]>+++++.";
	//Print the entered letter and the following 25 letters to the console
	string test2 = ">+++++[<+++++>-],.<[->+.<]";
	bf.run(test2);
	return 0;
}