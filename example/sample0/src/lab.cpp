// lab.cpp

#include "lab.h"

#include <print>

void lab_sample::task0(int a, int b) const 
{
    std::println(">>> Task 0 — Addition");
    std::println("{} + {} = {}", a, b, a + b);
}

void lab_sample::execute() const        // what your lab will perform while being executed (inherited from gcsll::labs::lab_base)
{
    this->task0(1, 1);
}

REG_LAB(lab_sample, "Sample lab");      // reg lab to be detected by launcher
