/*
** EPITECH PROJECT, 2018
** test.cpp
** File description:
** <..>
*/

#include "nanotekspice.hpp"

#include "or_gate.hpp"
#include "xor_gate.hpp"
#include "and_gate.hpp"
#include "nor_gate.hpp"
#include "nand_gate.hpp"

#include "4001.hpp"

#include "input.hpp"
#include "output.hpp"

void test_gate()
{
	or_gate	OR1(1, nts::TRUE, 2, nts::TRUE, 3);
	or_gate	OR2(1, nts::TRUE, 2, nts::FALSE, 3);
	or_gate	OR3(1, nts::FALSE, 2, nts::TRUE, 3);
	or_gate	OR4(1, nts::FALSE, 2, nts::FALSE, 3);

	xor_gate	XOR1(1, nts::TRUE, 2, nts::TRUE, 3);
	xor_gate	XOR2(1, nts::TRUE, 2, nts::FALSE, 3);
	xor_gate	XOR3(1, nts::FALSE, 2, nts::TRUE, 3);
	xor_gate	XOR4(1, nts::FALSE, 2, nts::FALSE, 3);

	and_gate	AND1(1, nts::TRUE, 2, nts::TRUE, 3);
	and_gate	AND2(1, nts::TRUE, 2, nts::FALSE, 3);
	and_gate	AND3(1, nts::FALSE, 2, nts::TRUE, 3);
	and_gate	AND4(1, nts::FALSE, 2, nts::FALSE, 3);

	nor_gate	NOR1(1, nts::TRUE, 2, nts::TRUE, 3);
	nor_gate	NOR2(1, nts::TRUE, 2, nts::FALSE, 3);
	nor_gate	NOR3(1, nts::FALSE, 2, nts::TRUE, 3);
	nor_gate	NOR4(1, nts::FALSE, 2, nts::FALSE, 3);

	nand_gate	NAND1(1, nts::TRUE, 2, nts::TRUE, 3);
	nand_gate	NAND2(1, nts::TRUE, 2, nts::FALSE, 3);
	nand_gate	NAND3(1, nts::FALSE, 2, nts::TRUE, 3);
	nand_gate	NAND4(1, nts::FALSE, 2, nts::FALSE, 3);

	std::cout << "TRUE | TRUE = " << OR1.compute(0) << std::endl;
	std::cout << "TRUE | FALSE = " << OR2.compute(0) << std::endl;
	std::cout << "FALSE | TRUE = " << OR3.compute(0) << std::endl;
	std::cout << "FALSE | FALSE = " << OR4.compute(0) << std::endl;
	std::cout << "TRUE ^ TRUE = " << XOR1.compute(0) << std::endl;
	std::cout << "TRUE ^ FALSE = " << XOR2.compute(0) << std::endl;
	std::cout << "FALSE ^ TRUE = " << XOR3.compute(0) << std::endl;
	std::cout << "FALSE ^ FALSE = " << XOR4.compute(0) << std::endl;
	std::cout << "TRUE & TRUE = " << AND1.compute(0) << std::endl;
	std::cout << "TRUE & FALSE = " << AND2.compute(0) << std::endl;
	std::cout << "FALSE & TRUE = " << AND3.compute(0) << std::endl;
	std::cout << "FALSE & FALSE = " << AND4.compute(0) << std::endl;
	std::cout << "!(TRUE | TRUE) = " << NOR1.compute(0) << std::endl;
	std::cout << "!(TRUE | FALSE) = " << NOR2.compute(0) << std::endl;
	std::cout << "!(FALSE | TRUE) = " << NOR3.compute(0) << std::endl;
	std::cout << "!(FALSE | FALSE) = " << NOR4.compute(0) << std::endl;
	std::cout << "!(TRUE & TRUE) = " << NAND1.compute(0) << std::endl;
	std::cout << "!(TRUE & FALSE) = " << NAND2.compute(0) << std::endl;
	std::cout << "!(FALSE & TRUE) = " << NAND3.compute(0) << std::endl;
	std::cout << "!(FALSE & FALSE) = " << NAND4.compute(0) << std::endl;

}

void test_input_output()
{
	input	in("a");
	input	in2("b");
	output	out("s");
	comp_4001	gate("gate");;
	nts::IComponent	*other;

	//in.setPinVal(nts::TRUE);
	//out.setLink(1, in, 1);
	//out.compute(1);
	//out.dump();

	other = &gate;
	in.setPinVal(nts::TRUE);
	in2.setPinVal(nts::FALSE);
	//out.compute(1);
	//out.dump();

	other->setLink(1, in, 1);
	other->setLink(2, in2, 1);
	out.setLink(1, *other, 3);
	out.compute(1);
	other->dump();
}
