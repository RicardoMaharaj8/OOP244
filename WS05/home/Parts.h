#pragma once

#include <iostream>
#include <cstring>

using namespace std;

namespace sdds {
#define MIN_FORCE 50
#define MIN_SPEED 25

    class Arms {
    private:
        int force;

    public:
        Arms();

        Arms(int f);

        ~Arms();

        int getForce() const;

        Arms &operator++();

        Arms operator++(int);

        Arms &operator+=(int);
    };

    class Legs {
    private:
        int speed;

    public:
        Legs();

        Legs(int s);

        ~Legs();

        int getSpeed() const;

        Legs &operator-=(int s);
    };

    bool operator>(const Legs &l1, const Legs &l2);

    bool operator<(const Legs &l1, const Legs &l2);

    bool operator>(const Arms &a1, const Arms &a2);

    bool operator<(const Arms &a1, const Arms &a2);
}
