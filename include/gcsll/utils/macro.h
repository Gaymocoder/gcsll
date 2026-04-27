#ifndef __GCSLL_UTILS_MACRO_H__
#define __GCSLL_UTILS_MACRO_H__

#define DECLARE_GCSLL_LAB(clName) \
    static auto _reg_##clName = gcsll::labs::lab::create(#clName); \
    std::shared_ptr <gcsll::labs::lab> _get_##clName##_instance() {return _reg_##clName;}

#define DECLARE_GCSLL_TASK(clName, taskName, ...) \
    static bool _reg_##clName##_##taskName = \
    _get_##clName##_instance()->add_task(#taskName, __VA_ARGS__);

#endif