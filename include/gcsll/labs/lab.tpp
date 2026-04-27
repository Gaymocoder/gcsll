#ifndef __GCSLL_LABS_LAB_TPP__
#define __GCSLL_LABS_LAB_TPP__

#include "gcsll/labs/lab.h"

namespace gcsll::labs
{

template <typename... Args>
std::shared_ptr <lab> lab::create(Args&& ... args)
{
    auto inst = std::shared_ptr <lab> (new lab(std::forward <Args> (args)...));
    lab::reg_lab(inst);
    return inst;
}

}

#endif