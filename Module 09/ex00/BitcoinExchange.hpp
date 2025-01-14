#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, double> btcVals;

public:
	BitcoinExchange();
	~BitcoinExchange();
};

#endif // BITCOINEXCHANGE_HPP
