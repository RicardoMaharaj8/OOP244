#include <iostream>

#include "MarksReport.h"
#include "Mark.h"

using namespace std;

namespace sdds {

    void printline() {
        cout.width(70);
        cout.fill('-');
        cout << '-' << endl;
    }

    void MarksReport::initialize() {
        cout << "Enter the report Name: ";
        cin.getline(title, 70);

        cout << "Enter the number of marks: ";
        cin >> marks;
        while (cin.get() != '\n') {
        }
        Marks = new Mark[marks];
    }

    void MarksReport::getMarks() {
        cout << "Please enter " << marks << " marks:" << endl;
        int i;
        for (i = 0; i < marks; i++) {
            Marks[i].setEmpty();
            Marks[i].set(DSP_LETTER);
            cout << (i + 1) << ": ";
            Marks[i].readName("Subject Name: ", 6);
            Marks[i].read("Mark (mark/outof): ");
        }
        cout << "Entry Completed!" << endl;
        cout << endl;
    }

    void MarksReport::print() {
        Mark print;
        printline();
        cout << title << endl;
        printline();

        cout << "Marks entered:" << endl;
        double gpa = 0;
        int max = 0;
        int min = Marks[0].percent();
        int i;
        for (i = 0; i < marks; i++) {
            Marks[i].display(66) << endl;

            if (Marks[i].percent() < min) {
                min = Marks[i].percent();
            }
            if (Marks[i].percent() > max) {
                max = Marks[i].percent();
            }
            gpa += Marks[i].letterBasedGPA();
        }
        printline();

        print.set(min, 100);
        print.set(DSP_PERCENT);
        print.set("Lowest Mark");
        cout.fill(' ');
        cout.width(30);
        cout << ' ';
        print.display(36) << endl;

        print.set(max, 100);
        print.set(DSP_PERCENT);
        print.set("Highest mark");
        cout.fill(' ');
        cout.width(30);
        cout << ' ';
        print.display(36) << endl;

        print.set(gpa / marks, 4);
        print.set(DSP_GPA);
        print.set("GPA");
        cout.fill(' ');
        cout.width(30);
        cout << ' ';
        print.display(36) << endl;
    }

    void MarksReport::terminate() {
        delete[] Marks;
    }
}
