#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer& copy) {
	if (this != &copy)
		return ;
}

const Serializer& Serializer::operator=(const Serializer& other) {
	if (this != &other)
		return *this;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}