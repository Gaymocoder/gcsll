#include "gcsll/utils/exstd.h"

#include <print>
#include <limits>
#include <iostream>

namespace gcsll::utils
{

void clear_output()
{
	std::print("{}{}", ECMA_ED, ECMA_CUP);
}

void press_enter()
{
    std::print("\nPress Enter to continue...");
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    std::cin.get();
}

}