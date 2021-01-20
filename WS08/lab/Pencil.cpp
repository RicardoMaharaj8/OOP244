#include "Pencil.h"

namespace sdds {
    Pencil::Pencil() {
        *HB_scale = 0;
        graphite = 0;
    }

    Pencil::Pencil(const char *c, int g) {
        if (c == nullptr || strcmp(c, "") == 0) {
            *HB_scale = 0;
            graphite = 0;
        } else {
            strncpy(HB_scale, c, HB_MAX + 1);
        }
        if (g < 1 || g > 100) {
            graphite = GRAPHITE_MAX;
        } else {
            graphite = g;
        }
    }

    void Pencil::write(const char *c) {
        if (graphite > 0) {
            int spaces = 0;
            int ledUsed = 0;
            int len = strlen(c);
            cout << "Writing out the following: " << c << " with a Pencil!" << endl;
            for (int i = 0; i < len; i++) {
                if (c[i] == ' ') {
                    spaces++;
                }
            }
            ledUsed = spaces * 5;
            graphite -= ledUsed;
            if (graphite < 0) {
                graphite = 0;
            }
        } else {
            cout << "We can't write without graphite!" << endl;
        }
    }

    void Pencil::refill(int g) {
        graphite += g;
        if (graphite > GRAPHITE_MAX) {
            graphite = GRAPHITE_MAX;
        }
        cout << "Refilling the pencil with graphite" << endl;
    }

    bool Pencil::filled() const {
        return graphite > 0;
    }

    ostream &Pencil::display(ostream &os) const {
        if (*HB_scale != 0) {
            os << "Pencil Details" << endl;
            os << "HB Value: " << HB_scale << endl;
            os << "Graphite Remaining: " << graphite << endl;
        } else {
            os << "This is an empty Pencil" << endl;
        }
        return os;
    }
}
