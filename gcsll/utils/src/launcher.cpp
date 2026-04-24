#include "gcsll/utils/launcher.h"
#include "gcsll/utils/exstd.h"
#include "gcsll/labs/lab.h"

#include <bit>
#include <print>
#include <format>
#include <iterator>
#include <iostream>

namespace gcsll::utils
{

namespace labs = gcsll::labs;
std::string launcher::title = "";

void launcher::init(std::string_view title)
{
    launcher::title = std::string(title);
    while (true)
    {
        utils::clear_output();
        
        launcher::printout();
        size_t selected = 0;
        std::cin >> selected;

        if (selected == 0)
            return;
       
        launcher::execute(selected);
        gcsll::utils::press_enter();
    }
}

void launcher::execute(size_t index)
{
    if (index > labs::count())
    {
        std::println("No lab with that index is provided. Choose from the ones are above");
        return;
    }
    
    auto& selected_lab = labs::get(index-1);
    gcsll::utils::clear_output();
    selected_lab.printout();
    selected_lab.execute();
}

void launcher::printout()
{
    const size_t labs_count = labs::count();
    const std::string tildas = std::format("{:~>{}}", "", launcher::title.size() + 4);

    std::print(
        "{0}\n{1:^{2}}\n{0}\nChoose lab (enter 0 to exit):\n",
        tildas,
        std::format("| {} |", launcher::title),
        tildas.length() - 1,
        labs_count
    );

    for(size_t i = 0, len = labs_count; i < len; ++i)
        std::print("{}. {}\n", 1 << i, labs::get(i).name());
    std::print("\nSelected lab number: ");
}

}