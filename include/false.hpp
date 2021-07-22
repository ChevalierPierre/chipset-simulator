/*
** EPITECH PROJECT, 2017
** false.hpp
** File description:
** <..>
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "pin.hpp"
#include "IComponent.hpp"

class false_cmp: public virtual nts::IComponent {
	public:
		false_cmp(std::string str);
		~false_cmp();
		nts::Tristate compute(std::size_t pin = 1);
		void setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin);
		void dump() const;
		std::string getName();
	private:
		struct pin	input_pin;
		struct link	*link_pin;
		int		link_no;
};

#endif
