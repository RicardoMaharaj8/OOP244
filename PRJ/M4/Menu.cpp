#include "Menu.h"

namespace sdds
{
    // MenuItem START
    MenuItem::MenuItem()
    {
        name = nullptr;
    }

    MenuItem::MenuItem(const char *c)
    {
        name = new char[strlen(c) + 1];
        strcpy(name, c);
    }

    MenuItem::~MenuItem()
    {
        delete[] name;
    }

    MenuItem::operator bool() const
    {
        return name != nullptr;
    }

    ostream &MenuItem::operator<<(ostream &os)
    {
        os << name;
        return os;
    }

    MenuItem::operator const char *() const
    {
        return name;
    }
    // MenuItem END

    // Menu START
    Menu::Menu()
    {
        count = 0;
    }

    Menu::Menu(const char *c)
    {
        menuName.name = new char[strlen(c) + 1];
        strcpy(menuName.name, c);
        count = 0;
    }

    unsigned int Menu::operator~() const
    {
        return getSelection();
    }

    ostream &Menu::displayTitle(ostream &os) const
    {
        if (menuName.name != nullptr)
        {
            os << menuName.name;
        }
        return os;
    }

    ostream &Menu::displayMenu(ostream &os) const
    {
        if (menuName.name != nullptr)
        {
            displayTitle(os);
            os << ":" << std::endl;
        }
        if (count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                os << " " << (i + 1) << "- " << list[i].name << endl;
            }
            os << " 0- Exit" << endl
               << "> ";
        }
        return os;
    }

    Menu &Menu::operator<<(const char *c)
    {
        if (count < 20)
        {
            list[count].name = new char[strlen(c) + 1];
            strcpy(list[count].name, c);
            count++;
        }
        return *this;
    }

    unsigned int Menu::getSelection() const
    {
        int choice = 0;
        displayMenu(cout);
        if (count > 0)
        {
            cin >> choice;
            while (cin.fail() || choice > count || choice < 0)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid Selection, try again: ";
                cin >> choice;
            }
        }
        return unsigned(choice);
    }

    const char *Menu::operator[](int i) const
    {
        while (i > count)
        {
            i -= count;
        }
        return list[i].name;
    }

    Menu::operator int() const
    {
        return count;
    }

    Menu::operator unsigned int() const
    {
        return count;
    }

    Menu::operator bool() const
    {
        return count > 0;
    }

    ostream &operator<<(ostream &os, const Menu &m)
    {
        m.displayTitle(os);
        return os;
    }
    // Menu END
}
