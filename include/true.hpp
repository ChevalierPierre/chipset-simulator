/*
** EPITECH PROJECT, 2017
** true.hpp
** File description:
** <..>
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "pin.hpp"
#include "IComponent.hpp"

class true_cmp: public virtual nts::IComponent {
	public:
		true_cmp(std::string str);
		~true_cmp();
		nts::Tristate compute(std::size_t pin = 1);
		void setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin);
		void dump() const;
		std::string getName() const;
	private:
		struct pin	input_pin;
		struct link	*link_pin;
		int		link_no;
};

#endif
