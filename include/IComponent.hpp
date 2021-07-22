/*
** EPITECH PROJECT, 2017
** IComponent.hpp
** File description:
** <..>
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>

namespace nts
{
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	class IComponent
	{
	public:
		virtual ~IComponent() = default;
	public:
		// compute does calculation on the pin output
		virtual nts::Tristate compute(std::size_t pin = 1) = 0;
		// set the link between two IComponent
		virtual void setLink(std::size_t pin, nts::IComponent &other,
				std::size_t otherPin) = 0;
        virtual std::string getName() = 0;
		// display information about component
		virtual void dump() const = 0;
	};
}

#endif
