#include <iostream>

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
    }

    bool Mark::isEmpty() const {
        return (m_displayMode == DSP_UNDEFINED && m_mark == -1 && m_outOf == 100);
    }

    int Mark::percent() const {
        double percentage;
        percentage = (((m_mark / m_outOf) * 100) + 0.5);
        return percentage;
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

    ostream &Mark::display() const {
        if (isEmpty()) {
            cout << "Empty Mark object!";
        } else {
            switch (m_displayMode) {
                case DSP_RAW:
                    cout << rawValue();
                    break;
                case DSP_PERCENT:
                    cout << "%" << percent();
                    break;
                case DSP_ASIS:
                    cout << m_mark << "/" << m_outOf;
                    break;
                case DSP_UNDEFINED:
                    cout << "Display mode not set!";
                    break;
                default:
                    cout << "Invalid Mark Display setting!";
                    break;
            }
        }
        return cout;
    }
}
