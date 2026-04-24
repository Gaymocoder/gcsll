#ifndef __NUMMETS_UTILS_EXSTD_H__
#define __NUMMETS_UTILS_EXSTD_H__

#ifndef __GCSLL_SHARE__

#ifdef _WIN32
    #define WIN true
#else
    #define WIN false
#endif

namespace gcsll::utils
{
    void clear_output();
    void press_enter();
}

#endif

#endif