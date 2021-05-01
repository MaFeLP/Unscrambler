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
    bool _isFinished;

    std::vector<std::string> _englishWords;

    std::vector<std::string> _correctWords;

    std::vector<std::string> _inputWords;

    unsigned int _maximumCombinations{};

    std::thread _runningThread;
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
