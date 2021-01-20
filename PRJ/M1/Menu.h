#pragma once

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace sdds
{
    class MenuItem
    {
    public:
        char *name;

        MenuItem();

        MenuItem(const char *c);

        ~MenuItem();

        operator bool() const;

        operator const char *() const;

        ostream &operator<<(ostream &os);
    };

    class Menu
    {
    public:
        MenuItem menuName;
        int count;
        MenuItem list[20];

        friend MenuItem;

        Menu();

        Menu(const char *c);

        ostream &displayTitle(ostream &os) const;

        ostream &displayMenu(ostream &os) const;

        Menu &operator<<(const char *c);

        unsigned int getSelection() const;

        const char *operator[](int i) const;

        unsigned int operator~() const;

        operator int() const;

        operator unsigned int() const;

        operator bool() const;
    };

    ostream &operator<<(ostream &os, const Menu &m);
}
