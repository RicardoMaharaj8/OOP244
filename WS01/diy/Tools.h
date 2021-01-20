#pragma once

#include "PhoneDir.h"

namespace sdds
{

    long long getLongLong(long long min, long long max, const char *valueName);

    long long getPhoneNumber();

    void getContact(Contact *C);

    int compare(const Contact *A, const Contact *B);

    void sort(Contact c[], int n);

    void toLowerCase(char *lowerCase, const char *str);

    bool nameInContact(const Contact *C, const char *nameSubStr);

    bool yes();

    bool valid(long long min, long long max, long long val);

    void getStr(char *str, int len);

    void getName(char *name);

}
