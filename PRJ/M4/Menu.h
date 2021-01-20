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
        // char pointer for DMA name

        MenuItem();
        // no arg constructor for default values

        MenuItem(const char *c);
        // one arg constructor to assign the name

        ~MenuItem();
        // destructor to delete DMA name

        operator bool() const;
        // bool operator for class uses with if statements

        operator const char *() const;
        // char operator for easy name data retrieval

        ostream &operator<<(ostream &os);
        // output operator for printing the name data
    };

    class Menu
    {
    public:
        MenuItem menuName; // single menuitem for holding a name

        int count; // counter to keep track of number of items

        MenuItem list[20]; // array of MenuItem for hold different items

        friend MenuItem; // allows Menu class access to MenuItem private data

        Menu();
        // no arg constructor for default values

        Menu(const char *c);
        // one arg constructor to set name with DMA

        ostream &displayTitle(ostream &os) const;
        // displays menuName data

        ostream &displayMenu(ostream &os) const;
        // prints the menu

        Menu &operator<<(const char *c);
        // assigns the name of a menuitem

        unsigned int getSelection() const;
        // accepts input from user with validation to choose menu option

        const char *operator[](int i) const;
        // returns item at position i and sets counter back

        unsigned int operator~() const;
        // returns getSelection()

        operator int() const;
        // returns the count

        operator unsigned int() const;
        // returns the count

        operator bool() const;
        // returns true if count is greater than zero ( menu not empty )
    };

    ostream &operator<<(ostream &os, const Menu &m);
    // helper to displayTitle()
}
