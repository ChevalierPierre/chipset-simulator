/*
** EPITECH PROJECT, 2018
** 4011.hpp
** File description:
** <..>
*/

#include "4011.hpp"

comp_4011::comp_4011(const std::string &value)
	: nand1(1, nts::UNDEFINED, 2, nts::UNDEFINED, 3),
	nand2(5, nts::UNDEFINED, 6, nts::UNDEFINED, 4),
	nand3(8, nts::UNDEFINED, 9, nts::UNDEFINED, 10),
	nand4(12, nts::UNDEFINED, 13, nts::UNDEFINED, 11),
	_value(value)
{
}

nts::Tristate comp_4011::compute(std::size_t pin)
{
	if (pin == 3)
		return nand1.compute(pin);
	if (pin == 4)
		return nand2.compute(pin);
	if (pin == 10)
		return nand3.compute(pin);
	if (pin == 11)
		return nand4.compute(pin);
	return nts::UNDEFINED;
}

void comp_4011::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	if (pin == 1 || pin == 2 || pin == 3)
		nand1.setLink(pin, other, otherPin);
	else if (pin == 5 || pin == 6 || pin == 4)
		nand2.setLink(pin, other, otherPin);
	else if (pin == 8 || pin == 9 || pin == 10)
		nand3.setLink(pin, other, otherPin);
	else if (pin == 12 || pin == 13 || pin == 11)
		nand4.setLink(pin, other, otherPin);
	else
		std::cerr << "Can't set link: Wrong pin!" << std::endl;
}

void comp_4011::dump() const
{
	std::cout << "Dump component 4011 of name " << _value << ":";
	std::cout << std::endl;
	std::cout << "nand gate no1" << std::endl;
	nand1.dump();
	std::cout << "nand gate no2" << std::endl;
	nand2.dump();
	std::cout << "nand gate no3" << std::endl;
	nand3.dump();
	std::cout << "nand gate no4" << std::endl;
	nand4.dump();
}

std::string comp_4011::getName() const
{
	return _value;
}
