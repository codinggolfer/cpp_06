#include "ScalarConverter.hpp"
#include <signal.h>

int main() {
	std::string input;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
    std::cout << "Enter a literal: ";
    std::cin >> input;

    ScalarConverter::converter(input);
    return 0;
}