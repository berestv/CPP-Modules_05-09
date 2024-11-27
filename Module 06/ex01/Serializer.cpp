#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &ser) { (void)ser; }
Serializer &Serializer::operator=(const Serializer &ser) { (void)ser; return *this; }
Serializer::~Serializer() {}

// FUNCTIONS

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
