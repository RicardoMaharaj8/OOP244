#include "Flower.h"

namespace sdds {
    Flower::Flower() {
        f_name = nullptr;
        f_colour = nullptr;
        f_price = 0;
    }

    Flower::Flower(const char *name, const char *colour, double price) {
        if (name == nullptr || colour == nullptr || price <= 0) {
            setEmpty();
        } else {
            f_name = new char[strlen(name) + 1];
            strcpy(f_name, name);
            f_colour = new char[strlen(colour) + 1];
            strcpy(f_colour, colour);
            f_price = price;
        }
    }

    Flower::~Flower() {
        if (isEmpty()) {
            cout << "An unknown flower has departed..." << endl;
        } else {
            cout << f_colour << " " << f_name << " has departed..." << endl;
            delete[] f_name;
            delete[] f_colour;
        }
    }

    const char *Flower::name() const {
        return f_name;
    }

    const char *Flower::colour() const {
        return f_colour;
    }

    double Flower::price() const {
        return f_price;
    }

    bool Flower::isEmpty() const {
        return (f_price <= 0 || f_colour == nullptr || f_name == nullptr || strcmp(f_name, "") == 0 ||
                strcmp(f_colour, "") == 0);
    }

    void Flower::setEmpty() {
        f_name = nullptr;
        f_colour = nullptr;
        f_price = 0;
    }

    void Flower::setName(const char *prompt) {
        cout << prompt;
        char name[26];
        read(name, 25, "A flower's name is limited to 25 characters... Try again: ");
        f_name = new char[strlen(name) + 1];
        strcpy(f_name, name);
    }

    void Flower::setColour(const char *prompt) {
        cout << prompt;
        char col[16];
        read(col, 15, "A flower's colour is limited to 15 characters... Try again: ");
        f_colour = new char[strlen(col) + 1];
        strcpy(f_colour, col);
    }

    void Flower::setPrice(const char *prompt) {
        cout << prompt;
        cin >> f_price;
        if (f_price < 0) {
            cout << "A flower's price is a non-negative number... Try again: ";
            f_price = 0;
            cin >> f_price;
        }
    }

    void Flower::setFlower() {
        cout << "Beginning the birth of a new flower..." << endl;
        setName("Enter the flower's name... : ");
        setColour("Enter the flower's colour... : ");
        setPrice("Enter the flower's price... : ");
        cout << "The flower's current details..." << endl;
        display();
    }

    ostream &Flower::display() const {
        if (isEmpty()) {
            cout << "This is an empty flower..." << endl;
        } else {
            cout << "Flower: " << f_colour << " " << f_name << " Price: " << f_price << endl;
        }
        return cout;
    }
}
