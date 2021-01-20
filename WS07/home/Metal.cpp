#include "Metal.h"

namespace sdds {
    Metal::Metal() {
        *name = 0;
        mohs = DEFAULT_MOHS;
    }

    Metal::Metal(double w, int p, const char *c, const char *n, double m) {
        if (n == nullptr) {
            *name = 0;
            mohs = DEFAULT_MOHS;
            weight = DEFAULT_WEIGHT;
            purity = DEFAULT_PURITY;
            *classification = 0;
        } else {
            strncpy(name, n, NAME_LEN);
        }

        if (m > 0) {
            mohs = m;
        } else {
            mohs = DEFAULT_MOHS;
        }

        if (w < 1) {
            weight = DEFAULT_WEIGHT;
        } else {
            weight = w;
        }

        if (p < 1 || p > 100) {
            purity = DEFAULT_PURITY;
        } else {
            purity = p;
        }

        strncpy(classification, c, CLASS_LEN);
    }

    void Metal::refine() {
        if (Ore::refine()) {
            mohs++;
        } else {
        }
    }

    ostream &Metal::display(ostream &os) const {
        if (*name == 0) {
            os << "This metal is imaginary" << endl;
        } else {
            os << "Name: " << name << endl;
            Ore::display(os);
            os << "Mohs: " << mohs << endl;
        }
        return os;
    }

    istream &Metal::input(istream &is) {
        char n[NAME_LEN];
        cout << "Enter a value for this metal's name: ";
        is.getline(n, NAME_LEN);
        strcpy(name, n);
        cout << "Enter a value for this metal's mohs: ";
        double m;
        is >> m;
        if (m > 0) {
            mohs = m;
        } else {
            mohs = DEFAULT_MOHS;
        }
        Ore::input(is);
        return is;
    }

    ostream &operator<<(ostream &os, const Metal &met) {
        os << "Metal" << endl;
        met.display(os);
        return os;
    }

    istream &operator>>(istream &is, Metal &met) {
        met.input(is);
        return is;
    }
}
