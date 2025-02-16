#include "ScalarConverter.hpp"

int main() {
	std::string input;
    std::cout << "Enter a literal: ";
    std::cin >> input;

    ScalarConverter::converter(input);
    return 0;
}