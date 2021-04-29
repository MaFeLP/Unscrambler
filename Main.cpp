//
// Created by max on 29.04.21.
//

#include "Main.h"
#include "Colors.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "SpellChecker.h"
#include "Combinations.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;

const bool debug = true;
string words{};

static vector<string> englishWords{};

int main(const int argc, const char* argv[]) {
    std::cout << "hello world!\n" << argc << "\n" << std::endl;

    /*
    if (debug) {
        for (int i = 0; i < argc; ++i) {
            const char* arg = argv[i];

            std::cout << "Argument " << i << ": " << arg << "\n";
        }
    }

    if (argc == 1) {
        printHelpMessage();
        return 1;
    }
    */

    cout << "Please enter the word to unscramble: ";
    cin >> words;
    cout << "Now checking words \"" << Colors::DARK_GRAY << words << Colors::RESET << "\"...\n";

    cout << Colors::CYAN << ":: " << Colors::RESET << "Reading in words.txt file...\n" << Colors::RESET;

    std::ifstream wordsFile;
    wordsFile.open("../words.txt", std::ios::out);

    if (wordsFile.is_open()) {
        string line;
        while (getline(wordsFile, line)) {
            englishWords.push_back(line);
        }
    } else {
        std::cerr << "Could not open the file words.txt!";
        return 1;
    }

    cout    << Colors::GREEN << ":: " << Colors::LIGHT_GRAY << "words.txt " << Colors::RESET << "read in!\n"
            << Colors::YELLOW << ":: " << Colors::RESET << "words.txt contains "
            << Colors::EFFECT_UNDERLINED << Colors::LIGHT_GRAY << englishWords.capacity()
            << Colors::RESET_UNDERLINED << Colors::RESET << " words!"
            << "\n\n";

//    for (auto it = words.begin(); it < words.end(); ++it)
//        cout << *it;

    auto comb = new Combinations{};
    auto allCombinations = comb->allCombinations(words);

    for (auto iter = allCombinations.begin(); iter < allCombinations.end(); ++iter) {
        cout << *iter << "\n";
    }

    cout << "\n\n";

    SpellChecker::incorrectArrangement(words);

    cout << std::endl;

    return 0;
}

void printHelpMessage() {
    cout << Colors::RED << "Help message" << std::endl;
}