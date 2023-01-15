
//#include "TermColour.hpp"

#include <iostream>
#include <string>
#include "TermColour.hpp"



int main()
{
    TermColour::ColourManager CM;
    CM.ChangeBGColour(Black);
    CM.ChangeFGColour(Blue);
    std::cout << "Hello world!" << std::endl;
    CM.ChangeBGColour(Black);
    std::cout << "Hello world!" << std::endl;
    CM.SetBGTransparent();
    std::cout << "Hello world!" << std::endl;
    std::cout << "Hello world!" << std::endl;
    std::cout << "Hello world!" << std::endl;
    std::cout << "Hello world!" << std::endl;
    std::cout << "Hello world!" << std::endl;
    std::cout << "Hello world!" << std::endl;
    std::cin.get();
    return 0;
}
