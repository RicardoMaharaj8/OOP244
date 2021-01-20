#pragma once

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

#define MAX_NAME_LEN 20
#define DEFAULT_PRICE 25.25

namespace sdds {

    class Figurine {
    private:
        char name[MAX_NAME_LEN + 1];
        char *pose;
        double price;

    public:
        Figurine();

        Figurine(const char *n, const char *p, double r);

        ~Figurine();

        Figurine(const Figurine &f);

        bool isEmpty() const;

        void setName(const char *n);

        void setPose(const char *p);

        void setPrice(double r);

        ostream &display() const;

        operator bool() const;
    };
}
