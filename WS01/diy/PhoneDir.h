#pragma once

namespace sdds
{

#define MAX_REC_NO 100

    struct Contact
    {
        char name[31];
        long long phoneNumber;
    };

    void phoneDir(const char *title, const char *filename);

    int menu();

}
