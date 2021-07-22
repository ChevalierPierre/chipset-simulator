/*
** EPITECH PROJECT, 2017
** 4001.hpp
** File description:
** <..>
*/

#ifndef F_4001_HPP_
#define F_4001_HPP_

#include "IComponent.hpp"
#include "nor_gate.hpp"

class comp_4001: public virtual nts::IComponent
{
	public:
		comp_4001(const std::string &value);
		nts::Tristate compute(std::size_t pin=1);
		void setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin);
		void dump() const;
		std::string getName();
	private:
		nor_gate	nor1;
		nor_gate	nor2;
		nor_gate	nor3;
		nor_gate	nor4;
		const std::string	&_value;
};

#endif
