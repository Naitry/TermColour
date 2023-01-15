//!
//! TermColour
//! ~~~~~~~~~
//!
//!


#ifndef TERMCOLOUR_HPP
#define TERMCOLOUR_HPP

#include <iostream>
#include <string>

#define TERMCOLOR_USE_ANSI_ESCAPE_SEQUENCES

#if defined(_WIN32) || defined(_WIN64)
    #define TERMCOLOUR_PLATFORM_WINDOWS
    #include <windows.h>
#elif defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    #define TERMCOLOUR_PLATFORM_POSIX
#endif

namespace TermColour
{

    class Colour
    {
    public:
        uint8_t Red, Green, Blue;

        explicit Colour(const uint8_t& red = 0,
                        const uint8_t& green = 0,
                        const uint8_t& blue = 0)
                        :
                        Red(red),
                        Green(green),
                        Blue(blue)
        {
            std::cout;
        }

        Colour& operator = (const Colour& colour)
        = default;

        void setValues(const uint8_t& red = 0,
                       const uint8_t& green = 0,
                       const uint8_t& blue = 0)
        {
            Red = red;
            Green = green;
            Blue = blue;
        }

    };

    bool EnableVirtualConsole();

    class ColourManager
    {
        std::basic_ostream<char>* OutputStream;

        Colour FGColour, BGColour;

        bool FGTransparent, BGTransparent;

    public:
        explicit ColourManager(std::basic_ostream<char>* outputStream = &(std::cout))
                               :
                               OutputStream(outputStream)
        {
            #ifdef TERMCOLOUR_PLATFORM_WINDOWS
                EnableVirtualConsole();
            #endif
        }

        void SetBGTransparent()
        {
            (*OutputStream) << "\033[48;1;m";
            ChangeFGColour(FGColour);
        }

        void ChangeFGColour(const uint8_t& red = 0,
                            const uint8_t& green = 0,
                            const uint8_t& blue = 0)
        {
            FGColour.setValues(red, green, blue);
            (*OutputStream) << "\033[38;2;" << + red << ";" << + green << ";" << + blue << "m";
        }

        void ChangeFGColour(const Colour& colour)
        {
            FGColour = colour;
            (*OutputStream) << "\033[38;2;" << + colour.Red << ";" << + colour.Green << ";" << + colour.Blue << "m";
        }

        void SetFGTransparent()
        {
            (*OutputStream) << "\033[38;1;m";
            ChangeFGColour(FGColour);
        }

        void ChangeBGColour(const uint8_t& red = 0,
                            const uint8_t& green = 0,
                            const uint8_t& blue = 0)
        {
            BGColour.setValues(red, green, blue);
            (*OutputStream) << "\033[48;2;" << + red << ";" << + green << ";" << + blue << "m";
        }

        void ChangeBGColour(const Colour& colour)
        {
            BGColour = colour;
            (*OutputStream) << "\033[48;2;" << + colour.Red << ";" << + colour.Green << ";" << + colour.Blue << "m";
        }


        ~ColourManager()
        {
            delete OutputStream;
        }
    };
}

TermColour::Colour Black(0,0,0);
TermColour::Colour White(255,255,255);
TermColour::Colour Red(255,0,0);
TermColour::Colour Gren(0,255,0);
TermColour::Colour Blue(0,0,255);


#ifdef TERMCOLOUR_PLATFORM_WINDOWS
bool TermColour::EnableVirtualConsole()
{
    // Set output mode to handle virtual terminal sequences
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return false;
    }
    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
    if (hIn == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    DWORD dwOriginalOutMode = 0;
    DWORD dwOriginalInMode = 0;
    if (!GetConsoleMode(hOut, &dwOriginalOutMode))
    {
        return false;
    }
    if (!GetConsoleMode(hIn, &dwOriginalInMode))
    {
        return false;
    }

    DWORD dwRequestedOutModes = ENABLE_VIRTUAL_TERMINAL_PROCESSING | DISABLE_NEWLINE_AUTO_RETURN;
    DWORD dwRequestedInModes = ENABLE_VIRTUAL_TERMINAL_INPUT;

    DWORD dwOutMode = dwOriginalOutMode | dwRequestedOutModes;
    if (!SetConsoleMode(hOut, dwOutMode))
    {
        // we failed to set both modes, try to step down mode gracefully.
        dwRequestedOutModes = ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        dwOutMode = dwOriginalOutMode | dwRequestedOutModes;
        if (!SetConsoleMode(hOut, dwOutMode))
        {
            // Failed to set any VT mode, can't do anything here.
            return -1;
        }
    }

    DWORD dwInMode = dwOriginalInMode | dwRequestedInModes;
    if (!SetConsoleMode(hIn, dwInMode))
    {
        // Failed to set VT input mode, can't do anything here.
        return -1;
    }
}
#endif //TERMCOLOUR_PLATFORM_WINDOWS

#endif //TERMCOLOUR_HPP


