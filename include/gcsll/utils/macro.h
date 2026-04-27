#ifndef __GCSLL_UTILS_MACRO_H__
#define __GCSLL_UTILS_MACRO_H__

// deprecated
#define DECLARE_LAB(clName, ...) \
    class clName : public gcsll::labs::lab <clName> \
    { \
        friend class gcsll::labs::lab <clName>; \
        protected: \
            clName(std::string_view name) : gcsll::labs::lab <clName> (name) {} \
        public: \
            void execute() const override; \
        __VA_ARGS__ \
    };
    
// deprecated
#define REG_LAB(class, name) \
    static bool _reg = class::create(name);

#define DECLARE_GCSLL_LAB(clName) \
    class clName : public gcsll::labs::lab <clName> \
    { \
        friend class gcsll::labs::lab <clName>; \
        protected: \
            clName(std::string_view name) : gcsll::labs::lab <clName> (name) {} \
        public: \
            static gcsll::labs::lab_ptr instance() { \
                if (clName::labs.empty()) \
                    return nullptr; \
                return clName::labs.front(); \
            } \
    }; \
    static bool _reg_##clName = clName::create(#clName);

#define DECLARE_GCSLL_TASK(clName, taskName, ...) \
    static bool _reg_##clName##_##taskName = \
    clName::instance()->add_task(#taskName, __VA_ARGS__);

#endif