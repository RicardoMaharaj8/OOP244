#include <iostream>

#include "Subject.h"

using namespace std;

using namespace sdds;

int main() {
    // Create a Subject
    Subject S;
    // Read Subject from console and place the data
    // in Dynamically allocated memory
    read(S);
    // print the data kept in Subject S
    report(S);
    // free the memory allocations pointed by Subject S
    freeMem(S);
    return 0;
}

/* read(Subject& ) execution example
Enter subject name: An obviously long text to type so the read function gives me an error for subject name
Name is too long, only 70 characters allowed!
Redo Entry: Intro to OOP using C++
Enter number of sections: 100
Invalid Number of sections, 1<=ENTRY<=10
Redo Entry: 4
Enter the number of students in each one of the 4 sections:
1: 340
Invalid Number of students, 5<=ENTRY<=35
Redo Entry: 34
2: 33
3: 23
4: 30
*/

/* report(const Subject&) execution sample
34, 33, 23, 30
Intro to OOP using C++: 120
*/

/*
Program execution:
Enter subject name: Intro to OOP using C++
Enter number of sections: 12
Invalid Number of sections, 1<=ENTRY<=10
Redo Entry: 4
Enter the number of students in each one of the 4 sections:
1: 340
Invalid Number of students, 5<=ENTRY<=35
Redo Entry: 34
2: 33
3: 23
4: 30
34,33,23,30
Intro to OOP using C++: 120
*/
