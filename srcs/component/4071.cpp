/*
** EPITECH PROJECT, 2018
** 4071.cpp
** File description:
** <..>
*/

#include "4071.hpp"

comp_4071::comp_4071(const std::string &value)
	: or1(1, nts::UNDEFINED, 2, nts::UNDEFINED, 3),
	or2(5, nts::UNDEFINED, 6, nts::UNDEFINED, 4),
	or3(8, nts::UNDEFINED, 9, nts::UNDEFINED, 10),
	or4(12, nts::UNDEFINED, 13, nts::UNDEFINED, 11),
	_value(value)
{
}

nts::Tristate comp_4071::compute(std::size_t pin)
{
	if (pin == 3)
		return or1.compute(pin);
	if (pin == 4)
		return or2.compute(pin);
	if (pin == 10)
		return or3.compute(pin);
	if (pin == 11)
		return or4.compute(pin);
	return nts::UNDEFINED;
}

void comp_4071::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	if (pin == 1 || pin == 2 || pin == 3)
		or1.setLink(pin, other, otherPin);
	else if (pin == 5 || pin == 6 || pin == 4)
		or2.setLink(pin, other, otherPin);
	else if (pin == 8 || pin == 9 || pin == 10)
		or3.setLink(pin, other, otherPin);
	else if (pin == 12 || pin == 13 || pin == 11)
		or4.setLink(pin, other, otherPin);
	else
		std::cerr << "Can't set link: Wrong pin!" << std::endl;
}

void comp_4071::dump() const
{
	std::cout << "Dump component 4071 of name " << _value << ":";
	std::cout << std::endl;
	std::cout << "or gate no1" << std::endl;
	or1.dump();
	std::cout << "or gate no2" << std::endl;
	or2.dump();
	std::cout << "or gate no3" << std::endl;
	or3.dump();
	std::cout << "or gate no4" << std::endl;
	or4.dump();
}

std::string comp_4071::getName() const
{
	return _value;
}
