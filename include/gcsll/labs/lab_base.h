#ifndef __NUMMETS_LABS_LAB_BASE_H__
#define __NUMMETS_LABS_LAB_BASE_H__

#include <string>
#include <vector>
#include <memory>

namespace gcsll::labs
{
    class lab_base
    {
        public:
            virtual const size_t& index() const = 0;
            virtual const std::string& name() const = 0;

            virtual void printout() const = 0;
            
            virtual void execute() const = 0;
            virtual ~lab_base() = default;            
    };

    typedef std::unique_ptr <lab_base> lab_ptr;
}

#endif