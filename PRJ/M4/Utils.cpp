#include "Utils.h"

void read(int &val, int min, int max, const char *intErrMess) {
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
    } while (!ok && cout << intErrMess);
}

void read(char *str, int len, const char *charErrMess) {
    bool ok;
    do {
        ok = true;
        cin.getline(str, len + 1, '\n');
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
        }
    } while (!ok && cout << charErrMess);
}
