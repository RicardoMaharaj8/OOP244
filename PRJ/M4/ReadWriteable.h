#pragma once

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace sdds
{
    // Abstract base class to provide operator overloads for all child classes
    class ReadWriteable
    {

    public:
        virtual istream &read(istream &is = cin) = 0;

        virtual ostream &write(ostream &os = cout) const = 0;
    };

    ostream &operator<<(ostream &os, const ReadWriteable &rw);

    istream &operator>>(istream &is, ReadWriteable &rw);
}
