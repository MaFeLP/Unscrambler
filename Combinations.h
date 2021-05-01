//
// Created by max on 29.04.21.
//

#ifndef UNSCRAMBLER_COMBINATIONS_H
#define UNSCRAMBLER_COMBINATIONS_H


#include <string>
#include <vector>

class Combinations {
    /// All the combinations found by the algorithm
    std::vector<std::string> _combinations;
    /// The size of the inputted string.
    unsigned _size;
    void compute(const std::string &input, const std::string &result);
public:
    std::vector<std::string> allCombinations(const std::string&);
};


#endif //UNSCRAMBLER_COMBINATIONS_H
