/*
** EPITECH PROJECT, 2017
** create.hpp
** File description:
** <..>
*/

#ifndef CREATE_HPP_
#define CREATE_HPP_

#include <memory>
#include <vector>

#include "IComponent.hpp"

struct created_list {
    std::unique_ptr<nts::IComponent>    component;
    struct created_list *next;
    struct created_list *prev;
};

class creator {
    public:
        creator();
        ~creator();
        std::unique_ptr<nts::IComponent> find_function(std::string name,
                const std::string &value);
    private:
        std::unique_ptr<nts::IComponent> (*func_ptr[11])
            (const std::string &value);
        std::vector<std::string> func_name;
        struct created_list *list;
};

std::unique_ptr<nts::IComponent> create4001(const std::string &value) noexcept;
std::unique_ptr<nts::IComponent> create4011(const std::string &value) noexcept;
std::unique_ptr<nts::IComponent> create4071(const std::string &value) noexcept;
std::unique_ptr<nts::IComponent> create4081(const std::string &value) noexcept;
std::unique_ptr<nts::IComponent> create4030(const std::string &value) noexcept;
std::unique_ptr<nts::IComponent> createInput(const std::string &value) noexcept;
std::unique_ptr<nts::IComponent> createOutput(const std::string &value) noexcept;
std::unique_ptr<nts::IComponent> createTrue(const std::string &value) noexcept;
std::unique_ptr<nts::IComponent> createFalse(const std::string &value) noexcept;
std::unique_ptr<nts::IComponent> createClock(const std::string &value) noexcept;

#endif
