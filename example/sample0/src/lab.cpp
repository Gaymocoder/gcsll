// lab.cpp
#include <gcsll/gcsll.h>

DECLARE_GCSLL_LAB(lab3);

DECLARE_GCSLL_TASK(lab3, task0, []()
{
    std::println("Dihotomia method");
});

DECLARE_GCSLL_TASK(lab3, task1, []()
{
    std::println("HELLO, world!");
});