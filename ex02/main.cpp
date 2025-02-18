#include "Base.hpp"
#include "ClassA.hpp"
#include "ClassC.hpp"
#include "ClassB.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>


void identify(Base* p) {
    if (dynamic_cast<ClassA*>(p))
        std::cout << "ClassA\n";
    else if (dynamic_cast<ClassB*>(p))
        std::cout << "ClassB\n";
    else if (dynamic_cast<ClassC*>(p))
        std::cout << "ClassC\n";
}

void identify(Base& p) {
    try {
        ClassA &a = dynamic_cast<ClassA&>(p);
        (void)a;
        std::cout << "ClassA\n";
    }
    catch (std::exception &e) {
        try {
            ClassB &b = dynamic_cast<ClassB&>(p);
            (void)b;
            std::cout << "ClassB\n";
        }
        catch (std::exception &e) {
            try {
                ClassC &c = dynamic_cast<ClassC&>(p);
                (void)c;
                std::cout << "ClassC\n";
            }
            catch (std::exception &e) {
                std::cout << "Unknown\n";
            }
        }
    }
}

Base* generate() {
    std::srand(std::time(0));
    size_t time = std::rand() % 3;
    switch (time)
    {
    case 0:
        return new ClassA();
    case 1:
        return new ClassB();
    case 2:
        return new ClassC();
    default:
        break;
    }
    return nullptr;
}

int main() {
    Base *p = generate();
	Base *c = nullptr;
    identify(p);
    identify(*p);
    identify(*c);
	delete p;
    return 0;
}