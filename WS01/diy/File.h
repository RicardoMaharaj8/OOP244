#pragma once

#include "PhoneDir.h"

namespace sdds
{

    bool readContact(Contact *C, FILE *fptr);

    void writeContact(FILE *fptr, const Contact *C);

}
