/*
** EPITECH PROJECT, 2017
** 4030.hpp
** File description:
** <..>
*/

#ifndef F_4030_HPP_
#define F_4030_HPP_

#include "IComponent.hpp"
#include "xor_gate.hpp"

class comp_4030: public virtual nts::IComponent
{
	public:
		comp_4030(const std::string &value);
		nts::Tristate compute(std::size_t pin=1);
		void setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin);
		void dump() const;
		std::string getName() const;
	private:
		xor_gate	xor1;
		xor_gate	xor2;
		xor_gate	xor3;
		xor_gate	xor4;
		const std::string	&_value;
};

#endif
