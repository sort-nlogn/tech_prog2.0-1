#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include "Stuff.hpp"
#include "Stationery.hpp"
#include "Book.hpp"
#include "Schoolbook.hpp"

using namespace std;

class Keeper{
    private:
        struct Node{
            Stuff *stuff;
            Node *next;
        };

        Node *head = nullptr;
        Node *tail = nullptr;
        int size;
    
    public:
        Keeper();
        ~Keeper();

        void add(Stuff *stuff);
        void print();
        void remove(int pos);
        void save_to_file(fstream &in, string path);
        void load_from_file(fstream &in, string path);
        void edit(int pos);
        Stuff *get(int pos);
};