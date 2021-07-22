/*
** EPITECH PROJECT, 2017
** IComponent.hpp
** File description:
** <..>
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <csignal>
#include <vector>
#include <memory>
#include "IComponent.hpp"
#include "input.hpp"
#include "output.hpp"

class Parser
{
	public:
        Parser();
		~Parser();
        void checker(char **av);
        void loader(std::string const &filepath, char **av);
        void file_init();
        void handle_links();
        void connection_maker();
	    void loop();
        void computing_dumping();
        void gate_handler();
        void end_handle_links();
        void end_gate_handler();
        
    private:
        std::string _name;
        std::string _value;
        std::string _data;
        std::stringstream _stream;
        std::vector<std::string> _inputs;
        std::vector<std::string> _outputs;
        std::vector<std::string> _links_name;
        std::vector<std::size_t> _links_gate_number;
        std::vector<std::size_t> _links_value;
        std::vector<input> _pins_inputs;
        std::vector<output> _pins_outputs;
        std::string _chipset_gate;
        std::vector<std::string> _arg_names;
        std::vector<std::size_t> _arg_values;
        std::unique_ptr<nts::IComponent> gate;
        std::string str_connec;
        std::vector<std::unique_ptr<nts::IComponent>>* _main_stack;
};

#endif
