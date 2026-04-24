// lab.h

#ifndef __GCSLL_SAMPLE_LAB_H__
#define __GCSLL_SAMPLE_LAB_H__

#include <gcsll/gcsll.h>

DECLARE_LAB(lab,
    void task1(int x) const;     // declaring lab tasks
    void task2(const std::string& str) const;
);

#endif
