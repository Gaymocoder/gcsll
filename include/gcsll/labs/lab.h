#ifndef __GCSLL_LABS_LAB_H__
#define __GCSLL_LABS_LAB_H__

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
    
#define REG_LAB(class, name) \
    static bool _reg = class::create(name);

#include "gcsll/labs/lab_base.h"

#include <print>
#include <vector>
#include <string>
#include <functional>

namespace gcsll::labs
{
    struct task
    {
        const std::string name;
        std::function <void()> execute;
    };

    template <typename labn>
    class lab : public lab_base
    {
        template <typename T>
        friend class lab;

        private:
            size_t _index;
            const std::string _name;

            static void reg_lab(lab_ptr lab);

        protected:
            lab(std::string_view name)
                : _index(lab <lab_base> ::count()), _name(name) {}

            std::vector <task> tasks;
            static std::vector <lab_ptr> labs;

        public:
            template <typename... Args>
            static bool create(Args&& ... args);

            static size_t count();
            static const lab_base& get(size_t index);

            const size_t& index() const override;
            const std::string& name() const override;
            bool add_task(std::string_view name, std::function <void()> task_func) override;
            
            void execute() const override;
            void printout() const override;
    };

    inline constexpr auto get = &lab <lab_base> ::get;
    inline constexpr auto count = &lab <lab_base> ::count;
}

#include "gcsll/labs/lab.tpp"

#endif