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
        bool copy;

    public:
        Figurine();

        Figurine(const char *n, const char *p, double r);

        ~Figurine();

        Figurine(const Figurine &f);

        Figurine &operator=(const Figurine &f);

        bool isEmpty() const;

        void setName(const char *n);

        void setPose(const char *p);

        void setPrice(double r);

        void setEmpty();

        ostream &display() const;

        operator bool() const;

        bool isCopy() const;

        const char *getName() const;

        const char *getPose() const;

        double getPrice() const;
    };

    bool operator==(const Figurine &f1, const Figurine &f2);
}
