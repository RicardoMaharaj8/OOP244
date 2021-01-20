#include "Pen.h"

namespace sdds {
    Pen::Pen() {
        style = nullptr;
        ink = 0;
    }

    Pen::Pen(const char *c, int i) {
        if (c == nullptr || strcmp(c, "") == 0) {
            style = nullptr;
            ink = 0;
        } else {
            int len = strlen(c);
            style = new char[len + 1];
            strncpy(style, c, len + 1);
        }
        if (i < 1 || 1 > 50) {
            ink = INK_MAX;
        } else {
            ink = i;
        }
    }

    Pen::~Pen() {
        delete[] style;
    }

    void Pen::write(const char *c) {
        if (ink > 0) {
            int i;
            int nonSpaces = 0;
            int inkUsed = 0;
            int len = strlen(c);
            cout << "Writing out the following: " << c << " with a Pen!" << endl;
            for (i = 0; i < len; i++) {
                if (c[i] != ' ') {
                    nonSpaces++;
                }
            }
            inkUsed = nonSpaces * 2;
            ink -= inkUsed;
            if (ink < 0) {
                ink = 0;
            }
        } else {
            cout << "We can't write without ink!" << endl;
        }
    }

    void Pen::refill(int i) {
        ink += i;
        if (ink > INK_MAX) {
            ink = INK_MAX;
        }
        cout << "Refilling the pen with ink" << endl;
    }

    bool Pen::filled() const {
        return ink > 0;
    }

    ostream &Pen::display(ostream &os) const {
        if (style == nullptr || strcmp(style, "") == 0) {
            os << "This is an empty Pen" << endl;
        } else {
            os << "Pen Details" << endl;
            os << "Style: " << style << endl;
            os << "Ink Remaining: " << ink << endl;
        }
        return os;
    }
}
