#include "Serializer.hpp"

int main () {
	Data dt = { 1, "Hello World" };

	std::cout << "--- Before ---" << std::endl;
	std::cout << "ID: " << dt.id << std::endl;
	std::cout << "Name: " << dt.name << std::endl << std::endl;

	uintptr_t raw = Serializer::serialize(&dt);
	Data* newDt = Serializer::deserialize(raw);

	std::cout << "--- After ---" << std::endl;
	std::cout << "ID: " << newDt->id << std::endl;
	std::cout << "Name: " << newDt->name << std::endl;
}