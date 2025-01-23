#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
private:
	std::map<std::string, double> btcVals;

public:
	BitcoinExchange(std::string &input);
	BitcoinExchange(const BitcoinExchange& cpy);
	BitcoinExchange &operator=(const BitcoinExchange &cpy);
	~BitcoinExchange();

	bool handleCSV();
	bool handleInput(std::string &input);
	static bool valiDate(std::string &date);

	class InvDbException : public std::exception {
		virtual const char* what() const throw();
	};
};

#endif // BITCOINEXCHANGE_HPP
