/*
** EPITECH PROJECT, 2018
** 4030.cpp
** File description:
** <..>
*/

#include "4030.hpp"

comp_4030::comp_4030(const std::string &value)
	: xor1(1, nts::UNDEFINED, 2, nts::UNDEFINED, 3),
	xor2(5, nts::UNDEFINED, 6, nts::UNDEFINED, 4),
	xor3(8, nts::UNDEFINED, 9, nts::UNDEFINED, 10),
	xor4(12, nts::UNDEFINED, 13, nts::UNDEFINED, 11),
	_value(value)
{
}

nts::Tristate comp_4030::compute(std::size_t pin)
{
	if (pin == 3)
		return xor1.compute(pin);
	if (pin == 4)
		return xor2.compute(pin);
	if (pin == 10)
		return xor3.compute(pin);
	if (pin == 11)
		return xor4.compute(pin);
	return nts::UNDEFINED;
}

void comp_4030::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	if (pin == 1 || pin == 2 || pin == 3)
		xor1.setLink(pin, other, otherPin);
	else if (pin == 5 || pin == 6 || pin == 4)
		xor2.setLink(pin, other, otherPin);
	else if (pin == 8 || pin == 9 || pin == 10)
		xor3.setLink(pin, other, otherPin);
	else if (pin == 12 || pin == 13 || pin == 11)
		xor4.setLink(pin, other, otherPin);
	else
		std::cerr << "Can't set link: Wrong pin!" << std::endl;
}

void comp_4030::dump() const
{
	std::cout << "Dump component 4001 of name " << _value << ":";
	std::cout << std::endl;
	std::cout << "nor gate no1" << std::endl;
	xor1.dump();
	std::cout << "nor gate no2" << std::endl;
	xor2.dump();
	std::cout << "nor gate no3" << std::endl;
	xor3.dump();
	std::cout << "nor gate no4" << std::endl;
	xor4.dump();
}

std::string comp_4030::getName() const
{
	return _value;
}
