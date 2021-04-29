//
// Created by max on 29.04.21.
//

#ifndef UNSCRAMBLER_RUNNER_H
#include <thread>
#include <vector>

#define UNSCRAMBLER_RUNNER_H


class Runner {
    static void calculate(unsigned long start, unsigned long end, const std::vector<std::string>& inputWords, const std::vector<std::string>& correctWords);

    static bool isWord(std::string word);
};

#endif //UNSCRAMBLER_RUNNER_H
