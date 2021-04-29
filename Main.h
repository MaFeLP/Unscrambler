//
// Created by max on 29.04.21.
//

#ifndef UNSCRAMBLER_MAIN_H
#include <string>
#include <vector>
#define UNSCRAMBLER_MAIN_H

int main(int argc, const char* argv[]);
void printHelpMessage();

static std::vector<std::string> englishWords{};

namespace Variables {
    const bool debug = true;
    static std::string scrambledWord{};

    static unsigned terminalRows = 232;
    static unsigned terminalColumns = 13;
}

#endif //UNSCRAMBLER_MAIN_H
