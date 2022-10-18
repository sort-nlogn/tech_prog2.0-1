#pragma once
#include <iostream>

class Stuff{
    public:
        enum variant{
            STATIONERY,
            BOOK,
            SCHOOLBOOK
        };

    Stuff();
    ~Stuff();

    virtual variant get_type() = 0;
    virtual void describe() = 0;
    void check_condition(bool condition, std::string err_message);
};