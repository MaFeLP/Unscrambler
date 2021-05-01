//
// Created by max on 29.04.21.
//

#include "Main.h"
#include "Colors.h"
#include "Runner.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <atomic>
#include "SpellChecker.h"
#include "Combinations.h"
#include "github/progress_bar.hpp"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::thread;

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

            std::cout << "Argument " << i << ": " << arg << "\combinationsNumber";
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


    cout    << Colors::GREEN << ":: " << Colors::LIGHT_GRAY << "words.txt " << Colors::RESET << "read in!\n"
            << Colors::YELLOW << ":: " << Colors::RESET << "words.txt contains "
            << Colors::EFFECT_UNDERLINED << Colors::LIGHT_GRAY << englishWords.capacity()
            << Colors::RESET_UNDERLINED << Colors::RESET << " words!"
            << "\n\n"
            << "Please enter the number of threads to work with: ";

    int numberOfThreads = 0;
    cin >> numberOfThreads;

    cout    << "\n"
            << Colors::YELLOW << ":: " << Colors::RESET << "Using "
            << Colors::LIGHT_GRAY << numberOfThreads
            << Colors::RESET << " threads."
            << "\n\n";

//    for (auto it = scrambled_word.begin(); it < scrambled_word.end(); ++it)
//        cout << *it;

    auto combinations = new Combinations{};
    auto allCombinations = combinations->allCombinations(Variables::scrambledWord);

    // Initialises the progress bar.
    int combinationsNumber = allCombinations.size();

    processed = 0;


    cout << "\n\n";

    //SpellChecker::incorrectArrangement(scrambled_word);

    int wordsPerThread = combinationsNumber / numberOfThreads;

    if (wordsPerThread == 0) {
        numberOfThreads = 0;
        wordsPerThread = combinationsNumber;
    }

    /*
    auto currentWord = allCombinations.begin();

    vector<thread> _threads;
    for (int i = 0; i < numberOfThreads; ++i) {
        vector<string> parameter{};

        for (int ii = 0; ii < (i + 1) * numberOfThreads; ++ii) {
            parameter.push_back(*currentWord);
            ++currentWord;
        }

        thread t(Runner::calculateWithoutProgressBar, parameter);
        t.join();
    } */

    vector<Runner *> runners{};

    for (int i = 0; i < numberOfThreads; ++i) {
        vector<string> wordsCombinations{allCombinations.begin(), allCombinations.begin() + ((i + 1) * (wordsPerThread))};
        auto *runner = new Runner(englishWords, wordsCombinations, combinationsNumber);
        runner->start();

        runners.push_back(runner);
    }

    vector<string> correctEnglishWordFromScrambled{};
    for (auto runnerItem = runners.begin(); runnerItem < runners.end(); ++runnerItem) {
        auto r = *runnerItem;
        r->waitForFinish();

        auto correctWordsFromThread = r->getCorrectWords();
        for (auto wordItem = correctWordsFromThread.begin(); wordItem < correctWordsFromThread.end(); ++wordItem) {
            correctEnglishWordFromScrambled.push_back(*wordItem);
        }
    }

    cout << Colors::GREEN
         << "\n\n";
    for (auto item = correctEnglishWordFromScrambled.begin(); item < correctEnglishWordFromScrambled.end(); ++item) {
        cout << *item;

        if (item != correctEnglishWordFromScrambled.end() - 1) {
            cout << "; ";
        }
    }

    cout << std::endl;

    return 0;
}

void printHelpMessage() {
    cout << Colors::RED << "Help message" << std::endl;
}