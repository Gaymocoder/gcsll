#ifndef __GCSLL_LABS_LAB_BASE_H__
#define __GCSLL_LABS_LAB_BASE_H__

#include <string>
#include <vector>
#include <memory>
#include <functional>

namespace gcsll::labs
{
    class lab_base
    {
        public:
            virtual const size_t& index() const = 0;
            virtual const std::string& name() const = 0;
            virtual bool add_task(std::string_view name, std::function <void()> task_func) = 0;

            virtual void printout() const = 0;
            
            virtual void execute() const = 0;
            virtual ~lab_base() = default;            
    };

    typedef std::shared_ptr <lab_base> lab_ptr;
}

#endif