#pragma once

namespace sdds
{
    void read(int &val, int min, int max, const char *errorMessage = "");

    void read(char *str, int len, const char *errorMessage = "");
}
