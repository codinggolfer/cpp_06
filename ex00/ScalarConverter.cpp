#include "ScalarConverter.hpp"
#include <string>
#include <iomanip>
#include <limits>
#include <numbers>


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter& copy) {
	if (this != &copy)
		return ;
}

const ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter() {}



void convertChar(const char c) {
    std::cout << "char: " << (std::isprint(static_cast<unsigned char>(c)) ? "'" + std::string(1,c) + "'" : "Non displayable") << "\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << ".0f\n";
    std::cout << "double: " << static_cast<double>(c) << ".0\n";
    return;
}

void convertInt(const std::string literal) {
    int i = 0;
    try {
        i = std::stoi(literal);
        std::cout << "char: " << (std::isprint(static_cast<unsigned char>(i)) ? "'" + std::string(1, static_cast<char>(i)) + "'" : "Non displayable") << "\n";
        std::cout << "int: " << i << "\n";
        std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(i) << "f\n";
        std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(i) << "\n";
    }
    catch (std::exception &e) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}

//-inf, +inf and nan, -inff, +inff and nanf

void convertFloatOrDouble(const std::string literal) {
    double d;
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        d = std::stof(literal);
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << (d) << "f\n";
        std::cout << "double: " << static_cast<double>(d) << "\n";
        return ;
    }
    else if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        d = std::stod(literal);
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << static_cast<float>(d) << "f\n";
        std::cout << "double: " << d << "\n";
        return ;
    }
    try {
        if (literal.back() == 'f') {
            d = std::stof(literal);
            std::cout << "char: " << (std::isprint(static_cast<unsigned char>(d)) ? "'" + std::string(1, static_cast<char>(d)) + "'" : "Non displayable") << "\n";
            std::cout << "int: " << static_cast<int>(d) << "\n";
            std::cout << "float: " << std::setprecision(2) << std::fixed << d << "f\n";
            std::cout << "double: " << std::setprecision(2) << std::fixed << static_cast<double>(d) << "\n";
            return;
        }
        else {
            d = std::stod(literal);
            std::cout << "char: " << (std::isprint(static_cast<unsigned char>(d)) ? "'" + std::string(1, static_cast<char>(d)) + "'" : "Non displayable") << "\n";
            std::cout << "int: " << static_cast<int>(d) << "\n";
            std::cout << "float: " << std::setprecision(2) << std::fixed << static_cast<float>(d) << "f\n";
            std::cout << "double: " << std::setprecision(2) << std::fixed <<  d << "\n";
        }
    }
    catch (std::exception &e) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}

bool isDoubledot(std::string str) {
	int dd = 0;
	int i = 0;
	while (str[i]) {
		if (str[i] == '.')
			dd++;
		i++;
	}
	if (dd == 1)
		return true;
	else
		return false;
}

void ScalarConverter::converter(std::string literal) {
    std::string valid = "0123456789.f-+";
	bool islegit = true;
    if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        convertChar(literal[1]);
    }
    else if (literal.find('.') != std::string::npos || literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "nan") {
		if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "nan") {
			convertFloatOrDouble(literal);
			return ;
		}
            for (size_t i = 0; i < literal.length(); i++) {
                if (!valid.contains(literal[i])) {
					islegit = false;
					std::cout << "Error: can't convert\n";
                    return ;
                }
            }
			islegit = isDoubledot(literal);
			if (islegit)
            	convertFloatOrDouble(literal);
			if (!islegit)
				std::cout << "Error: can't convert\n";
    }
    else {
        convertInt(literal);
    }
    
}
