// lab.cpp

#include "lab.h"

#include <print>

void lab::task1(int x) const 
{
    std::println(">>> Task 1: Compute square");
    std::println("Square of {} = {}", x, x * x);
}

void lab::task2(const std::string& str) const
{
    std::println(">>> Task 2: String length");
    std::println("Length of '{}' = {}", str, str.length());
}

void lab::execute() const                      // what your lab will perform while being executed (inherited from gcsll::labs::lab_base)
{
    this->task1(42);
    this->task2("This is laboratory assignment #1");
}

REG_LAB(lab, "Laboratory assignment #1");      // reg lab to be detected by launcher
