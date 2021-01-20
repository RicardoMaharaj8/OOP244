#include "Figurine.h"

namespace sdds {
    Figurine::Figurine() {
        strcpy(name, "");
        pose = nullptr;
        price = 0;
    }

    Figurine::Figurine(const char *n, const char *p, double r) {

        if (n == nullptr || strcmp(n, "") == 0) {
            strcpy(name, "");
        } else {
            strcpy(name, n);
        }

        if (p == nullptr || strcmp(p, "") == 0) {
            pose = nullptr;
        } else {
            pose = nullptr;
            pose = new char[strlen(p) + 1];
            strcpy(pose, p);
            pose[strlen(pose)] = '\0';
        }
        if (r < 1) {
            price = DEFAULT_PRICE;
        } else {
            price = r;
        }
    }

    Figurine::~Figurine() {
        delete[] pose;
    }

    Figurine::Figurine(const Figurine &f) {
        strcpy(name, f.name);
        price = f.price;
        if (f.isEmpty()) {
            pose = nullptr;
        } else {
            pose = nullptr;
            pose = new char[strlen(f.pose) + 1];
            strcpy(pose, f.pose);
            pose[strlen(pose)] = '\0';
        }
    }

    void Figurine::setName(const char *n) {
        strcpy(name, n);
    }

    void Figurine::setPose(const char *p) {
        pose = nullptr;
        pose = new char[strlen(p) + 1];
        strcpy(pose, p);
        pose[strlen(pose)] = '\0';
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
        } else {
            cout << "Figurine Details" << endl;
            cout << "Name: " << name << endl;
            cout << "Pose: " << pose << endl;
            cout << std::fixed;
            cout << std::setprecision(2);
            cout.precision(2);
            cout << "Price: " << price << endl;
        }
        return cout;
    }

    Figurine::operator bool() const {
        return (strcmp(name, "") == 0);
    }

    bool Figurine::isEmpty() const {
        return (strcmp(name, "") == 0) || (pose == nullptr) || (price < 1);
    }
}
