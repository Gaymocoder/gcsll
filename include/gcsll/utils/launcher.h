#ifndef __NUMMETS_UTILS_LAUNCHER_H__
#define __NUMMETS_UTILS_LAUNCHER_H__

#include "gcsll/labs/lab_base.h"

#include <vector>
#include <memory>
#include <string_view>

namespace gcsll::utils
{
    class launcher
    {
        private:
            launcher();
            static std::string title;

        public:
            static void init(std::string_view title);
            static void execute(size_t index);
            static void printout();
    };
}

#endif