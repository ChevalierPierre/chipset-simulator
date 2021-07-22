/*
** EPITECH PROJECT, 2017
** 4011.hpp
** File description:
** <..>
*/

#ifndef F_4011_HPP_
#define F_4011_HPP_

#include "IComponent.hpp"
#include "nand_gate.hpp"

class comp_4011: public virtual nts::IComponent
{
	public:
		comp_4011(const std::string &value);
		nts::Tristate compute(std::size_t pin=1);
		void setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin);
		void dump() const;
		std::string getName() const;
	private:
		nand_gate	nand1;
		nand_gate	nand2;
		nand_gate	nand3;
		nand_gate	nand4;
		const std::string	&_value;
};

#endif
