/*
** EPITECH PROJECT, 2018
** 4081.cpp
** File description:
** <..>
*/

#include "4081.hpp"

comp_4081::comp_4081(const std::string &value)
	: and1(1, nts::UNDEFINED, 2, nts::UNDEFINED, 3),
	and2(5, nts::UNDEFINED, 6, nts::UNDEFINED, 4),
	and3(8, nts::UNDEFINED, 9, nts::UNDEFINED, 10),
	and4(12, nts::UNDEFINED, 13, nts::UNDEFINED, 11),
	_value(value)
{
}

nts::Tristate comp_4081::compute(std::size_t pin)
{
	if (pin == 3)
		return and1.compute(pin);
	if (pin == 4)
		return and2.compute(pin);
	if (pin == 10)
		return and3.compute(pin);
	if (pin == 11)
		return and4.compute(pin);
	return nts::UNDEFINED;
}

void comp_4081::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	if (pin == 1 || pin == 2 || pin == 3)
		and1.setLink(pin, other, otherPin);
	else if (pin == 5 || pin == 6 || pin == 4)
		and2.setLink(pin, other, otherPin);
	else if (pin == 8 || pin == 9 || pin == 10)
		and3.setLink(pin, other, otherPin);
	else if (pin == 12 || pin == 13 || pin == 11)
		and4.setLink(pin, other, otherPin);
	else
		std::cerr << "Can't set link: Wrong pin!" << std::endl;
}

void comp_4081::dump() const
{
	std::cout << "Dump component 4001 of name " << _value << ":";
	std::cout << std::endl;
	std::cout << "nor gate no1" << std::endl;
	and1.dump();
	std::cout << "nor gate no2" << std::endl;
	and2.dump();
	std::cout << "nor gate no3" << std::endl;
	and3.dump();
	std::cout << "nor gate no4" << std::endl;
	and4.dump();
}

std::string comp_4081::getName() const
{
	return _value;
}
