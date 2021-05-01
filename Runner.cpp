//
// Created by max on 29.04.21.
//

#include "Runner.h"
#include "Main.h"
#include "SpellChecker.h"
#include "github/progress_bar.hpp"
#include <vector>
#include <iostream>
#include <thread>

using std::vector;
using std::string;
using std::cout;
using std::thread;

/// Getter for the internal variable "_correct words"
std::vector<std::string> Runner::getCorrectWords() {
    return _correctWords;
}

/// The method to get all the matches from the vector "_inputWords".
void Runner::calculateWithoutProgressBar() {
    string current{};
    // iterates over each word in this vector and then checks, if it is an english word.
    for (auto iter = _inputWords.begin(); iter < _inputWords.end(); ++iter) {
        current = *iter;
        if (SpellChecker::isCorrect(current, englishWords))
            _correctWords.push_back(current);
        // Increments the counter for the progress bar.
        ++processed;
    }
    // If this method finishes, it sets its state to finished.
    _isFinished = true;
}

/// The method to get all the matches from the vector "_inputWords", but also handles printing of the progress bar.
void Runner::calculateWithProgressBar() {
    // Initializes the progress bar.
    ProgressBar pb(_maximumCombinations, "Calculating possible combinations...", cout);

    string current{};
    // iterates over each word in this vector and then checks, if it is an english word.
    for (auto iter = _inputWords.begin(); iter < _inputWords.end(); ++iter) {
        current = *iter;
        if (SpellChecker::isCorrect(current, _englishWords))
            _correctWords.push_back(current);
        // Increments the counter for the progress bar.
        ++processed;
        // Updates the progress bar
        pb.Progressed(processed);
    }
    // If this method finishes, it sets its state to finished.
    _isFinished = true;
}

/// Starts a new thread, which searches for matches of combinations and english words.
void Runner::start() {
    thread t;
    if (_maximumCombinations != 0)
        t = thread(&Runner::calculateWithProgressBar, this);
    else
        t = thread(&Runner::calculateWithoutProgressBar, this);
    t.detach();
}

/// The method, that is in infinitive loop, until the thread finishes.
void Runner::waitForFinish() const {
    while (!_isFinished) {
        // Wait for 10ms, before the next iteration, to not freak out the CPU with iterations.
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

/// The constructor, that creates a new Runner, whose thread does not handle the progress bar.
/// \param englishWords_ The dictionary of english words, read in at the start of the program.
/// \param inputWords The words this thread should cover.
Runner::Runner(const vector<string> &englishWords_, const vector<string> &inputWords) : _englishWords(
        englishWords_), _inputWords(inputWords) {
    _isFinished = false;
    _maximumCombinations = 0;
}

/// The constructor, that creates a new Runner, whose thread does handle the progress bar.
/// \param englishWords_ The dictionary of english words, read in at the start of the program.
/// \param inputWords The words this thread should cover.
/// \param maximumCombinations The maximum combinations of all words.
Runner::Runner(const vector<string> &englishWords_, const vector<string> &inputWords,
               unsigned int maximumCombinations)  : _englishWords(englishWords_), _inputWords(inputWords),
               _maximumCombinations(maximumCombinations){
    _isFinished = false;
}