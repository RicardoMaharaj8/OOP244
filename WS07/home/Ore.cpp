#include "Ore.h"

namespace sdds {
    Ore::Ore() {
        weight = DEFAULT_WEIGHT;
        purity = DEFAULT_PURITY;
        *classification = 0;
    }

    Ore::Ore(double w, int p, const char *c) {
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

    bool Ore::refine() {
        if (purity >= 100) {
            cout << "Can no longer be refined" << endl;
            purity = 100;
            return false;
        } else {
            weight -= 20;
            purity += 10;
            return true;
        }
    }

    ostream &Ore::display(ostream &os) const {
        if (*classification == 0) {
            os << "This ore is imaginary" << endl;
        } else {
            os << fixed;
            os << setprecision(2);
            os << "Weight: " << weight << endl;
            os << "Purity: " << purity << endl;
            os << "Classification: " << classification << endl;
        }
        return os;
    }

    istream &Ore::input(istream &is) {
        double w;
        cout << "Enter a value for this ore's weight: ";
        is >> w;
        int p;
        cout << "Enter a value for this ore's purity: ";
        is >> p;
        cout << "Enter a classification for the ore (MAX 30 chars): ";
        is.ignore();
        is.getline(classification, CLASS_LEN);
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
        return is;
    }

    ostream &operator<<(ostream &os, const Ore &ore) {
        cout << "Ore" << endl;
        ore.display(os);
        return os;
    }

    istream &operator>>(istream &is, Ore &ore) {
        ore.input(is);
        return is;
    }
}
