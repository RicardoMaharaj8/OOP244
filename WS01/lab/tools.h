#pragma once

#include <iomanip>
#include <iostream>

using namespace std;
#define MAX_NO_OF_SAMPLES 20

namespace sdds
{
    void line(int n, const char *label = nullptr);

    int getInt(int min, int max);

    void goBack(int n);

    int menu(int noOfSamples);
}
