#pragma once

#include "Parts.h"

namespace sdds {

    class Robot {
    public:
        char nickname[11];
        int durability;
        Arms arms;

        Robot();

        Robot(const char *name, int f, int dur);

        ~Robot();

        ostream &display() const;

        operator bool() const;
    };
}
