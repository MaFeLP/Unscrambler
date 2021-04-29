//
// Created by max on 29.04.21.
//

#include "Runner.h"
#include "Colors.h"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;

void Runner::calculate(const unsigned long start, const unsigned long end, const vector<string> &inputWords,
                       const vector<std::string> &correctWords) {

    auto _correctWords = new vector<string> {};

    if (end >= inputWords.capacity()) {
        cout << Colors::RED << "Error running calculate! The end point is bigger than the overall capacity of the combinations!";
    }

    for (ulong i = 0; i <= end; ++i) {
        string w = inputWords[i];
    }
}

bool Runner::isWord(std::string word) {


    return false;
}
