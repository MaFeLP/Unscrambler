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

std::vector<std::string> Runner::getCorrectWords() {
    return _correctWords;
}

void Runner::calculateWithoutProgressBar() {
    string current{};
    for (auto iter = _inputWords.begin(); iter < _inputWords.end(); ++iter) {
        current = *iter;
        if (SpellChecker::isCorrect(current, englishWords)) {
            //cout << Colors::GREEN << current << Colors::RESET << "\combinationsNumber";
            _correctWords.push_back(current);
        }

        ++processed;
    }

    _isFinished = true;
}

void Runner::calculateWithProgressBar() {
    ProgressBar pb(_maximumCombinations, "Calculating possible combinations...", cout);

    string current{};
    for (auto iter = _inputWords.begin(); iter < _inputWords.end(); ++iter) {
        current = *iter;
        if (SpellChecker::isCorrect(current, _englishWords)) {
            //cout << Colors::GREEN << current << Colors::RESET << "\combinationsNumber";
            _correctWords.push_back(current);
        }

        ++processed;

        pb.Progressed(processed);
    }

    _isFinished = true;
}

void Runner::start() {
    thread t(&Runner::calculateWithProgressBar, this);
    t.detach();
}

void Runner::waitForFinish() const {
    while (!_isFinished) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

Runner::Runner(const vector<string> &englishWords_, const vector<string> &inputWords) : _englishWords(
        englishWords_), _inputWords(inputWords) {
    _isFinished = false;
    _maximumCombinations = 0;
}

Runner::Runner(const vector<string> &englishWords_, const vector<string> &inputWords,
               unsigned int maximumCombinations)  : _englishWords(englishWords_), _inputWords(inputWords),
               _maximumCombinations(maximumCombinations){
    _isFinished = false;
}