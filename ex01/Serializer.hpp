#pragma once

#include <iostream>

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

class Serializer
{
private:
    Serializer();
	Serializer(Serializer& copy);
	const Serializer& operator=(const Serializer&  other);

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
