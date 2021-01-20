#include <iostream>
#include <cstring>

#include "Subject.h"
#include "utils.h"

using namespace std;

namespace sdds {

    void read(char *name) {
        cout << "Enter subject name: ";
        read(name, 70, "Name is too long, only 70 characters allowed!\nRedo Entry: ");
    }

    void read(int &sec) {
        cout << "Enter number of sections: ";
        read(sec, 1, 10, "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ");
    }

    void read(int array[], int num) {
        cout << "Enter the number of students in each one of the " << num << " sections:\n";
        for (int i = 0; i < num; i++) {
            cout << i + 1 << ": ";
            read(array[i], 5, 35, "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ");
        }
    }

    void read(Subject &Sub) {
        char name[71];
        read(name);
        Sub.m_subjectName = new char[strlen(name) + 1];
        strcpy(Sub.m_subjectName, name);

        int *sec = nullptr;
        sec = new int;
        Sub.m_noOfSections = sec;
        read(*sec);

        int *num = nullptr;
        num = new int[*sec];
        Sub.m_noOfStdsInSecs = num;
        read(num, *sec);
    }

    int report(const Subject &Sub) {
        for (int i = 0; i < *Sub.m_noOfSections; i++) {
            cout << Sub.m_noOfStdsInSecs[i];
            if (i < *Sub.m_noOfSections - 1) {
                cout << ",";
            }
        }

        cout << "\n";
        cout << Sub.m_subjectName << ": ";
        int sum = 0;
        for (int i = 0; i < *Sub.m_noOfSections; i++) {
            sum += Sub.m_noOfStdsInSecs[i];
        }
        cout << sum << "\n";
        return sum;
    }

    void freeMem(Subject &Sub) {
        delete[] Sub.m_subjectName;
        delete Sub.m_noOfSections;
        delete[] Sub.m_noOfStdsInSecs;
    }
}
