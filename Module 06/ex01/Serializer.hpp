#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data {
	int id;
	std::string name;
};

class Serializer {
private:
	Serializer();
	Serializer(const Serializer& ser);
	Serializer &operator=(const Serializer& ser);
	~Serializer();

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};

#endif //SERIALIZER_HPP
