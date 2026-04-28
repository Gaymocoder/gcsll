#ifndef __GCSLL_LABS_LAB_H__
#define __GCSLL_LABS_LAB_H__

#include "gcsll/labs/lab_base.h"

#include <print>
#include <vector>
#include <string>
#include <iostream>
#include <functional>

namespace gcsll::labs
{
    typedef std::pair <std::string, std::function <void()>> task;
    class lab : public lab_base
    {
        private:
            size_t _index;
            const std::string _name;

            static void reg_lab(lab_ptr rlab) {lab::labs.push_back(rlab);}

        protected:
            lab(std::string_view name)
                : _index(lab::count()), _name(name) {}

            static std::vector <lab_ptr> labs;
            std::vector <gcsll::labs::task> tasks;

        public:
            template <typename... Args>
            static std::shared_ptr <lab> create(Args&& ... args);

            static size_t count() {return lab::labs.size();}
            static const lab_base& get(size_t index) {return *lab::labs[index].get();}

            const size_t& index() const override {return this->_index;}
            const std::string& name() const override {return this->_name;}
            bool add_task(std::string_view name, std::function <void()> task_func) override;
            
            int execute() const override;
            void printout() const override;
    };

    inline constexpr auto get = &lab::get;
    inline constexpr auto count = &lab::count;
}

#include "gcsll/labs/lab.tpp"

#endif