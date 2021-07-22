/*
** EPITECH PROJECT, 2017
** IComponent.hpp
** File description:
** <..>
*/

#include "parser.hpp"
#include "input.hpp"
#include "output.hpp"
#include "create.hpp"

Parser::Parser()
{}

Parser::~Parser()
{}

static std::string trim_tab(const std::string& str)
{
	std::size_t first = str.find_first_not_of('\t');
	if (std::string::npos == first)
		return str;
	std::size_t last = str.find_last_not_of('\t');
	return str.substr(first, (last - first + 1));
}

static std::string trim(const std::string& str)
{
	std::size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
		return str;
	std::size_t last = str.find_last_not_of(' ');
	return trim_tab(str.substr(first, (last - first + 1)));
}

static nts::Tristate converter(int nb)
{
	if (nb == 0)
		return (nts::Tristate::FALSE);
	if (nb == 1)
		return (nts::Tristate::TRUE);
	if (nb == -1)
		return (nts::Tristate::UNDEFINED);
	std::cerr << "converting issue between boolean and integer" << std::endl;
	exit(84);
}

void Parser::checker(char **avi)
{
	size_t temp;
	for (size_t i = 2; avi[i]; i++) {
		std::string av = std::string(avi[i]);
		_name = trim(av.substr(0, av.find_first_of('=')));
		_arg_names.push_back(_name);
		_value = trim(av.substr(av.find_first_of('=') + 1));
		temp = stoi(_value);
		_arg_values.push_back(temp);
		if (_name.compare(av) == 0 || _name.size() == av.size()) {
			std::cerr << "Arguments are ill written" << std::endl;
			exit(84);
		}
	}
}

void Parser::loader(std::string const &filepath, char **av)
{
	std::ifstream file(filepath);

	if (!file.is_open())
		exit(84);

	std::stringstream buffer;
	buffer << file.rdbuf();
	_data = buffer.str();
	_stream = std::stringstream(_data);
	file_init();
	checker(av);
	handle_links();
	connection_maker();
}

