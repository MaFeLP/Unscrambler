//
// Created by max on 29.04.21.
//

#include "Main.h"
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

int main(const int argc, const char* argv[]) {
    std::cout << "hello world!\n" << argc << "\n" << std::endl;

    for (int i = 0; i <= argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << "\n";
    }

    return 0;
}
