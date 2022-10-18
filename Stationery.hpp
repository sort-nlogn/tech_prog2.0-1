#pragma once
#include "Stuff.hpp"

using namespace  std;

class Stationery: public Stuff{
    private:
        string type, purpose, color;
        int cost;

    public:
        Stationery::Stationery();
        Stationery::Stationery(string type, string purpose, string color, int cost);
        Stationery::Stationery(const Stationery &other);
        Stationery::~Stationery();

        void set_type_stationery(string type);
        string get_type_stationery();
        void set_purpose_stationery(string purpose);
        string get_purpose_stationery();
        void set_color_stationery(string color);
        string get_color_stationery();
        void set_const_stationery(int cost);
        int get_cost_stationery();

        variant get_type() override;
        void describe() override;

        friend istream& operator>> (istream &in, Stationery &stationery); 
};