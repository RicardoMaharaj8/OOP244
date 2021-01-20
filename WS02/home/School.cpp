#include <iostream>
#include <cstring>

#include "School.h"
#include "Subject.h"
#include "utils.h"

using namespace std;

namespace sdds {

    void read(School &Sch) {
        Sch.m_name = nullptr;
        Sch.m_name = new char[61];
        cout << "Please enter the name of the school:\n> ";
        read(Sch.m_name, 61, "Name is too long, only 60 characters allowed!\nRedo Entry: ");

        Sch.m_noOfSubjects = nullptr;
        Sch.m_noOfSubjects = new int;
        cout << "Please enter the number of subjects offered by " << Sch.m_name << ": ";
        read(*Sch.m_noOfSubjects, 2, 50, "Invalid Number of subjects, 2<=ENTRY<=50\nRedo Entry: ");
        Sch.m_subjects = nullptr;
        Sch.m_subjects = new Subject[*Sch.m_noOfSubjects];
        for (int i = 0; i < *Sch.m_noOfSubjects; i++) {
            cout << i + 1 << ") ------------------------------" << endl;
            read(Sch.m_subjects[i]);
        }
    }

    int report(const School &Sch) {
        cout << Sch.m_name << endl;
        cout << "Subject Enrollments" << endl;
        int total = 0;
        int i;
        for (i = 0; i < *Sch.m_noOfSubjects; i++) {
            total += report(Sch.m_subjects[i]);
        }
        cout << "Total enrollment: " << total << endl;
        return total;
    }

    void freeMem(School &Sch) {
        delete[] Sch.m_name;
        delete[] Sch.m_subjects;
        delete Sch.m_noOfSubjects;
    }
}
