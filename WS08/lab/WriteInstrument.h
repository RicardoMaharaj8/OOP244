#pragma once

#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

namespace sdds {
    class WriteInstrument {
    public:
        virtual ~WriteInstrument() = default;;

        virtual void write(const char *) = 0;

        virtual void refill(int) = 0;

        virtual bool filled() const = 0;

        virtual ostream &display(ostream &os) const = 0;
    };
}
