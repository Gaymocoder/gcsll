#ifndef __NUMMETS_LAB_TPP__
#define __NUMMETS_LAB_TPP__

#include "gcsll/utils.h"
#include "gcsll/labs/lab.h"

#include <print>
#include <format>
#include <memory>
#include <string>
#include <optional>

namespace gcsll::labs
{

std::vector <lab_ptr> lab::labs;

void lab::printout(std::optional <size_t> task_num) const
{
    const std::string task_name = (!task_num) ? "" : std::format(" {} |", this->tasks[*task_num].first);
    const std::string tildas = std::format("{:~>{}}", "", this->_name.size() + task_name.size() + 12);
    std::print(
        "{0}\n{1:^{2}}\n{0}\n",
        tildas,
        std::format("| LAB #{}. {} |{}", (uint16_t) this->index() + 1, this->_name, task_name),
        tildas.length() - 1
    );
}

int lab::execute() const
{
    for(size_t i = 0; const auto& [name, _] : this->tasks)
        std::println("{}. {}", ++i, name);
    std::print("{}. Launch all\n\nSelected task (enter 0 to return to lab list): ", this->tasks.size() + 1);

    size_t selected_task = 0;
    std::cin >> selected_task;
    if (!selected_task)
        return 0;

    gcsll::utils::clear_output();
    this->printout(selected_task - 1);

    if (selected_task != tasks.size() + 1)
    {
        this->tasks[selected_task-1].second();
        return 1;
    }
    
    for(const auto& [name, func] : this->tasks)
        func();
    return 1;
}

bool lab::add_task(std::string_view name, std::function <void()> task_func)
{
    this->tasks.push_back({std::string(name), task_func});
    return true;
}

}

#endif