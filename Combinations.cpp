//
// Created by max on 29.04.21.
//

#include "Combinations.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

vector<string> Combinations::allCombinations(const string input) {
    vector<string> out{};

    for (auto iter = input.begin(); iter < input.end(); ++iter) {
        _chars.push_back(*iter);

    }

    for (auto iter = _chars.begin(); iter < _chars.end(); ++iter) {
        vector<char> i = _chars;
        i.erase(iter);

        string next{};

        for (auto iter2 = i.begin(); iter2 < i.end(); ++iter2) {
            next.push_back(*iter2);
        }

        auto comb = new Combinations{};
        auto insertable = comb->allCombinations(next);
        out.insert(out.end(), insertable.begin(), insertable.end());
    }

    return out;
}