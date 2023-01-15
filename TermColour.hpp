//!
//! TermColour
//! ~~~~~~~~~
//!
//! TermColour is a header only library based on termcolor by Ihor Kalnytskyi
//! I was frustrated with some of the functionality of the original program and how the templates restricted it
//! Hopefully this will be easier to use and more powerful
//!


#ifndef TERMCOLOUR_HPP
#define TERMCOLOUR_HPP

namespace TermColour
{
    #if defined(_WIN32) || defined(_WIN64)
    #   define TERMCOLOR_TARGET_WINDOWS
    #elif defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    #   define TERMCOLOR_TARGET_POSIX
    #endif
}
#endif //TERMCOLOUR_HPP
