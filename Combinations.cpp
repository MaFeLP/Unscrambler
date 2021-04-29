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

void Combinations::compute(const string& input, const string& result) {
    if (result.length() == _size) {
        _combinations.push_back(result);

        // cout << result << endl;
    }

    for( int i = 0; i < input.length(); i++ )
        compute(string(input).erase(i, 1), result + input[i]);
}

std::vector<std::string> Combinations::allCombinations(const string& input) {
    _size = input.length();
    compute(input,"");
    return _combinations;
}
