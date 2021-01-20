#pragma once

#include "Ore.h"

namespace sdds {
#define DEFAULT_MOHS 2.5
#define NAME_LEN 10

    class Metal : public Ore {
    protected:
        char name[NAME_LEN];
        double mohs;

    public:
        Metal();

        Metal(double w, int p, const char *c, const char *n, double m);

        void refine();

        ostream &display(ostream &os) const;

        istream &input(istream &is);
    };

    ostream &operator<<(ostream &os, const Metal &met);

    istream &operator>>(istream &os, Metal &met);
}
