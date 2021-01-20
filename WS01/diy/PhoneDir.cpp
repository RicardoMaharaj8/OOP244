#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

#include "PhoneDir.h"
#include "Contact.h"
#include "File.h"
#include "Tools.h"

namespace sdds
{

    void phoneDir(const char *title, const char *filename)
    {
        int option;
        Contact C[MAX_REC_NO];
        Contact SearchRes[MAX_REC_NO];
        Contact temp;
        bool changed = false;
        int noOfRecs = readContacts(C, filename);
        int noOfSrchs;
        cout << title << ".................." << endl;
        do
        {
            switch (option = menu())
            {
            case 0:
                cout << "Goodbye!" << endl;
                break;
            case 1:
                getContact(&temp);
                C[noOfRecs] = temp;
                noOfRecs++;
                changed = true;
                break;
            case 2:
                cout << "Name to search for: ";
                getStr(temp.name, 30);
                noOfSrchs = search(SearchRes, C, temp.name, noOfRecs);
                if (noOfSrchs)
                {
                    printContacts(SearchRes, noOfSrchs);
                }
                else
                {
                    cout << temp.name << ", not found!" << endl;
                }
                break;
            case 3:
                sort(C, noOfRecs);
                cout << "Sorted!" << endl;
                changed = true;
                break;
            case 4:
                printContacts(C, noOfRecs);
                break;
            }
        } while (option);
        if (changed)
        {
            cout << endl
                 << "The phone diecotry has changed!"
                 << "Save changes? (Y/N): ";
            if (yes())
            {
                writeContacts(C, noOfRecs, filename);
                cout << "Changes Saved!!" << endl;
            }
            else
            {
                cout << "Changes aborted!!" << endl;
            }
        }
    }

    int menu()
    {
        cout << endl
             << "1- Add Phone Record " << endl;
        cout << "2- Search           " << endl;
        cout << "3- Sort             " << endl;
        cout << "4- List all         " << endl;
        cout << "0- Exit             " << endl;
        cout << "> ";
        return int(getLongLong(0, 4, "option"));
    }

}
