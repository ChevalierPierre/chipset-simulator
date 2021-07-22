/*
** EPITECH PROJECT, 2017
** input.hpp
** File description:
** <..>
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "pin.hpp"
#include "IComponent.hpp"

class input: public virtual nts::IComponent {
	public:
		input(std::string str);
		~input();
		nts::Tristate compute(std::size_t pin = 1);
		void setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin);
		void dump() const;
		void setPinVal(nts::Tristate val);
		std::string getName();
	private:
		struct pin	input_pin;
		struct link	*link_pin;
		int		link_no;
};

#endif
