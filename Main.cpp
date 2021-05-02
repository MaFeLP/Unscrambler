//
// Created by max on 29.04.21.
//

#include "Main.h"
#include "Colors.h"
#include "Runner.h"
#include "SpellChecker.h"
#include "Combinations.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <thread>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::thread;

int main(const int argc, const char* argv[]) {
    // Ask the user for the word to unscramble.
    cout << "Please enter the word to unscramble: ";
    cin >> Variables::scrambledWord;
    cout << Colors::CYAN << ":: " << Colors::RESET << Colors::EFFECT_BOLD << "Now checking word combinations for \""
         << Colors::DARK_GRAY << Variables::scrambledWord << Colors::RESET << Colors::EFFECT_BOLD << "\"...\n";

    cout << Colors::CYAN << ":: " << Colors::RESET << Colors::EFFECT_BOLD << "Reading in words.txt file...\n" << Colors::RESET;

    // Read the file words.txt in to the vector "english words".
    std::ifstream wordsFile;
    // Change the commenting of the next two lines, when developing in CLion.
    wordsFile.open("./words.txt", std::ios::out);
    // wordsFile.open("../words.txt", std::ios::out);
    if (wordsFile.is_open()) {
        string line;
        while (getline(wordsFile, line)) {
            englishWords.push_back(line);
        }
    } else {
        std::cerr << "FileError: Could not open the file scrambled_word.txt!";
        return 1;
    }

    // Display information about the words in the vector "english words".
    cout    << Colors::GREEN << ":: " << Colors::LIGHT_GRAY << "words.txt " << Colors::RESET << "read in!\n"
            << Colors::YELLOW << ":: " << Colors::RESET << "words.txt contains "
            << Colors::EFFECT_UNDERLINED << Colors::LIGHT_GRAY << englishWords.capacity()
            << Colors::RESET_UNDERLINED << Colors::RESET << " words!"
            << "\n"
            << "Please enter the number of threads to work with: ";

    // Ask the user for the number of threads he/she wants to use: currently not available!
    int numberOfThreads = 1;
    cin >> numberOfThreads;
    cout    << "\n"
            << Colors::YELLOW << ":: " << Colors::RESET << "Using "
            << Colors::LIGHT_GRAY << numberOfThreads
            << Colors::RESET << " threads."
            << "\n\n";

    // Creates all possible combinations.
    auto combinations = new Combinations{};
    auto allCombinations = combinations->allCombinations(Variables::scrambledWord);

    // Initialises the progress bar, used in the runner class.
    int combinationsNumber = allCombinations.size();
    processed = 0;

    // does some preparation work for the splitting of work in the threads.
    int wordsPerThread = combinationsNumber / numberOfThreads;
    if (wordsPerThread == 0) {
        numberOfThreads = 0;
        wordsPerThread = combinationsNumber;
    }

    // Initializes and starts the threads.
    vector<Runner *> runners{};
    if (numberOfThreads <= 1) {
        // Creates a runner with this list (handles the threads).
        auto *runner = new Runner(englishWords, allCombinations, combinationsNumber, 1);
        // Start the prepared thread.
        runner->start();
        // Add this thread to the vector of thread pointers.
        runners.push_back(runner);
    } else {
        auto wordStart = allCombinations.begin();
        auto wordEnd = wordStart + wordsPerThread;
        auto wordStartInt = 0;
        auto wordEndInt = wordStartInt + wordsPerThread;
        for (int threadNumber = 1; threadNumber <= numberOfThreads; ++threadNumber) {
            if (threadNumber == 1) {
                // Creates a sublist of combinations of the words, each individual thread should handle.
                vector<string> wordsCombinations{allCombinations.begin(), wordEnd};
                // Creates a runner with this list (handles the threads).
                auto *runner = new Runner(englishWords, wordsCombinations, combinationsNumber, numberOfThreads);
                // Start the prepared thread.
                runner->start();
                // Add this thread to the vector of thread pointers.
                runners.push_back(runner);

                wordStart += wordsPerThread;
                wordEnd += wordsPerThread;
                wordStartInt += wordsPerThread;
                wordEndInt += wordsPerThread;
            } else if (threadNumber == numberOfThreads) {
                // Creates a sublist of combinations of the words, each individual thread should handle.
                vector<string> wordsCombinations{wordStart, allCombinations.end()};
                // Creates a runner with this list (handles the threads).
                auto *runner = new Runner(englishWords, wordsCombinations);
                // Start the prepared thread.
                runner->start();
                // Add this thread to the vector of thread pointers.
                runners.push_back(runner);
            } else {
                // Creates a sublist of combinations of the words, each individual thread should handle.
                vector<string> wordsCombinations{wordStart, wordEnd};
                // Creates a runner with this list (handles the threads).
                auto *runner = new Runner(englishWords, wordsCombinations);
                // Start the prepared thread.
                runner->start();
                // Add this thread to the vector of thread pointers.
                runners.push_back(runner);

                wordStart += wordsPerThread;
                wordEnd += wordsPerThread;
                wordStartInt += wordsPerThread;
                wordEndInt += wordsPerThread;
            }
        }
    }

    // Initializes the vector of correct english words, each thread has gathered.
    vector<string> correctEnglishWordFromScrambled{};
    // Wait for all threads to finish.
    for (auto runnerItem = runners.begin(); runnerItem < runners.end(); ++runnerItem) {
        // Waits for the current thread to finish.
        auto r = *runnerItem;
        r->waitForFinish();
        // When the thread has finished, get all its correct words and add them to the list of correct words.
        auto correctWordsFromThread = r->getCorrectWords();
        for (auto wordItem = correctWordsFromThread.begin(); wordItem < correctWordsFromThread.end(); ++wordItem) {
            correctEnglishWordFromScrambled.push_back(*wordItem);
        }
    }

    // Print the results
    cout << "\n"
         << Colors::GREEN << ":: " << Colors::RESET
         << Colors::EFFECT_BOLD << "Done!" << Colors::RESET_BOLD << "\n"
         << Colors::GREEN << ":: " << Colors::RESET
         << Colors::EFFECT_BOLD << "All possible matches found!" << Colors::RESET_BOLD
         << "\n";
    for (auto item = correctEnglishWordFromScrambled.begin(); item < correctEnglishWordFromScrambled.end(); ++item) {
        cout << Colors::LIGHT_BLUE << *item << Colors::RESET;
        // If the item is not the last in its line, print a semicolon.
        if (item != correctEnglishWordFromScrambled.end() - 1) {
            cout << "; ";
        }
    }

    cout << "\n"
         << Colors::GREEN << ":: " << Colors::RESET
         << Colors::EFFECT_BOLD << "Exiting" << Colors::EFFECT_BLINK <<  "...\n" << Colors::RESET_BOLD << Colors::RESET_BLINK
         << Colors::LIGHT_GRAY << "Unscrambler made by MaFeLP (https://mafelp.githu.io/)!"
                               << "\nThanks for using it!"
         << Colors::RESET
         << std::endl;

    return 0;
}