void Parser::file_init()
{
	creator *create_things = new creator;
	bool chip = false;
	bool gat = false;
	std::string line;

	while (std::getline(_stream, line)) {
		if (line[0] != '#' && line[0] != '\0' && line[0] != '\n') {
			if (line.find("#") != std::string::npos)
				line = line.substr(0, line.find('#'));
			if (line.find(".chipsets:") != std::string::npos && chip == false) { 
				chip = true;	
				continue;
			}
			if (line.find(".links:") != std::string::npos && gat == false && chip == true) {
				gat = true;
				chip = false;
				continue;
			}
			if (chip == true) {
				std::string n1 = trim(line.substr(0, line.find(' ')));
				std::string n2 = trim(line.substr(line.find(' ')));
				std::unique_ptr<nts::IComponent> ptr;
				if ((ptr = create_things->find_function(n1, n2)) == nullptr)
					exit(84);
				_main_stack->push_back(ptr);// CETTE LIGNE PART EN COUILLE
			}
			else if (gat == true) {
				std::string n1 = trim(line.substr(0, line.find(' ')));
				std::string n2 = trim(line.substr(line.find(' ')));
				std::unique_ptr<nts::IComponent> ptr;
				if ((ptr = create_things->find_function(n1, n2)) == nullptr)
					exit(84);
				_main_stack->push_back(ptr); // CETTE LIGNE PART EN COUILLE
			}
			else
				continue;
		}
	}
}
/*
	size_t nb;
	std::string line;
	std::string chunk;

	while (std::getline(_stream, line)) {
		if (line.compare(0,1,"#") == 0)
			continue;
		if (line.find("#") != std::string::npos)
			line = line.substr(0, line.find('#'));
		if (line.find("input") != std::string::npos) {
			chunk = trim(line.substr(line.find("input") + 5));
			_inputs.push_back(chunk);
		} else if (line.find("output") != std::string::npos) {
			chunk = trim(line.substr(line.find("output") + 6));
			_outputs.push_back(chunk);
		} else if (line[0] == '4') {
			chunk = trim(line.substr(line.find("4"), 4));
			_chipset_gate = chunk;
		} else if (line.find("gate:") != std::string::npos) {
			chunk = trim(line.substr(0, line.find_first_of(":")));
			_links_name.push_back(chunk);
			nb = stoi(trim(line.substr(line.find_first_of(":") + 1, 1)));
			_links_value.push_back(nb);
			nb = stoi(trim(line.substr(line.find_last_of(":") + 1)));
			_links_gate_number.push_back(nb);
		} else
			continue;
	}
}

void Parser::end_handle_links()
{
	size_t j = 0;
	for (size_t i = 0; i < _arg_names.size(); i++) {
		for (size_t l = 0; l < _inputs.size(); l++) {
			if (_arg_names[i].compare(_inputs[l]) == 0) {
				j++;
				_pins_inputs[l].setPinVal(converter(_arg_values[i]));
				break;
			}
		} if (j < i) {
			std::cerr << "Issue with arguments" << std::endl;
			exit(84);
		}
	}
}

void Parser::handle_links()
{
	for (std::size_t i = 0; i < _inputs.size(); i++) {
		if (_links_name[i].compare(_inputs[i]) == 0) {
			input inp(_inputs[i]);
			_pins_inputs.push_back(inp);
		}
	}
	for (std::size_t i = 0; i < _outputs.size(); i++) {
		if (_links_name[i + _inputs.size()] == _outputs[i]) {
			output outp(_outputs[i]);
			_pins_outputs.push_back(outp);
		}
	}
	end_handle_links();
}

std::unique_ptr<nts::IComponent> (*fptr[4])(const std::string &value);

void Parser::connection_maker()
{
	str_connec = "";
	gate_handler();	
	std::cout << "> " << std::flush;
	std::cin >> str_connec;
	str_connec = trim(str_connec);
	while (str_connec != "exit" && std::cin) {
		if (str_connec == "display") {
			for (unsigned int i = 0; i < _pins_outputs.size(); i++)
				_pins_outputs[i].dump();
		} else if (str_connec == "simulate") {
			for (unsigned int i = 0; i < _pins_outputs.size(); i++)
				_pins_outputs[i].compute(1);
		} else if (str_connec.find("=") != std::string::npos) {
			for (size_t i = 0; i < _pins_inputs.size(); i++) {
				if (_pins_inputs[i].getName() == str_connec.substr(0, str_connec.find("="))) {
					_pins_inputs[i].setPinVal(converter(std::stoi(str_connec.substr(str_connec.find("=") + 1, 1))));
					break;
				}
			}
		} else if(str_connec == "dump") {
			for (unsigned int i = 0; i < _pins_inputs.size(); i++)
				_pins_inputs[i].dump();
			for (unsigned int i = 0; i < _pins_outputs.size(); i++)
				_pins_outputs[i].dump();
			gate->dump();
		} else
			std::cerr << "Command not found!" << std::endl;
		std::cout << "> " << std::flush;
		std::cin >> str_connec;
		str_connec = trim(str_connec);
	}
}

void Parser::end_gate_handler()
{
	if (gate == nullptr) {
		std::cerr << "No gate found in the database" << std::endl;
		exit(84);
	}
	for (std::size_t i = 0; i < _inputs.size(); i++)
		gate->setLink(_links_gate_number[i], _pins_inputs[i], _links_value[i]);
	for (std::size_t i = 0; i < _outputs.size(); i++)
		_pins_outputs[i].setLink(_links_value[_inputs.size()+i], *gate, _links_gate_number[_inputs.size()+i]);
	for (std::size_t i = 0; i < _pins_outputs.size(); i++) {
		_pins_outputs[i].compute(1);
		_pins_outputs[i].dump();
	}

}

void Parser::gate_handler()
{
	gate = nullptr;
	std::vector<std::string> gate_database = {"4001", "4011", "4071", "4081", "4030"};
	fptr[0] = &create4001;
	fptr[1] = &create4011;
	fptr[2] = &create4071;
	fptr[3] = &create4081;
	fptr[4] = &create4030;
	for (std::size_t i = 0; i < gate_database.size(); i++) {
		if (gate_database[i] == _chipset_gate) {
			gate = (fptr[i])(_chipset_gate);
			break;
		}
	}
	end_gate_handler();
}
*/
