#pragma once
#include "Stuff.hpp"

using namespace std;

class Book: public Stuff{
    private:
        std::string name, author, annotation, genere;
        int pages, cost, release_year;
    
    public:
        Book();
        Book(string name, string author, string annotation, string genere, int pages, int cost, int release_year);
        Book(const Book &other);
        ~Book();

        string get_name_book();
        void set_name_book(string name);

        string get_author_book();
        void set_author_book(string author);
        
        void set_annotation_book(string annotation);
        string get_annotation_book();

        void set_genere_book(string genere);
        string get_genere_book();

        void set_pages_book(int pages);
        int get_pages_book();

        void set_cost_book(int cost);
        int get_cost_book();

        void set_release_year_book(int release_year);
        int get_release_year_book();

        variant get_type() override;
        void describe() override;

        friend istream& operator>> (istream &in, Book &book); 
};