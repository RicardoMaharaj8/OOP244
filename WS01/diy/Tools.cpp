#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

#include "PhoneDir.h"
#include "Tools.h"

namespace sdds
{

    long long getLongLong(long long min, long long max, const char *valueName)
    {
        long long val;
        bool done = false;
        while (!done)
        {
            cin >> val;
            if (cin.fail())
            {
                cin.clear();
                cout << "Bad Number, try again: ";
            }
            else
            {
                if (!valid(min, max, val))
                {
                    cout << "Invalid " << valueName << "!" << endl
                         << "The " << valueName << " must be between " << min << " and " << max << ": ";
                }
                else
                {
                    done = true;
                }
            }
            cin.ignore(1000, '\n');
        }
        return val;
    }

    long long getPhoneNumber()
    {
        return getLongLong(1000000000LL, 9999999999LL, "Phone Number");
    }

    void getContact(Contact *C)
    {
        cout << "Name: ";
        getName(C->name);
        cout << "Phone Number: ";
        C->phoneNumber = getPhoneNumber();
    }

    int compare(const Contact *A, const Contact *B)
    {
        return strcmp(A->name, B->name);
    }

    void sort(Contact *c, int n)
    {
        Contact temp;
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (compare(&c[j], &c[j + 1]) > 0)
                {
                    temp = c[j];
                    c[j] = c[j + 1];
                    c[j + 1] = temp;
                }
            }
        }
    }

    void toLowerCase(char *lowerCase, const char *str)
    {
        int i;
        for (i = 0; str[i] && i < 30; i++)
        {
            lowerCase[i] = str[i] | 0x20;
        }
        lowerCase[i] = 0;
    }

    bool nameInContact(const Contact *C, const char *nameSubStr)
    {
        char name[31];
        char subName[31];
        toLowerCase(name, C->name);
        toLowerCase(subName, nameSubStr);
        return strstr(name, subName) != nullptr;
    }

    bool yes()
    {
        char ch;
        ch = cin.get();
        cin.ignore(1000, '\n');
        return ch == 'y' || ch == 'Y';
    }

    bool valid(long long min, long long max, long long val)
    {
        return min <= val && val <= max;
    }

    void getStr(char *str, int len)
    {
        cin.getline(str, len, '\n');
    }

    void getName(char *name)
    {
        getStr(name, 30);
    }
}
