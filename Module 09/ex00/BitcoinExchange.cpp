#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string input) {
	if (input.empty())
		throw InvInputException();
	if (!handleCSV())
		throw InvDbException();
	if (!handleInput(input))
		throw InvInputException();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
	this->btcVals = cpy.btcVals;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy) {
	if (this != &cpy)
		this->btcVals = cpy.btcVals;
	return *this;
}

BitcoinExchange::~BitcoinExchange() { }

// FUNCTIONS


bool BitcoinExchange::handleCSV() {
	std::ifstream st("data.csv");
	if (!st.is_open())
		return false;
	std::string line;
	std::getline(st, line);
	while (std::getline(st, line))
	{

		size_t sep = line.find(',');
		if (sep == std::string::npos)
			return false;
		std::string date = line.substr(0, sep);
		double rate = std::strtod(line.substr(sep + 1).c_str(), NULL);
		if (rate < 0 || rate > 2147483647)
			return false;
		if (!valiDate(date))
			return false;
	}
	return true;
}

void numReturns(char c)
{
	switch (c) {
		case 'n':
			std::cerr << "Error: not a positive number." << std::endl;
			break;
		case 'b':
			std::cerr << "Error: " << std::endl;
	}
}

bool BitcoinExchange::handleInput(std::string &input) {
	std::ifstream st(input.c_str());
	std::cout << "Opening " << input.c_str() << std::endl;
	if (!st.is_open())
		return false;
	std::string line;
/*	std::getline(st, line);

	if (line != "date | value")
		return false;*/

	while (std::getline(st, line))
	{
/*		size_t start = line.find_first_not_of(" \t");
		if (start != std::string::npos)
			line = line.substr(start);*/

		size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cout << "Couldn't find pipe in: " << line << std::endl;
			return false;
		}

	}
	return true;
}

bool BitcoinExchange::valiDate(std::string &date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int y, m, d;
	char dash, dash2;

	std::stringstream ss(date);
	ss >> y >> dash >> m >> dash2 >> d;
	if (ss.fail() || dash != '-' || dash2 != '-')
		return false;
	return true;
}

// EXCEPTIONS

const char *BitcoinExchange::InvDbException::what() const throw() {
	return "Error: invalid database file provided. Make sure to have data.csv in the program directory, and use the \"date,exchange_rate\" format.";
}

const char *BitcoinExchange::InvInputException::what() const throw() {
	return "Error: invalid input file provided. Make sure to have it in the program's directory, and use the \"date | value\" format.";
}