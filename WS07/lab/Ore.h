#pragma once

#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

namespace sdds {
#define DEFAULT_WEIGHT 300.50
#define DEFAULT_PURITY 20
#define CLASS_LEN 30

    class Ore {
    private:
        double weight;
        int purity;
        char classification[CLASS_LEN];

    public:
        Ore();

        Ore(double w, int p, const char *c = "Unknown");

        bool refine();

        ostream &display(ostream &os) const;

        bool isEmpty() const;

        istream &input(istream &is);
    };

    ostream &operator<<(ostream &os, const Ore &ore);

    istream &operator>>(istream &os, Ore &ore);
}
