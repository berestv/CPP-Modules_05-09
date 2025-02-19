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
		btcVals[date] = rate;
	}
	st.close();
	return true;
}

bool BitcoinExchange::handleInput(std::string &input) {
	std::ifstream st(input.c_str());
	if (!st.is_open())
		return false;
	std::string line;

	std::getline(st, line);
	while (std::getline(st, line))
	{
		size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pipe);
		std::string value = line.substr(pipe + 1);
		char* ptr;
		double val = std::strtod(value.c_str(), &ptr);

		if (!valiDate(date) || *ptr != '\0')
			std::cerr << "Error: bad input => " << line << std::endl;
		else if (val < 0)
			std::cerr << "Error: not a positive number." << std::endl;
		else if (val > 2147483647)
			std::cerr << "Error: too large a number." << std::endl;
		else
		{
			std::map<std::string, double>::iterator it = btcVals.upper_bound(date);
			it--;
			double mult = it->second;
			std::cout << date << " => " << val << " = " << val * mult << std::endl;
		}
	}
	st.close();
	return true;
}

bool BitcoinExchange::valiDate(std::string &date) {
	if (date.size() == 11 && date[10] == ' ')
		date.erase(10);
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int y, m, d;
	char dash, dash2;

	std::stringstream ss(date);
	ss >> y >> dash >> m >> dash2 >> d;
	if (ss.fail() || dash != '-' || dash2 != '-' || y < 2009 || y > 3000 || m > 12 || m < 1 || d > 31 || d < 1)
		return false;

	int mDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		mDays[1] = 29;
	if (d > mDays[m - 1])
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