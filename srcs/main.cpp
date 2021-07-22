/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** <..>
*/


#include "nanotekspice.hpp"
#include <string.h>

#include "parser.hpp"
#include "create.hpp"

int main(int ac, char **av)
{
	Parser pars;

	if(ac < 2) {
		std::cout << "Usage:\nFirst argument is the name of the";
		std::cout << " nts file: [file.nts]\nOther arguments ";
		std::cout << "are: [input=value]" << std::endl;
		return (84);
	}
	std::string str_load = std::string(av[1]);
	pars.loader(str_load, av);
//	pars.loop();
	return (0);
}
