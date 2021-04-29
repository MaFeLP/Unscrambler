//
// Created by max on 29.04.21.
//

#include "Main.h"
#include "Colors.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "SpellChecker.h"
#include "Combinations.h"
#include "github/progress_bar.hpp"

using std::cout;
using std::cin;
using std::string;
using std::vector;


void progress(const unsigned long &current, const unsigned &maximum, const string& label) {
    // "[] 99.99% "

    string maximumNumberLenght{&"" [ maximum]};
    int asdfasdf = maximumNumberLenght.length();

    unsigned pl = Variables::terminalColumns / 2 - 9;
    cout << "\r"
         << "(";

    for (int i = 0; i < maximum - current; ++i) {
        cout << " ";
    }

    cout << current << "/" << maximum << ")";

    for (int i = 0; i < (Variables::terminalColumns - 16 + (6 - 2 * (asdfasdf))); ++i) {
        cout << " ";
    }

    cout << "[";
}


int main(const int argc, const char* argv[]) {
    struct winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    std::cout << "cols: " << w.ws_col << "; rows: " << w.ws_row << std::endl;

    Variables::terminalColumns = w.ws_col;
    Variables::terminalRows = w.ws_row;

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
    cin >> Variables::scrambledWord;
    cout << Colors::CYAN << Colors::RESET << Colors::EFFECT_BOLD << "Now checking word combinations for \""
         << Colors::DARK_GRAY << Variables::scrambledWord << Colors::RESET << Colors::EFFECT_BOLD << "\"...\n";

    cout << Colors::CYAN << ":: " << Colors::RESET << Colors::EFFECT_BOLD << "Reading in words.txt file...\n" << Colors::RESET;

    std::ifstream wordsFile;
    wordsFile.open("../words.txt", std::ios::out);

    if (wordsFile.is_open()) {
        string line;
        while (getline(wordsFile, line)) {
            englishWords.push_back(line);
        }
    } else {
        std::cerr << "FileError: Could not open the file scrambled_word.txt!";
        return 1;
    }

    auto asdf = englishWords;

    cout    << Colors::GREEN << ":: " << Colors::LIGHT_GRAY << "words.txt " << Colors::RESET << "read in!\n"
            << Colors::YELLOW << ":: " << Colors::RESET << "words.txt contains "
            << Colors::EFFECT_UNDERLINED << Colors::LIGHT_GRAY << englishWords.capacity()
            << Colors::RESET_UNDERLINED << Colors::RESET << " words!"
            << "\n\n";

//    for (auto it = scrambled_word.begin(); it < scrambled_word.end(); ++it)
//        cout << *it;

    vector<string> checkedWords{};

    auto combinations = new Combinations{};
    auto allCombinations = combinations->allCombinations(Variables::scrambledWord);

    // Initialises the progress bar.
    int n = allCombinations.size();
    ProgressBar progress_bar(n, "Calculating possible combinations...");

    unsigned long jobIndex = 0;
    string current{};
    for (auto iter = allCombinations.begin(); iter < allCombinations.end(); ++iter) {
        current = *iter;
        if (SpellChecker::isCorrect(current, englishWords)) {
            //cout << Colors::GREEN << current << Colors::RESET << "\n";
            checkedWords.push_back(current);
        }

        progress_bar.Progressed(jobIndex);
        //progress(i, allCombinations.size(), "adsf");

        ++jobIndex;
    }

    cout << "\n\n";

    //SpellChecker::incorrectArrangement(scrambled_word);

    cout << Colors::GREEN;
    for (auto iter = checkedWords.begin(); iter < checkedWords.end(); ++iter) {
        cout << *iter << "; ";
    }

    cout << std::endl;

    return 0;
}

void printHelpMessage() {
    cout << Colors::RED << "Help message" << std::endl;
}


/*
 * def progress(i, max, string):
    width, height = os.get_terminal_size()
    pl=round(math.log(width/57 ,1.01644658))
    string=' '+string+200*' '
    print('\r('+(len(str(max))-len(str(i)))*' '+str(i)+
    '/'+str(max)+')'

    +string[:width-16+(6-2*len(str(max)))-pl]+
    '['+round((i/max)*pl)*'#'+(pl-round((i/max)*pl))*'-'+']
     '+(3-len(str(round((i/max)*100))))*' '+str(round((i/max)*100))+'%', end='', flush=True)
 */