//
// Created by max on 29.04.21.
//

#ifndef UNSCRAMBLER_MAIN_H
#include <string>
#include <vector>
#include <atomic>
#define UNSCRAMBLER_MAIN_H

// Main Method
int main(int argc, const char* argv[]);
// The vector which contains all english words, from the "words.txt" file.
// They are being read in, after the user typed his/her word to search for.
static std::vector<std::string> englishWords{};
// The variable that stores the current process of the program, when searching for matches.
static std::atomic<unsigned long> processed;

// Namespace only made for this one variable because of a linker error.
namespace Variables {
    // The variable that stores the inputted word.
    static std::string scrambledWord{};
}

#endif //UNSCRAMBLER_MAIN_H