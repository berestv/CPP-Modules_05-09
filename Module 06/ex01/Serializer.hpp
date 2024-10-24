#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data {
	int id;
	std::string name;
};

class Serialzier {
private:
	Serialzier();
	Serialzier(const Serialzier& ser);
	Serialzier &operator=(const Serialzier& ser);
	~Serialzier();

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};

#endif //SERIALIZER_HPP
