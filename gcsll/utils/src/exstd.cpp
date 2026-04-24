#include "gcsll/utils/exstd.h"

#include <print>
#include <limits>
#include <iostream>

namespace gcsll::utils
{

void clear_output()
{
	if (WIN)
		system("cls");
	else
		system("clear");
}

void press_enter()
{
    std::print("\nPress Enter to continue...");
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    std::cin.get();
}

}