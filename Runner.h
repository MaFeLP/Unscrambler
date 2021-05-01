//
// Created by max on 29.04.21.
//

#ifndef UNSCRAMBLER_RUNNER_H
#include <vector>
#include <string>
#include <thread>
#include <pthread.h>
#define UNSCRAMBLER_RUNNER_H

class Runner {
    /// The status of the thread and if it is running.
    bool _isFinished;
    /// The dictionary of english words.
    std::vector<std::string> _englishWords;
    /// The matches the thread found in the input words, that are an english word.
    std::vector<std::string> _correctWords;
    /// The words in which to find english words.
    std::vector<std::string> _inputWords;
    /// The maximum amount of combinations that the progress bar should display.
    /// Is 0, if the thread does not handle a progress bar.
    unsigned int _maximumCombinations{};
public:
    void calculateWithProgressBar();

    void calculateWithoutProgressBar();

    std::vector<std::string> getCorrectWords();

    void start();

    void waitForFinish() const;

    explicit Runner(const std::vector<std::string> &englishWords_, const std::vector<std::string> &inputWords);

    explicit Runner(const std::vector<std::string> &englishWords, const std::vector<std::string> &inputWords,
           unsigned int maximumCombinations);
};

#endif //UNSCRAMBLER_RUNNER_H
