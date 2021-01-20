#include <iostream>
#include <cstring>
#include "Subject.h"
#include "utils.h"

using namespace std;

namespace sdds
{

    void read(char *name)
    {
        cout << "Enter subject name: ";
        const char *errorMessage = "Name is too long, only 70 characters allowed!\nRedo Entry: ";
        read(name, 70, errorMessage);
    }

    void read(int &numOfSec)
    {
        cout << "Enter number of sections: ";
        const char *ErrorMess = "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ";
        read(numOfSec, 1, 10, ErrorMess);
    }

    void read(int stuNum[], int numOfStu)
    {
        cout << "Enter the number of students in each one of the " << numOfStu << " sections:\n";
        const char *ErrorMess = "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ";
        for (int i = 0; i < numOfStu; i++)
        {
            cout << i + 1 << ": ";
            read(stuNum[i], 5, 35, ErrorMess);
        }
    }

    void read(Subject &Sub)
    {
        char name[71];
        read(name);
        Sub.m_subjectName = new char[strlen(name) + 1];
        strcpy(Sub.m_subjectName, name);

        int *addressOfSections = nullptr;
        addressOfSections = new int;
        Sub.m_noOfSections = addressOfSections;
        read(*addressOfSections);

        int *numOfstdInSections = nullptr;
        numOfstdInSections = new int[*addressOfSections];
        Sub.m_noOfStdsInSecs = numOfstdInSections;
        read(numOfstdInSections, *addressOfSections);
    }

    int report(const Subject &Sub)
    {
        for (int i = 0; i < *Sub.m_noOfSections; i++)
        {
            cout << Sub.m_noOfStdsInSecs[i];
            if (i < *Sub.m_noOfSections - 1)
            {
                cout << ",";
            }
        }

        cout << "\n";
        cout << Sub.m_subjectName << ": ";
        int sum = 0;
        for (int i = 0; i < *Sub.m_noOfSections; i++)
        {
            sum += Sub.m_noOfStdsInSecs[i];
        }
        cout << sum << "\n";
        return sum;
    }

    void freeMem(Subject &Sub)
    {
        delete[] Sub.m_subjectName;
        delete Sub.m_noOfSections;
        delete[] Sub.m_noOfStdsInSecs;
    }
}