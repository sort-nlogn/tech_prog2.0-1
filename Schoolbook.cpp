#include <iostream>
#include <sstream>
#include "Schoolbook.hpp"

Schoolbook::Schoolbook(){
    std::cout << "Schoolbook default constructor has been called" << std::endl;
}

Schoolbook::Schoolbook(string name, string author, string uni_name, int pages, int cost, int release_year, int class_number): 
    name(name), author(author), uni_name(uni_name), pages(pages), cost(cost), release_year(release_year), class_number(class_number)
{
    std::cout << "Schoolbook constructor with parameters has been called" << std::endl;
}

Schoolbook::Schoolbook(const Schoolbook &other):
    name(other.name), author(other.author), uni_name(other.uni_name), pages(other.pages), cost(other.cost), release_year(other.release_year), class_number(other.class_number)
{
    std::cout << "Schoolbook copy constructor has been called" << std::endl;
}

Schoolbook::~Schoolbook(){
    std::cout << "Schoolbook default destructor has been called" << std::endl;
}

void Schoolbook::set_name_schoolbook(string name){
    check_condition(name.length() > 0, "Name length must be positive"); this->name = name;
}

string Schoolbook::get_name_schoolbook(){
    return this->name;
}

void Schoolbook::set_author_schoolbook(string author){
    check_condition(author.length() > 0, "Author length must be positive"); this->author = author;
}

string Schoolbook::get_author_schoolbook(){
    return this->author;
}

void Schoolbook::set_uni_name_schoolbook(string uni_name){
    check_condition(uni_name.length() > 0, "Author length must be positive"); this->uni_name = uni_name;
}

string Schoolbook::get_uni_name_schoolbook(){
    return this->uni_name;
}

void Schoolbook::set_pages_schoolbook(int pages){
    check_condition(pages > 0, "Pages must be positive number"); this->pages = pages;
}

int Schoolbook::get_pages_schoolbook(){
    return this->pages;
}

void Schoolbook::set_cost_schoolbook(int cost){
    check_condition(cost > 0, "Cost must be positive number"); this->cost = cost;
}

int Schoolbook::get_cost_schoolbook(){
    return this->cost;
}

void Schoolbook::set_release_year_schoolbook(int release_year){
    check_condition(release_year > 0, "Release year must be positive number"); this->pages = pages;
}

int Schoolbook::get_release_year_schoolbook(){
    return this->release_year;
}

void Schoolbook::set_class_number_schoolbook(int class_number){
    check_condition(class_number > 0, "Class number year must be positive number"); this->pages = pages;
}

int Schoolbook::get_class_number_schoolbook(){
    return this->class_number;
}

Stuff::variant Schoolbook::get_type(){
    return variant::SCHOOLBOOK;
}

void Schoolbook::describe(){
    printf("Schoolbook. Name: %s, Author %s, University name: %s, Pages: %d Cost: %d Release year: %d Class number: %d", 
    this->name, this->author, this->uni_name, this->pages, this->cost, this->release_year, this->class_number);
}

std::istream& operator>> (std::istream &in, Schoolbook &b){
    cout << "Name: "; in >> b.name;
    cout << "Author: "; in >> b.author;
    cout << "University name: "; in >> b.uni_name;
    cout << "Pages: "; in >> b.pages;
    cout << "Cost: "; in >> b.cost;
    cout << "Release year: "; in >> b.release_year;
    cout << "Class number: "; in >> b.class_number;
    return in;
}