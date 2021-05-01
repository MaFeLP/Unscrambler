//
// Created by max on 29.04.21.
//

#include "SpellChecker.h"
#include "Main.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

/// Iterates over each word in the dictionary (second parameter) and checks, if the word
/// (first parameter) is in it. If not, return false.
/// \param word The word to search in the dictionary
/// \param dict The dictionary to find the word in.
bool SpellChecker::isCorrect(const string& word, const vector<string> &dict) {
    for (auto iter = dict.begin(); iter < dict.end(); ++iter) {
        if (word == *iter) {
            return true;
        }
    }

    return false;
}