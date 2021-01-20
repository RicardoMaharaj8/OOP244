#include <iostream>
#include <cstring>
#include <iomanip>

#include "Mark.h"

using namespace std;

namespace sdds {
    void Mark::flushKeyboard() const {
        char ch;
        do {
            ch = cin.get();
        } while (ch != '\n');
    }

    void Mark::set(int displayMode) {
        m_displayMode = displayMode;
    }

    void Mark::set(double mark, int outOf) {
        m_mark = mark;
        m_outOf = outOf;
    }

    void Mark::setEmpty() {
        m_displayMode = DSP_UNDEFINED;
        m_mark = -1;
        m_outOf = 100;
        strcpy(m_name, "");
    }

    bool Mark::isEmpty() const {
        return (m_mark == -1);
    }

    int Mark::percent() const {
        double percentage;
        percentage = (((m_mark / m_outOf) * 100) + 0.5);
        return int(percentage);
    }

    double Mark::rawValue() const {
        double val = 0;
        val = (m_mark / m_outOf);
        return val;
    }

    bool Mark::read(const char *prompt) {

        bool success = true;

        cout << prompt;
        cin >> m_mark;
        cin.ignore();
        cin >> m_outOf;

        if (cin.fail()) {
            cin.clear();
            setEmpty();
            success = false;
        }
        flushKeyboard();
        return success;
    }

    ostream &Mark::display(int width) const {
        if (strcmp(m_name, "") != 0) {
            cout.fill('.');
            cout.width(width);
            cout.setf(ios::left);
            cout << m_name;
        }
        if (isEmpty()) {
            cout << "Empty Mark object!";
        } else {
            switch (m_displayMode) {
                case DSP_RAW:
                    cout << fixed << setprecision(2);
                    cout << rawValue();
                    break;
                case DSP_PERCENT:
                    cout << "%" << percent();
                    break;
                case DSP_ASIS:
                    cout << fixed << setprecision(1);
                    cout << m_mark << "/" << m_outOf;
                    break;
                case DSP_UNDEFINED:
                    cout << "Display mode not set!";
                    break;
                case DSP_LETTER:
                    prnLetter();
                    break;
                case DSP_GPA:
                    cout << fixed << setprecision(1);
                    cout << GPA();
                    break;
                default:
                    cout << "Invalid Mark Display setting!";
                    break;
            }
        }
        return cout;
    }

    void Mark::prnLetter() const {
        int val = 0;
        if (m_mark != -1) {
            val = percent();
        }
        if (val <= 49) {
            cout << "F";
        } else if (val <= 54) {
            cout << "D";
        } else if (val <= 59) {
            cout << "D+";
        } else if (val <= 64) {
            cout << "C";
        } else if (val <= 69) {
            cout << "C+";
        } else if (val <= 74) {
            cout << "B";
        } else if (val <= 79) {
            cout << "B+";
        } else if (val <= 89) {
            cout << "A";
        } else if (val <= 100) {
            cout << "A+";
        } else if (val > 100) {
            cout << "?";
        }
    }

    void Mark::set(const char *name) {
        strcpy(m_name, name);
    }

    void Mark::set(const char *name, double rawMark, int outof) {
        set(name);
        set(rawMark, outof);
    }

    bool Mark::readName(const char *prompt, int maxLen) {
        cout << prompt;
        bool ok = true;
        cin.getline(m_name, maxLen + 1);
        if (cin.fail()) {
            cin.clear();
            flushKeyboard();
            strcpy(m_name, "");
            ok = false;
        }
        return ok;
    }

    void Mark::changeOutOf(int value) {
        double r = m_mark * (double(value) / m_outOf);
        if (r < 1) {
            m_mark = -1;
        } else {
            m_mark = r;
        }
        m_outOf = value;
    }

    double Mark::GPA() const {
        return rawValue() * 4;
    }

    double Mark::letterBasedGPA() const {
        double gpa = 0;
        gpa = percent();
        if (gpa <= 49) {
            gpa = 0.0;
        } else if (gpa <= 54) {
            gpa = 1.0;
        } else if (gpa <= 59) {
            gpa = 1.5;
        } else if (gpa <= 64) {
            gpa = 2.0;
        } else if (gpa <= 69) {
            gpa = 2.5;
        } else if (gpa <= 74) {
            gpa = 3.0;
        } else if (gpa <= 79) {
            gpa = 3.5;
        } else if (gpa <= 89) {
            gpa = 4.0;
        } else if (gpa <= 100) {
            gpa = 4.0;
        }
        return gpa;
    }
}
