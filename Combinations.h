//
// Created by max on 29.04.21.
//

#ifndef UNSCRAMBLER_COMBINATIONS_H
#define UNSCRAMBLER_COMBINATIONS_H


#include <string>
#include <vector>

class Combinations {
    std::vector<char> _chars;
public:
    std::vector<std::string> allCombinations(std::string input);
};


#endif //UNSCRAMBLER_COMBINATIONS_H
