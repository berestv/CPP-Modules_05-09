#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string input) {
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
	std::ifstream ist();

}

bool BitcoinExchange::checkInput(std::string input) {

}

// EXCEPTIONS

const char *BitcoinExchange::InvDbException::what() const throw() {
	return "Error: invalid database file provided. Make sure to have \"data.csv\" in the program's directory.";
}
