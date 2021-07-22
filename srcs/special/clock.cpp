/*
** EPITECH PROJECT, 2018
** clock.hpp
** File description:
** <..>
*/

#include "clock.hpp"

clock_cmp::clock_cmp(std::string str)
{
	clock_pin.name = str;
	clock_pin.pin_no = 1;
	clock_pin.type = INPUT;
	clock_pin.val = nts::UNDEFINED;
	link_pin = NULL;
	link_no = 1;
}

clock_cmp::~clock_cmp()
{
	if (link_pin)
		free(link_pin);
}

nts::Tristate clock_cmp::compute(std::size_t pin)
{
	if (pin == clock_pin.pin_no) {
		if (clock_pin.val == nts::TRUE) {
			clock_pin.val = nts::FALSE;
		} else if (clock_pin.val == nts::FALSE) {
			clock_pin.val = nts::TRUE;
		} else {
			clock_pin.val = nts::UNDEFINED;
		}
		return (clock_pin.val);
	}
	return (nts::UNDEFINED);
}

void clock_cmp::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	if (link_pin == NULL) {
		link_pin = (struct link *)malloc(sizeof(struct link));
		if (link_pin == NULL)
			std::cerr << "out of memory" << std::endl;
		link_pin->pin = pin;
		link_pin->other = &other;
		link_pin->otherPin = otherPin;
	} else {
		std::cerr << "Can't create multiple links!" << std::endl;
	}
}

void clock_cmp::dump() const
{
	std::cout << clock_pin.name << "=" << clock_pin.val << std::endl;
}

void clock_cmp::setPinVal(nts::Tristate val)
{
	clock_pin.val = val;
}

std::string clock_cmp::getName()
{
	return clock_pin.name;
}
