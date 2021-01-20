#pragma once

#include <iostream>
#include <iomanip>
#include <cstring>

#include "utils.h"

using namespace std;

#define NAME_MAX_LEN 25
#define COL_MAX_LEN 15

namespace sdds {
    class Flower {
    private:
        char *f_name;
        char *f_colour;
        double f_price;

    public:
        Flower();

        Flower(const char *name, const char *colour, double price);

        ~Flower();

        const char *name() const;

        const char *colour() const;

        double price() const;

        bool isEmpty() const;

        void setEmpty();

        void setName(const char *prompt);

        void setColour(const char *prompt);

        void setPrice(const char *prompt);

        void setFlower();

        ostream &display() const;

        void setName(const char *name, int len);

        void setColour(const char *colour, int len);

        void setPrice(double price);
    };
}
