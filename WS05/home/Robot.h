#pragma once

#include "Parts.h"

namespace sdds {
    class Robot {
    private:
        char nickname[11];
        int durability;
        Arms arms;
        Legs legs;

    public:
        Robot();

        Robot(const char *name, int f, int dur, int s);

        ~Robot();

        ostream &display() const;

        operator bool() const;

        Arms getArms() const;

        Legs getLegs() const;

        Robot &operator-=(int dm);
    };

    void box(Robot &r1, Robot &r2);
}
