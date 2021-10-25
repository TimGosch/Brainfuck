#include "include/brainfuck.h"

int main(int argc, char const *argv[]) {
    Brainfuck bf(1024);
    string testString =
        "+[++[>++<]++]+++";
    std::string lol = bf.decode(testString);
    cout << lol << endl;
    return 0;
}