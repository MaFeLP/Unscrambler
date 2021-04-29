//
// Created by max on 29.04.21.
//

#ifndef UNSCRAMBLER_COLORS_H
#define UNSCRAMBLER_COLORS_H

namespace Colors {
    // Resets the colors to the terminal defaults.
    const static auto RESET = "\033[0;0m";
    const static auto RESET_BOLD = "\033[0;1m";
    const static auto RESET_DIM = "\033[0;2m";
    const static auto RESET_UNDERLINED = "\033[0;4m";
    const static auto RESET_BLINK = "\033[0;5m";
    const static auto RESET_REVERSE = "\033[0;7m";
    const static auto RESET_HIDDEN = "\033[0;8m";

    // normal text colors
    const static auto BLACK = "\033[0;30m";
    const static auto RED = "\033[0;31m";
    const static auto GREEN = "\033[0;32m";
    const static auto YELLOW = "\033[0;33m";
    const static auto BLUE = "\033[0;34m";
    const static auto MAGENTA = "\033[0;35m";
    const static auto CYAN = "\033[0;36m";
    const static auto LIGHT_GRAY = "\033[0;37m";
    const static auto DARK_GRAY = "\033[0;90m";
    const static auto LIGHT_RED = "\033[0;91m";
    const static auto LIGHT_GREEN = "\033[0;92m";
    const static auto LIGHT_YELLOW = "\033[0;93m";
    const static auto LIGHT_BLUE = "\033[0;94m";
    const static auto LIGHT_MAGENTA = "\033[0;95m";
    const static auto LIGHT_CYAN = "\033[0;96m";
    const static auto WHITE = "\033[0;97m";

    // Background colors
    const static auto BACKGROUND_DEFAULT = "\033m0;49mm";
    const static auto BACKGROUND_BLACK = "\033[0;40m";
    const static auto BACKGROUND_RED = "\033[0;41m";
    const static auto BACKGROUND_GREEN = "\033[0;42m";
    const static auto BACKGROUND_YELLOW = "\033[0;43m";
    const static auto BACKGROUND_BLUE = "\033[0;44m";
    const static auto BACKGROUND_MAGENTA = "\033[0;45m";
    const static auto BACKGROUND_CYAN = "\033[0;46m";
    const static auto BACKGROUND_LIGHT_GRAY = "\033[0;47m";
    const static auto BACKGROUND_DARK_GRAY = "\033[0;100m";
    const static auto BACKGROUND_LIGHT_RED = "\033[0;101m";
    const static auto BACKGROUND_LIGHT_GREEN = "\033[0;102m";
    const static auto BACKGROUND_LIGHT_YELLOW = "\033[0;103m";
    const static auto BACKGROUND_LIGHT_BLUE = "\033[0;104m";
    const static auto BACKGROUND_LIGHT_MAGENTA = "\033[0;105m";
    const static auto BACKGROUND_LIGHT_CYAN = "\033[0;106m";
    const static auto BACKGROUND_WHITE = "\033[0;107m";

    // Effects
    const static auto EFFECT_BOLD = "\033[0;1m";
    const static auto EFFECT_DIM = "\033[0;2m";
    const static auto EFFECT_UNDERLINED = "\033[0;4m";
    const static auto EFFECT_BLINK = "\033[0;5m";
    const static auto EFFECT_REVERSE = "\033[0;7m";
    const static auto EFFECT_HIDDEN = "\033[0;8m";
}

#endif //UNSCRAMBLER_COLORS_H
