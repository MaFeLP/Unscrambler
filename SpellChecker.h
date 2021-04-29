//
// Created by max on 29.04.21.
//
// Function check is self written.
//
// Used from GitHub at: https://github.com/LordHypersonic/C-Spell-Checker/blob/master/Spell%20Checker/spell_checker.cpp
//
/*
Program: spell checker
Description: It is a spell checker program. It checks if the spelling of entered word is right or wrong. I spelling is wrong it give suggestions of correct spellings.
Author: Lord Hypersonic
Email: lordhypersonic.522@gmail.com
Website: www.lordhypersonic.blogspot.com
*/
#ifndef UNSCRAMBLER_SPELLCHECKER_H
#include <string>
#include <vector>

#define UNSCRAMBLER_SPELLCHECKER_H


class SpellChecker {
public:
    static int incorrectArrangement(std::string input);
    static int exchangedCharacters (std::string input);

    static int missingCharacter(std::string input);

    static int extraCharacter(std::string input);

    static int mixedExtraMissing(std::string input);

    static bool isCorrect(const std::string &word, const std::vector<std::string> &dict);
};


#endif //UNSCRAMBLER_SPELLCHECKER_H
