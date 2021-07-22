/*
** EPITECH PROJECT, 2017
** pin.hpp
** File description:
** <..>
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "IComponent.hpp"

enum PIN_TYPE {
	INPUT,
	OUTPUT
};

struct pin {
	std::string	name;
	size_t		pin_no;
	enum PIN_TYPE	type;
	nts::Tristate	val;
};

struct link {
	std::size_t	pin;
	nts::IComponent *other;
	std::size_t	otherPin;
	struct link	*next_link;
};

#endif
