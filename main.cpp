#include <iostream>
#include <string>

class Stuff{

};

class Book: public Stuff{
    std::string name, author, annotation, genere, release_year;
    int pages, cost;
};

class Schoolbook: public Stuff{
    std::string uni_name;
};

class Stationery: public Stuff{
    
};

int main(){
    return 0;
}