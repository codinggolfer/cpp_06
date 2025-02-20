#include "ScalarConverter.hpp"
#include <signal.h>

int main(int ac, char** av) {
	if (ac != 1)
    	ScalarConverter::converter(av[1]);
	else
		std::cout << "invalid amount of arguments\n";
    return 0;
}