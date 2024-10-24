#include "Serializer.hpp"

Serialzier::Serialzier() {}
Serialzier::Serialzier(const Serialzier &ser) { (void)ser; }
Serialzier &Serialzier::operator=(const Serialzier &ser) { (void)ser; return *this; }
Serialzier::~Serialzier() {}

// FUNCTIONS

uintptr_t Serialzier::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serialzier::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
