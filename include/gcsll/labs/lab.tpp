#ifndef __NUMMETS_LAB_TPP__
#define __NUMMETS_LAB_TPP__

#include "gcsll/labs/lab.h"

#include <print>
#include <format>
#include <memory>
#include <string>

namespace gcsll::labs
{

template <typename labn>
std::vector <lab_ptr> lab <labn> ::labs;

template <typename labn>
void lab <labn> ::reg_lab(lab_ptr rlab)
{
    lab <lab_base> ::labs.push_back(rlab);
    lab <labn> ::labs.push_back(rlab);
}

template <typename labn>
template <typename... Args>
bool lab <labn> ::create(Args&& ... args)
{
    lab::reg_lab(
        std::shared_ptr <labn> (new labn(std::forward <Args> (args)...))
    );
    return true;
}

template <typename labn>
size_t lab <labn> ::count()
{
    return lab <lab_base> ::labs.size();
}

template <typename labn>
const lab_base& lab <labn> ::get(size_t index)
{
    return *lab <lab_base> ::labs[index].get();
}


template <typename labn>
const size_t& lab <labn> ::index() const
{
    return this->_index;
}

template <typename labn>
const std::string& lab <labn> ::name() const
{
    return this->_name;
}


template <typename labn>
void lab <labn> ::printout() const
{
    const std::string tildas = std::format("{:~>{}}", "", this->_name.size() + 12);
    std::print(
        "{0}\n{1:^{2}}\n{0}\n",
        tildas,
        std::format("| LAB #{}. {} |", (uint16_t) this->index() + 1, this->_name),
        tildas.length() - 1
    );
}

template <typename labn>
void lab <labn> ::execute() const 
{
    for(auto& task : this->tasks)
    {
        std::println("\n[{}]", task.name);
        task.execute();
    }
}

template <typename labn>
bool lab <labn> ::add_task(std::string_view name, std::function <void()> task_func)
{
    this->tasks.push_back(task {
        std::string(name),
        task_func
    });
    return true;
}

}

#endif