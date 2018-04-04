#include <iostream>
#include "CoTeFo.h"

using namespace CoTeFo;

int main() {
    /* using 'generate AEC string' functions */
    // set formatting
    std::cout << CTF::gen_fmt_aec(Attribute::UNDERLINE, Colour::BRIGHT_BLUE, Colour::BRIGHT_CYAN);
    // write formatted string, reset formatting, start new line
    std::cout << "Hello, World!" << CTF::gen_rst_aec() << std::endl;
    // write un-formatted, start new line
    std::cout << "Something" <<  std::endl;

    /* using 'set' and 'reset' functions */
    // set format
    CTF::set_fmt(Attribute::BOLD, Colour::RED, Colour::BRIGHT_YELLOW);
    // write formatted
    std::cout << "Say something!...";
    // reset formatting, write un-formatted, start new line
    CTF::rst_fmt();
    std::cout << std::endl << "Anything!" << std::endl;

    return 0;
}