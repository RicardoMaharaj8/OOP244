#include "School.h"

using namespace sdds;

int main() {
    School S;
    read(S);
    report(S);
    freeMem(S);
    return 0;
}

/* read(School&) execution example:
Please enter the name of the school:
> Prg School
Please enter the number of subjects offered by Prg School: 2
1) ------------------------------
Enter subject name: OO Programming 1
Enter number of sections: 2
Enter the number of students in each one of the 2 sections:
1: 20
2: 25
2) ------------------------------
Enter subject name: OO Programming 2
Enter number of sections: 3
Enter the number of students in each one of the 3 sections:
1: 30
2: 35
3: 25
*/

/* report execution example
Prg School
Subject Enrollments
20,25
OO programming 1: 45
30,35,25
OO Programming 2: 90
Total enrollment: 135
*/
