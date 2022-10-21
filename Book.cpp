#include <iostream>
#include <sstream>
#include "Book.hpp"

Book::Book(){
    std::cout << "Book default constructor has been called" << std::endl;
}

Book::Book(string name, string author, string annotation, string genere, int pages, int cost, int release_year): 
    name(name), author(author), annotation(annotation), genere(genere), pages(pages), cost(cost), release_year(release_year)
{
    std::cout << "Book constructor with parameters has been called" << std::endl;
}

Book::Book(const Book &other):
    name(other.name), author(other.author), annotation(other.annotation), genere(other.genere), pages(other.pages), cost(other.cost), release_year(other.release_year)
{
    std::cout << "Book copy constructor has been called" << std::endl;
}

Book::~Book(){
    std::cout << "Book default destructor has been called" << std::endl;
}

void Book::set_name_book(string name){
    check_condition(name.length() > 0, "Name length must be positive"); this->name = name;
}

string Book::get_name_book(){
    return this->name;
}

void Book::set_author_book(string author){
    check_condition(author.length() > 0, "Author length must be positive"); this->author = author;
}

string Book::get_author_book(){
    return this->author;
}

void Book::set_annotation_book(string annotation){
    check_condition(annotation.length() > 0, "Annotation length must be positive"); this->annotation = annotation;
}

string Book::get_annotation_book(){
    return this->annotation;
}

void Book::set_genere_book(string genere){
    check_condition(genere.length() > 0, "Genere length must be positive"); this->genere = genere;
}

string Book::get_genere_book(){
    return this->genere;
}

void Book::set_pages_book(int pages){
    check_condition(pages > 0, "Pages must be positive number"); this->pages = pages;
}

int Book::get_pages_book(){
    return this->pages;
}

void Book::set_cost_book(int cost){
    check_condition(cost > 0, "Cost must be positive number"); this->cost = cost;
}

int Book::get_cost_book(){
    return this->cost;
}

void Book::set_release_year_book(int release_year){
    check_condition(release_year > 0, "Release year must be positive number"); this->pages = pages;
}

int Book::get_release_year_book(){
    return this->release_year;
}

Stuff::variant Book::get_type(){
    return variant::BOOK;
}

void Book::describe(){
    cout << "Book. Name: " << this->name << " Author: " << this->author<< " Annotation: " << this->annotation << " Genere: " << this->genere << " Cost: " << 
    this->cost << " Pages: " << this->pages << " Release year: " << this->release_year <<endl;
}

std::istream& operator>> (std::istream &in, Book &b){
    cout << "Name: "; in >> b.name;
    cout << "Author: "; in >> b.author;
    cout << "Annotation: "; in >> b.annotation;
    cout << "Genere: "; in >> b.genere;
    cout << "Pages: "; in >> b.pages;
    cout << "Cost: "; in >> b.cost;
    cout << "Release year: "; in >> b.release_year;
    return in;
}
