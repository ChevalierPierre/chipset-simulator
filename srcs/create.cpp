/*
** EPITECH PROJECT, 2018
** create.cpp
** File description:
** <..>
*/

#include "create.hpp"

#include "4001.hpp"
#include "4011.hpp"
#include "4071.hpp"
#include "4081.hpp"
#include "4030.hpp"

#include "input.hpp"
#include "output.hpp"
#include "true.hpp"
#include "false.hpp"
#include "clock.hpp"

std::unique_ptr<nts::IComponent> create4001(const std::string &value) noexcept
{
	auto gate = std::unique_ptr<nts::IComponent>(new comp_4001(value));

	return gate;
}

std::unique_ptr<nts::IComponent> create4011(const std::string &value) noexcept
{
	auto gate = std::unique_ptr<nts::IComponent>(new comp_4011(value));

	return gate;
}

std::unique_ptr<nts::IComponent> create4071(const std::string &value) noexcept
{
	auto gate = std::unique_ptr<nts::IComponent>(new comp_4071(value));

	return gate;
}

std::unique_ptr<nts::IComponent> create4081(const std::string &value) noexcept
{
	auto gate = std::unique_ptr<nts::IComponent>(new comp_4081(value));

	return gate;
}

std::unique_ptr<nts::IComponent> create4030(const std::string &value) noexcept
{
	auto gate = std::unique_ptr<nts::IComponent>(new comp_4030(value));

	return gate;
}

std::unique_ptr<nts::IComponent> createInput(const std::string &value) noexcept
{
	auto gate = std::unique_ptr<nts::IComponent>(new input(value));

	return gate;
}

std::unique_ptr<nts::IComponent> createOutput(const std::string &value) noexcept
{
	auto gate = std::unique_ptr<nts::IComponent>(new output(value));

	return gate;
}

std::unique_ptr<nts::IComponent> createTrue(const std::string &value) noexcept
{
	auto gate = std::unique_ptr<nts::IComponent>(new true_cmp(value));

	return gate;
}

std::unique_ptr<nts::IComponent> createFalse(const std::string &value) noexcept
{
	auto gate = std::unique_ptr<nts::IComponent>(new false_cmp(value));

	return gate;
}

std::unique_ptr<nts::IComponent> createClock(const std::string &value) noexcept
{
	auto gate = std::unique_ptr<nts::IComponent>(new clock_cmp(value));

	return gate;
}
