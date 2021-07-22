/*
** EPITECH PROJECT, 2018
** output.cpp
** File description:
** <..>
*/

#include "output.hpp"

output::output(std::string str)
{
	output_pin.name = str;
	output_pin.pin_no = 1;
	output_pin.type = INPUT;
	output_pin.val = nts::UNDEFINED;
	link_pin = NULL;
	link_no = 1;
}

output::~output()
{
	if (link_pin)
		free(link_pin);
}

nts::Tristate output::compute(std::size_t pin)
{
	if (link_pin && link_pin->pin == pin) {
		output_pin.val = link_pin->other->compute(link_pin->otherPin);
		return (output_pin.val);
	}
	return (nts::UNDEFINED);
}

void output::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	if (link_pin == NULL) {
		link_pin = (struct link *)malloc(sizeof(struct link));
		if (link_pin == NULL)
			std::cerr << "out of memory" << std::endl;
		link_pin->pin = pin;
		link_pin->other = &(other);
		link_pin->otherPin = otherPin;
	} else {
		std::cerr << "Can't create multiple links!" << std::endl;
	}
}

void output::dump() const
{
	std::cout << output_pin.name << "=" << output_pin.val << std::endl;
}

std::string output::getName() const
{
	return output_pin.name;
}
