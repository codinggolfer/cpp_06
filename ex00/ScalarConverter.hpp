#pragma once

#include <iostream>
#include <limits>
#include <cmath>
#include <sstream>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter& copy);
	const ScalarConverter& operator=(const ScalarConverter&  other);
public:
	static void converter(std::string);
	~ScalarConverter();
};
