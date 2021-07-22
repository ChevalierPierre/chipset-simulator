/*
** EPITECH PROJECT, 2017
** clock.hpp
** File description:
** <..>
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "pin.hpp"
#include "IComponent.hpp"

class clock_cmp: public virtual nts::IComponent {
	public:
		clock_cmp(std::string str);
		~clock_cmp();
		nts::Tristate compute(std::size_t pin = 1);
		void setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin);
		void dump() const;
		void setPinVal(nts::Tristate val);
		std::string getName();
	private:
		struct pin	clock_pin;
		struct link	*link_pin;
		int		link_no;
};

#endif
