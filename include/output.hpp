/*
** EPITECH PROJECT, 2017
** output.hpp
** File description:
** <..>
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "pin.hpp"
#include "IComponent.hpp"

class output : public virtual nts::IComponent {
	public:
		output(std::string str);
		~output();
		nts::Tristate compute(std::size_t pin = 1);
		void setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin);
		void dump() const;
		std::string getName() const;
	private:
		struct pin	output_pin;
		struct link	*link_pin;
		int		link_no;
};

#endif
