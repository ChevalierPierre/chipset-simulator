/*
** EPITECH PROJECT, 2018
** creator.c
** File description:
** <..>
*/

#include "create.hpp"

creator::creator()
{
    func_ptr[0] = &create4001;
    func_name.push_back("4001");
    func_ptr[1] = &create4011;
    func_name.push_back("4011");
    func_ptr[2] = &create4071;
    func_name.push_back("4071");
    func_ptr[3] = &create4081;
    func_name.push_back("4081");
    func_ptr[4] = &create4030;
    func_name.push_back("4081");
    func_ptr[5] = &createInput;
    func_name.push_back("input");
    func_ptr[6] = &createOutput;
    func_name.push_back("output");
    func_ptr[7] = &createTrue;
    func_name.push_back("true");
    func_ptr[8] = &createFalse;
    func_name.push_back("false");
    func_ptr[9] = &createClock;
    func_name.push_back("clock");
    func_ptr[10] = nullptr;
    list = nullptr;
}

std::unique_ptr<nts::IComponent> creator::find_function(std::string name,
        const std::string &value)
{
    for (unsigned int i = 0; i < func_name.size(); i++) {
        if (func_ptr[i] == nullptr)
            break;
        if (func_name[i].compare(name) == 0)
            return (func_ptr[i](value));
    }
    return (nullptr);
}

struct created_list *creator::create_list(std::unique_ptr<nts::IComponent> comp)
{
    struct created_list *tmp = new struct created_list;
    struct created_list *tmp2 = list;

    if (tmp == nullptr)
        return (nullptr);
    memset(tmp, 0, sizeof(struct created_list));
    tmp->component = comp;
    if (list == nullptr) {
        list = tmp;
    } else {
        while (tmp2 && tmp2->next)
            tmp2 = tmp2->next;
        tmp2->next = tmp;
        tmp->prev = tmp2;
    }
    return (list);
}

std::unique_ptr<nts::IComponent> creator::extract(std::string name)
{
    struct created_list *tmp = list;
    std::unique_ptr<nts::IComponent>    ptr;

    if (tmp == nullptr)
        return (nullptr);
    while (tmp) {
        ptr = tmp->component;
        if (name.compare(ptr->getName()) == 0)
            return (ptr);
        tmp = tmp->next;
    }
    return (nullptr);
}
