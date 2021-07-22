/*
** EPITECH PROJECT, 2017
** 4071.hpp
** File description:
** <..>
*/

#ifndef F_4071_HPP_
#define F_4071_HPP_

#include "IComponent.hpp"
#include "or_gate.hpp"

class comp_4071: public virtual nts::IComponent
{
	public:
		comp_4071(const std::string &value);
		nts::Tristate compute(std::size_t pin=1);
		void setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin);
		void dump() const;
		std::string getName() const;
	private:
		or_gate	or1;
		or_gate	or2;
		or_gate	or3;
		or_gate	or4;
		const std::string	&_value;
};

#endif
