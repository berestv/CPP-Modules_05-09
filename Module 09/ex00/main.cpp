#include "BitcoinExchange.hpp"

bool checkExtension(const std::string& file)
{
	size_t i = file.rfind('.');
	if (i == std::string::npos)
		return false;
	std::string ext = file.substr(i);
	if (ext == ".txt")
		return true;
	return false;
}

int main (int argc, char* argv[])
{
	if (argc == 2)
	{
		if (checkExtension(argv[1]))
		{
			std::ifstream st(argv[1]);
			if (st.is_open())
			{
				std::cout << "File exists! Comparing..." << std::endl;

				try {
					BitcoinExchange btc(argv[1]);
				} catch (std::exception &e) {
					std::cerr << e.what() << std::endl;
				}
				st.close();
			} else
				std::cerr << "Error: could not open file." << std::endl;
		} else
			std::cerr << "Error: wrong file extension! Please use .txt files." << std::endl;
	} else
		std::cerr << "Error: wrong number of arguments!" << std::endl;
	return 0;
}
