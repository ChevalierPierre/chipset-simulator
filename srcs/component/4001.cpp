/*
** EPITECH PROJECT, 2018
** 4001.cpp
** File description:
** <..>
*/

#include "4001.hpp"

comp_4001::comp_4001(const std::string &value)
	: nor1(1, nts::UNDEFINED, 2, nts::UNDEFINED, 3),
	nor2(5, nts::UNDEFINED, 6, nts::UNDEFINED, 4),
	nor3(8, nts::UNDEFINED, 9, nts::UNDEFINED, 10),
	nor4(12, nts::UNDEFINED, 13, nts::UNDEFINED, 11),
	_value(value)
{
}

nts::Tristate comp_4001::compute(std::size_t pin)
{
	if (pin == 3)
		return nor1.compute(pin);
	if (pin == 4)
		return nor2.compute(pin);
	if (pin == 10)
		return nor3.compute(pin);
	if (pin == 11)
		return nor4.compute(pin);
	return nts::UNDEFINED;
}

void comp_4001::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	if (pin == 1 || pin == 2 || pin == 3)
		nor1.setLink(pin, other, otherPin);
	else if (pin == 5 || pin == 6 || pin == 4)
		nor2.setLink(pin, other, otherPin);
	else if (pin == 8 || pin == 9 || pin == 10)
		nor3.setLink(pin, other, otherPin);
	else if (pin == 12 || pin == 13 || pin == 11)
		nor4.setLink(pin, other, otherPin);
	else
		std::cerr << "Can't set link: Wrong pin!" << std::endl;
}

void comp_4001::dump() const
{
	std::cout << "Dump component 4001 of name " << _value << ":";
	std::cout << std::endl;
	std::cout << "nor gate no1" << std::endl;
	nor1.dump();
	std::cout << "nor gate no2" << std::endl;
	nor2.dump();
	std::cout << "nor gate no3" << std::endl;
	nor3.dump();
	std::cout << "nor gate no4" << std::endl;
	nor4.dump();
}

std::string comp_4001::getName() const
{
	return _value;
}
