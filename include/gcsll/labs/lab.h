#ifndef __NUMMETS_LAB_H__
#define __NUMMETS_LAB_H__

#include <print>
#include <vector>
#include <string>

namespace gcsll::labs
{
    template <typename labn>
    class lab : public lab_base
    {
        private:
            size_t _index;
            const std::string _name;

            static std::vector <lab_ptr> labs;
            static void reg_lab(lab_ptr lab);

        protected:
            lab(std::string_view name)
                : _index(lab <lab_base> ::count()), _name(name) {}

        public:
            template <typename... Args>
            static bool create(Args&& ... args);

            static size_t count();
            static const lab_base& get(size_t index);

            const size_t& index() const override;
            const std::string& name() const override;

            void printout() const override;
    };
}

#endif