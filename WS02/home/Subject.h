#pragma once

namespace sdds {

    struct Subject {
        int *m_noOfSections;
        int *m_noOfStdsInSecs;
        char *m_subjectName;
    };

    void read(char *nameOfSubject);

    void read(int &numOfSections);

    void read(int students[], int numOfStudents);

    void read(Subject &Sub);

    int report(const Subject &Sub);

    void freeMem(Subject &Sub);
}
