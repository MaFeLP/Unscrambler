//
// Created by max on 29.04.21.
//

#include "Combinations.h"
#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

/// The method used to recursively compute all possible combinations.
/// \param input The input from which to compute all combinations of.
/// \param IDK myself.
void Combinations::compute(const string& input, const string& result) {
    if (result.length() == _size) {
        _combinations.push_back(result);
    }

    for( int i = 0; i < input.length(); i++ )
        compute(string(input).erase(i, 1), result + input[i]);
}

/// Start the process of computing all combinations.
/// \param input The string from which to compute the combinations of.
/// \return A vector which holds all possible combinations.
std::vector<std::string> Combinations::allCombinations(const string& input) {
    _size = input.length();
    compute(input,"");
    return _combinations;
}
