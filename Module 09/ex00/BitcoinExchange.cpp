#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &input) {
	if (!handleCSV())
		throw InvDbException();
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
	while (std::getline(st, line))
	{
		size_t sep = line.find(',');
		if (sep == std::string::npos)
			return false;
		std::string date = line.substr(0, sep);
		double rate = std::strtod(line.substr(sep + 1).c_str(), NULL);
		if (rate < 0 || rate > 2147483647)
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
			std::
	}
}

bool BitcoinExchange::handleInput(std::string &input) {
	std::ifstream st(input);
	std::string line;

	std::getline(st, line);
	if (line != "date | value")
		while (std::getline(st, line))
		{
			size_t pipe = line.find('|');
			if (pipe == std::string::npos)
				return false;

		}
	return true;
}

bool BitcoinExchange::valiDate(std::string &date) {
	if (date.size() != 10 || date[4] != '-' || date[8] != '-')
		return false;

	int y, m, d;
	char dash, dash2;

	std::stringstream ss(date);
	ss >> y >> dash >> m >> dash2 >> d;
	if (ss.fail() || dash != '-' || dash2 != '-')
		return false;

	if (y < 1900 || y > 2025)
		return false;
}

// EXCEPTIONS

const char *BitcoinExchange::InvDbException::what() const throw() {
	return "Error: invalid database file provided. Make sure to have \"data.csv\" in the program's directory, and use the \"date | value\" format.";
}