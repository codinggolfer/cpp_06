#pragma once

#include <iostream>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter& copy);
	const ScalarConverter& operator=(ScalarConverter& const other);
public:
	static void converter(std::string);
	~ScalarConverter();
};
