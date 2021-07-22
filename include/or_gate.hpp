/*
** EPITECH PROJECT, 2017
** or_gate.hpp
** File description:
** <..>
*/

#ifndef OR_GATE_HPP_
#define OR_GATE_HPP_

#include "pin.hpp"

class or_gate: public nts::IComponent {
	public:
		or_gate(size_t in_pin, nts::Tristate val, size_t sin_pin,
				nts::Tristate sval, size_t o_pin);
		~or_gate();
		nts::Tristate compute(std::size_t pin);
		void setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin);
		void dump() const;
		struct pin getOutputPin();
        std::string getName();
	private:
		struct pin input_pin_A;
		struct pin input_pin_B;
		struct pin output_pin_Y;
		struct link	*link_pin;
		int		link_no;
};

#endif
