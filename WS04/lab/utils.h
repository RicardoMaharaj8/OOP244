#pragma once

namespace sdds {
    void copystr(char *&dest, const char *src, unsigned int max_len);

    void read(int &val, int min, int max, const char *errorMessage = "");

    void read(char *str, int len, const char *errorMessage = "");
}
