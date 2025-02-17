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
    /* data */
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
