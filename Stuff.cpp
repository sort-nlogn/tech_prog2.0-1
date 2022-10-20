#include <iostream>
#include "Stuff.hpp"

Stuff::Stuff(){
    std::cout << "Stuff default constructor has been called" << std::endl;
}

Stuff::~Stuff(){
    std::cout << "Stuff default destructor has been called" << std::endl;
}

void Stuff::check_condition(bool condition, std::string err_message){
    if (!condition) throw std::runtime_error(err_message);
}