#pragma once
#include "Stuff.hpp"

using namespace std;

class Schoolbook: public Stuff{
    private:
        std::string name, author, uni_name;
        int pages, cost, release_year, class_number;
    
    public:
        Schoolbook();
        Schoolbook(string name, string author, string uni_name, int pages, int cost, int release_year, int class_number);
        Schoolbook(const Schoolbook &other);
        ~Schoolbook();

        string get_name_schoolbook();
        void set_name_schoolbook(string name);

        string get_author_schoolbook();
        void set_author_schoolbook(string author);

        void set_uni_name_schoolbook(string annotation);
        string get_uni_name_schoolbook();

        void set_class_number_schoolbook(int class_number);
        int get_class_number_schoolbook();

        void set_pages_schoolbook(int pages);
        int get_pages_schoolbook();

        void set_cost_schoolbook(int cost);
        int get_cost_schoolbook();

        void set_release_year_schoolbook(int release_year);
        int get_release_year_schoolbook();

        variant get_type() override;
        void describe() override;

        friend istream& operator>> (istream &in, Schoolbook &book); 
};