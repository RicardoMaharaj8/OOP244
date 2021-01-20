#pragma once

#include "PhoneDir.h"

namespace sdds
{

    void printContact(const Contact *C);

    void printContacts(const Contact *C, int num);

    int search(Contact *found, const Contact *C, const char *name, int noOfRecs);

    int readContacts(Contact *contacts, const char *filename);

    void writeContacts(Contact *contacts, int cntno, const char *filename);

}
