#ifndef __NUMMETS_LAB_TPP__
#define __NUMMETS_LAB_TPP__

#include "gcsll/labs/lab.h"

#include <print>
#include <format>
#include <memory>
#include <string>

namespace gcsll::labs
{

std::vector <lab_ptr> lab::labs;

void lab::printout() const
{
    const std::string tildas = std::format("{:~>{}}", "", this->_name.size() + 12);
    std::print(
        "{0}\n{1:^{2}}\n{0}\n",
        tildas,
        std::format("| LAB #{}. {} |", (uint16_t) this->index() + 1, this->_name),
        tildas.length() - 1
    );
}

void lab::execute() const 
{
    for(auto& task : this->tasks)
    {
        std::println("\n[{}]", task.name);
        task.execute();
    }
}

bool lab::add_task(std::string_view name, std::function <void()> task_func)
{
    this->tasks.push_back(task {
        std::string(name),
        task_func
    });
    return true;
}

}

#endif