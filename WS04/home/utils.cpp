#include <iostream>
#include <cstring>

#include "utils.h"

using namespace std;

namespace sdds {
    void copystr(char *&dest, const char *src, unsigned int max_len) {}

    void read(int &val, int min, int max, const char *ErrorMess) {
        bool ok;
        char newline;
        do {
            cin >> val;
            newline = cin.get();
            if (cin.fail() || newline != '\n') {
                ok = false;
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                ok = val <= max && val >= min;
            }
        } while (!ok && cout << ErrorMess);
    }

    void read(char *str, int len, const char *errorMessage) {
        bool ok;
        do {
            ok = true;
            cin.getline(str, len + 1, '\n');
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                ok = false;
            } else if (strlen(str) == 0)
                ok = false;
        } while (!ok && cout << errorMessage);
    }
}
