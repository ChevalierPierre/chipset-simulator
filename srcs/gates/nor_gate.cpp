/*
** EPITECH PROJECT, 2018
** nor_gate.cpp
** File description:
** <..>
*/

#include "nor_gate.hpp"

nor_gate::nor_gate(size_t in_pin, nts::Tristate val, size_t sin_pin,
		nts::Tristate sval, size_t o_pin)
{
	input_pin_A.type = INPUT;
	input_pin_A.pin_no = in_pin;
	input_pin_A.val = val;
	input_pin_B.type = INPUT;
	input_pin_B.pin_no = sin_pin;
	input_pin_B.val = sval;
	output_pin_Y.type = OUTPUT;
	output_pin_Y.pin_no = o_pin;
	output_pin_Y.val = nts::UNDEFINED;
	link_pin = nullptr;
	link_no = 0;
}

nor_gate::~nor_gate()
{}

nts::Tristate nor_gate::compute(std::size_t pin)
{
	struct link	*tmp = link_pin;

	(void) pin;
	while (tmp) {
		if (input_pin_A.pin_no == tmp->pin)
			input_pin_A.val = tmp->other->compute(tmp->otherPin);
		if (input_pin_B.pin_no == tmp->pin)
			input_pin_B.val = tmp->other->compute(tmp->otherPin);
		tmp = tmp->next_link;
	}
	if (input_pin_A.val == nts::UNDEFINED || input_pin_B.val ==
			nts::UNDEFINED) {
		if (input_pin_A.val == nts::UNDEFINED &&
				input_pin_B.val == nts::TRUE)
			output_pin_Y.val = nts::FALSE;
		if (input_pin_A.val == nts::TRUE &&
				input_pin_B.val == nts::UNDEFINED)
			output_pin_Y.val = nts::FALSE;
		if (input_pin_A.val == nts::UNDEFINED &&
				input_pin_B.val == nts::FALSE)
			output_pin_Y.val = nts::UNDEFINED;
		if (input_pin_A.val == nts::FALSE &&
				input_pin_B.val == nts::UNDEFINED)
			output_pin_Y.val = nts::UNDEFINED;
		if (input_pin_A.val == nts::UNDEFINED &&
				input_pin_B.val == nts::UNDEFINED)
			output_pin_Y.val = nts::UNDEFINED;
	} else {
		if (!(input_pin_A.val || input_pin_B.val))
			output_pin_Y.val = nts::TRUE;
		else
			output_pin_Y.val = nts::FALSE;
	}
	return output_pin_Y.val;
}

static bool pin_already_linked(struct link *link_lst, std::size_t pin)
{
	while (link_lst) {
		if (link_lst->pin == pin)
			return false;
		link_lst = link_lst->next_link;
	}
	return true;
}

void nor_gate::setLink(std::size_t pin, nts::IComponent &other,
		std::size_t otherPin)
{
	struct link	*tmp = link_pin;
	struct link	*tmp2 = link_pin;

	if (link_no < 3 && pin_already_linked(link_pin, pin)) {
		tmp = (struct link *)malloc(sizeof(struct link));
		if (tmp == NULL)
			std::cerr << "out of memory" << std::endl;
		tmp->pin = pin;
		tmp->other = &(other);
		tmp->otherPin = otherPin;
		tmp->next_link = nullptr;
		while (tmp2 && tmp2->next_link)
			tmp2 = tmp2->next_link;
		if (tmp2)
			tmp2->next_link = tmp;
		else
			link_pin = tmp;
		link_no++;
	} else {
		std::cerr << "Can't create more than 3 links!" << std::endl;
	}
}

struct pin nor_gate::getOutputPin()
{
	return (output_pin_Y);
}

void nor_gate::dump() const
{
	std::cout << "A = " << input_pin_A.val << std::endl;
	std::cout << "B = " << input_pin_B.val << std::endl;
	std::cout << "Y = " << output_pin_Y.val << std::endl;
}

std::string nor_gate::getName()
{
    return ("");
}
