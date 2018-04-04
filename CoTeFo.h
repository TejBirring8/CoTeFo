//
//
// * Console Text Formatting *
// Copyright(C) 2018 by Gurtej Singh Birring. All Rights Reserved.
//
//
// USAGE: First, import this header file at the top of your source file.
//        Then, there are 4 functions for you to use:
//          (1) gen_fmt_aec   (attribute, background_colour, foreground_colour)
//          (2) gen_rst_aec   ()
//          (3) set_fmt       (attribute, background_colour, foreground_colour)
//          (4) rst_fmt       ()
//
//
// EXAMPLE: see 'main.cpp'
//
//

#include <string>
#include <iostream>
#ifndef CONSOLE_TEXT_FORMATTING_H
#define CONSOLE_TEXT_FORMATTING_H

namespace CoTeFo
{
    /* The attribute options available to the user */
    enum class Attribute {RESET, BOLD, DIM, UNDERLINE,
                          BLINK, REVERSE, HIDDEN};

    /* The colour options available to the user */
    enum class Colour {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
                       BRIGHT_BLACK, BRIGHT_RED, BRIGHT_GREEN, BRIGHT_YELLOW,
                       BRIGHT_BLUE, BRIGHT_MAGENTA, BRIGHT_CYAN, BRIGHT_WHITE,
                       DEFAULT};

    /* This static class is the  public interface to all Console Text Formatting (CTF) functions */
    class CTF
    {
    private:
        /* This static sub-class hides all details from the user */
        class Hdn {
            friend class CTF;   // allows parent class' functions to access Hdn's members

            /* Linux terminal ANSI Escape Code (AEC) components */
            static constexpr const char* _start   = "\e[";
            static constexpr const char* _end     = "m";
            static constexpr const char* _attributes[] = { "0", "1", "2", "4", "5", "7", "8" };
            static constexpr const char* _foreground_clr[] =
                    { "30" , "31" , "32" , "33" , "34" , "35" , "36" , "37" ,
                      "90" , "91" , "92" , "93" , "94" , "95" , "96" , "97" , "39"
                    };
            static constexpr const char* _background_clr[] =
                    { "40" , "41" , "42", "43" , "44" , "45" , "46" , "47" ,
                      "100" , "101" , "102" , "103" , "104" , "105" , "106" , "107" , "49"
                    };

            /* Fetches correct 'attribute' AEC component based on parameter */
            static std::string _get_attribute(const Attribute& a)
            {
                switch (a) {
                    case Attribute:: RESET:
                        return _attributes[0];
                    case Attribute:: BOLD:
                        return _attributes[1];
                    case Attribute:: DIM:
                        return _attributes[2];
                    case Attribute:: UNDERLINE:
                        return _attributes[3];
                    case Attribute:: BLINK:
                        return _attributes[4];
                    case Attribute:: REVERSE:
                        return _attributes[5];
                    case Attribute:: HIDDEN:
                        return _attributes[6];
                }
            }

            /* Fetches correct 'colour' AEC component based on parameters */
            static std::string _get_colour(const Colour& c, const bool&& bg)
            {
                switch (c) {
                    case Colour:: BLACK:
                        return (bg ? _background_clr[0] : _foreground_clr[0]);
                    case Colour:: RED:
                        return (bg ? _background_clr[1] : _foreground_clr[1]);
                    case Colour:: GREEN:
                        return (bg ? _background_clr[2] : _foreground_clr[2]);
                    case Colour:: YELLOW:
                        return (bg ? _background_clr[3] : _foreground_clr[3]);
                    case Colour:: BLUE:
                        return (bg ? _background_clr[4] : _foreground_clr[4]);
                    case Colour:: MAGENTA:
                        return (bg ? _background_clr[5] : _foreground_clr[5]);
                    case Colour:: CYAN:
                        return (bg ? _background_clr[6] : _foreground_clr[6]);
                    case Colour:: WHITE:
                        return (bg ? _background_clr[7] : _foreground_clr[7]);
                    case Colour:: BRIGHT_BLACK:
                        return (bg ? _background_clr[8] : _foreground_clr[8]);
                    case Colour:: BRIGHT_RED:
                        return (bg ? _background_clr[9] : _foreground_clr[9]);
                    case Colour:: BRIGHT_GREEN:
                        return (bg ? _background_clr[10] : _foreground_clr[10]);
                    case Colour:: BRIGHT_YELLOW:
                        return (bg ? _background_clr[11] : _foreground_clr[11]);
                    case Colour:: BRIGHT_BLUE:
                        return (bg ? _background_clr[12] : _foreground_clr[12]);
                    case Colour:: BRIGHT_MAGENTA:
                        return (bg ? _background_clr[13] : _foreground_clr[13]);
                    case Colour:: BRIGHT_CYAN:
                        return (bg ? _background_clr[14] : _foreground_clr[14]);
                    case Colour:: BRIGHT_WHITE:
                        return (bg ? _background_clr[15] : _foreground_clr[15]);
                    case Colour:: DEFAULT:
                        return (bg ? _background_clr[16] : _foreground_clr[16]);
                }
            }
        }; //class Hdn

    /* THESE ARE THE FUNCTIONS FOR THE USER (API) */
    public:
        /* generates AEC as per specified parameters */
        static std::string gen_fmt_aec (const Attribute& a,
                               const Colour& background,
                               const Colour& foreground)
        {
            return (Hdn::_start
                    + Hdn::_get_attribute(a)
                    + ";" + Hdn::_get_colour(foreground, false)
                    + ";" + Hdn::_get_colour(background, true)
                    + Hdn::_end);
        }

        /* generates AEC to reset any formatting set previously */
        static std::string gen_rst_aec()
        {
            return (std::string(Hdn::_start) + "0" + Hdn::_end);
        }

        /* sets the terminal formatting as per specified parameters */
        static void set_fmt (const Attribute& a,
                             const Colour& background,
                             const Colour& foreground)
        {
            std::cout << gen_fmt_aec ( a, background, foreground );
        }

        /* resets terminal formatting */
        static void rst_fmt ()
        {
            std::cout << gen_rst_aec();
        }
    };
}
#endif //CONSOLE_TEXT_FORMATTING_H
