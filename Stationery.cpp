#include <iostream>
#include <sstream>
#include "Stationery.hpp"

Stationery::Stationery(){
    std::cout << "Stationery default constructor has been called" << std::endl;
}

Stationery::Stationery(string type, string purpose, string color, int cost): 
    type(type), purpose(purpose), color(color), cost(cost)
{
    std::cout << "Stationary constructor with parameters has been called" << std::endl;
}

Stationery::Stationery(const Stationery &other):
    type(other.type), purpose(other.purpose), color(other.color), cost(other.cost)
{
    std::cout << "Stationary copy constructor has been called" << std::endl;
}

Stationery::~Stationery(){
    std::cout << "Stationary default destructor has been called" << std::endl;
}

void Stationery::set_type_stationery(string type){
    check_condition(type.length() > 0, "Type length must be positive"); this->type = type;
}

string Stationery::get_type_stationery(){
    return this->type;
}

void Stationery::set_purpose_stationery(string purpose){
    check_condition(purpose.length() > 0, "Purpose length must be positive"); 
    this->purpose = purpose;
}

string Stationery::get_purpose_stationery(){
    return this->purpose;
}

void Stationery::set_color_stationery(string color){
    this->color = color;
}

string Stationery::get_color_stationery(){
    return this->color;
}

void Stationery::set_const_stationery(int cost){
    check_condition(cost > 0, "Cost must be positive"); 
}

int Stationery::get_cost_stationery(){
    return this->cost;
}

Stuff::variant Stationery::get_type(){
    return variant::STATIONERY;
}

void Stationery::describe(){
    printf("Stationey. Type: %s, Purpose %s, Color: %s, Cost: %d", 
    this->type, this->purpose, this->color, this->cost);
}

std::istream& operator>> (std::istream &in, Stationery &st){
    cout << "Type: "; in >> st.type;
    cout << "Purpose: "; in >> st.purpose;
    cout << "Color: "; in >> st.color;
    cout << "Cost: "; in >> st.cost;
    return in;
}


