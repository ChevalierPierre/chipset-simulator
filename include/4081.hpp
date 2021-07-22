/*
** EPITECH PROJECT, 2017
** 4081.hpp
** File description:
** <..>
*/

#ifndef F_4081_HPP_
#define F_4081_HPP_

#include "IComponent.hpp"
#include "and_gate.hpp"

class comp_4081: public virtual nts::IComponent
{
	public:
		comp_4081(const std::string &value);
		nts::Tristate compute(std::size_t pin=1);
		void setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin);
		void dump() const;
		std::string getName() const;
	private:
		and_gate	and1;
		and_gate	and2;
		and_gate	and3;
		and_gate	and4;
		const std::string	&_value;
};

#endif
