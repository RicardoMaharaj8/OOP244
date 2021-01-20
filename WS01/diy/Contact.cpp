#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

#include "Contact.h"
#include "PhoneDir.h"
#include "Tools.h"
#include "File.h"

namespace sdds
{

    void printContact(const Contact *C)
    {
        cout << setw(35) << setfill('.') << setiosflags(ios::left) << C->name << C->phoneNumber << endl;
    }

    void printContacts(const Contact *C, int num)
    {
        for (int i = 0; i < num; i++)
        {
            printContact(&C[i]);
        }
    }

    int search(Contact *found, const Contact *C, const char *name, int noOfRecs)
    {
        int i;
        int noOfMatches = 0;
        for (i = 0; i < noOfRecs; i++)
        {
            if (nameInContact(&C[i], name))
            {
                found[noOfMatches] = C[i];
                noOfMatches++;
            }
        }
        return noOfMatches;
    }

    int readContacts(Contact *contacts, const char *filename)
    {
        FILE *fptr = fopen(filename, "r");
        Contact C;
        int num;
        for (num = 0; fptr && num < MAX_REC_NO && readContact(&C, fptr); num++)
        {
            contacts[num] = C;
        }
        return num;
    }

    void writeContacts(Contact *contacts, int cntno, const char *filename)
    {
        FILE *fptr = fopen(filename, "w");
        int num;
        for (num = 0; num < cntno; num++)
        {
            writeContact(fptr, &contacts[num]);
        }
        fclose(fptr);
    }
}
