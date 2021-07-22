/*
** EPITECH PROJECT, 2018
** true.cpp
** File description:
** <..>
*/

#include "true.hpp"

true_cmp::true_cmp(std::string str)
{
	input_pin.name = str;
	input_pin.pin_no = 1;
	input_pin.type = INPUT;
	input_pin.val = nts::TRUE;
	link_pin = NULL;
	link_no = 1;
}

true_cmp::~true_cmp()
{
	if (link_pin)
		free(link_pin);
}

nts::Tristate true_cmp::compute(std::size_t pin)
{
	if (pin == input_pin.pin_no)
		return (input_pin.val);
	return (nts::UNDEFINED);
}

void true_cmp::setLink(std::size_t pin, nts::IComponent &other,
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

void true_cmp::dump() const
{
	std::cout << input_pin.name << "=" << input_pin.val << std::endl;
}

std::string true_cmp::getName() const
{
	return input_pin.name;
}
