#include "Figurine.h"

namespace sdds {
    Figurine::Figurine() {
        *name = 0;
        pose = nullptr;
        price = 0;
        copy = false;
    }

    Figurine::Figurine(const char *n, const char *p, double r) {
        if (n == nullptr || p == nullptr) {
            setEmpty();
        } else {
            setName(n);
            setPose(p);
            setPrice(r);
        }
        copy = false;
    }

    Figurine::~Figurine() {
        delete[] pose;
    }

    void Figurine::setEmpty() {
        *name = 0;
        pose = nullptr;
        price = 0;
    }

    Figurine::Figurine(const Figurine &f) {
        setName(f.name);
        setPrice(f.price);
        if (f.pose == nullptr) {
            pose = nullptr;
        } else {
            setPose(f.pose);
        }
        copy = true;
    }

    void Figurine::setName(const char *n) {
        if (strlen(n) > MAX_NAME_LEN) {
            strncpy(name, n, MAX_NAME_LEN);
        } else {
            strcpy(name, n);
        }
    }

    void Figurine::setPose(const char *p) {
        if (p != nullptr) {
            pose = nullptr;
            pose = new char[strlen(p) + 1];
            strcpy(pose, p);
        }
    }

    void Figurine::setPrice(double r) {
        if (r < 1) {
            price = DEFAULT_PRICE;
        } else {
            price = r;
        }
    }

    ostream &Figurine::display() const {
        if (isEmpty()) {
            cout << "This Figurine has not yet been sculpted" << endl;
            if (isCopy()) {
                cout << "This is a replica of emptiness" << endl;
            }
        } else {
            cout << "Figurine Details" << endl;
            cout << "Name: " << name << endl;
            cout << "Pose: " << pose << endl;
            cout << std::fixed;
            cout << std::setprecision(2);
            cout.precision(2);
            cout << "Price: " << price << endl;
            if (isCopy()) {
                cout << "This is a replica" << endl;
            }
        }
        return cout;
    }

    Figurine::operator bool() const {
        return (*name == 0);
    }

    bool Figurine::isEmpty() const {
        return (*name == 0 || pose == nullptr || price == 0);
    }

    Figurine &Figurine::operator=(const Figurine &f) {
        if (this != &f) {
            setName(f.name);
            setPrice(f.price);
            delete[] pose;
            setPose(f.pose);
            copy = true;
        }
        return *this;
    }

    bool Figurine::isCopy() const {
        return copy;
    }

    const char *Figurine::getName() const {
        return name;
    }

    const char *Figurine::getPose() const {
        return pose;
    }

    double Figurine::getPrice() const {
        return price;
    }

    bool operator==(const Figurine &f1, const Figurine &f2) {
        return strcmp(f1.getName(), f2.getName()) == 0 && strcmp(f1.getPose(), f2.getPose()) == 0 &&
               f1.getPrice() == f2.getPrice() && !f1.isCopy() && !f2.isCopy();
    }
}
