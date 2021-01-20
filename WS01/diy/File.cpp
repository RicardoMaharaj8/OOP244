#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

#include "File.h"
#include "PhoneDir.h"

namespace sdds
{

    bool readContact(Contact *C, FILE *fptr)
    {
        return fscanf(fptr, "%[^,],%lld", C->name, &C->phoneNumber) == 2;
    }

    void writeContact(FILE *fptr, const Contact *C)
    {
        fprintf(fptr, "%s,%lld", C->name, C->phoneNumber);
    }
}
