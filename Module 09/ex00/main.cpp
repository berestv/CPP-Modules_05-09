#include "BitcoinExchange.hpp"

bool checkExtension(std::string file)
{
	int i = file.rfind('.');
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
			std::ofstream ofs;
			ofs.open(argv[1]);
			if (ofs.is_open())
			{

			} else
				std::cerr << "Error: file does not exist!" << std::endl;
		} else
			std::cerr << "Error: wrong file extension! Please use .txt files." << std::endl;
	} else
		std::cerr << "Error: wrong number of arguments!" << std::endl;
}
