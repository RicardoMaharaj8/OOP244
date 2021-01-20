#pragma once

#include <iostream>
#include <cstring>

using namespace std;

namespace sdds {
#define MIN_FORCE 50

    class Arms {
    public:
        int force;

        Arms();

        Arms(int f);

        ~Arms();

        int getForce() const;

        Arms &operator++();

        Arms operator++(int);

        Arms &operator+=(int);
    };
}
