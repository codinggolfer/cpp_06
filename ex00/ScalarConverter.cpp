#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter& copy) {
	if (this != &copy)
		return ;
}

const ScalarConverter& ScalarConverter::operator=(ScalarConverter& const other) {
	if (this != &other)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter() {}


void ScalarConverter::converter(std::string literal) {
	 if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'') {
            char c = literal[1];
            std::cout << "char: '" << c << "'\n";
            std::cout << "int: " << static_cast<int>(c) << "\n";
            std::cout << "float: " << static_cast<float>(c) << ".0f\n";
            std::cout << "double: " << static_cast<double>(c) << ".0\n";
            return;
        }
}


