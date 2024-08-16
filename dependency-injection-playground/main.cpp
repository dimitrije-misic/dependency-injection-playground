// dependency-injection-playground.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "implementations.h"

int main()
{
    cisim::FordMustang new_mustang{ cisim::V6Turbo{ cisim::Garrett{} }, cisim::Automatic{} };
    cisim::FordMustang old_mustang{ cisim::V8{}, cisim::Manual{} };

    std::cout << "Hello World!\n";
}