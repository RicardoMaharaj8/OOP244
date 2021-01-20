#pragma once

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace sdds
{
    const int NO_ERROR = 0;
    const int CIN_FAILED = 1;
    const int YEAR_ERROR = 2;
    const int MON_ERROR = 3;
    const int DAY_ERROR = 4;
    const char DATE_ERROR[5][17] = {
        "No Error",
        "cin Failed.",
        "Bad Year Value.",
        "Bad Month Value.",
        "Bad Day Value."};
    const int MIN_YEAR = 1500;

    class Date
    {
    private:
        int m_year;
        int m_mon;
        int m_day;
        int m_ErrorCode;
        int m_CUR_YEAR;

        int daysSince0001_1_1() const;
        // returns number of days passed since the date 0001/1/1

        bool validate();
        // validates the date setting the error code and then returning the result true, if valid, and false if invalid

        void errCode(int);
        // sets the error code

        int curYear() const;
        // returns the current system year

        bool bad() const;
        // return true if

        int mdays() const;
        // returns the number of days in current month

        void setToToday();
        // sets the date to the current date (system date)

    public:
        Date();
        // creates a date with current date

        Date(int year, int mon, int day);
        // create a date with assigned values then validates the date and sets the  error code accordingly

        int errCode() const;
        // returns the error code or zero if date is valid

        const char *dateStatus() const;
        // returns a string corresponding the current status of the date

        int currentYear() const;
        // returns the m_CUR_YEAR value;

        istream &read(istream &is = cin);
        // receive input from console and validate using validate()

        ostream &write(ostream &os = cout) const;
        // output Date object data to console

        int getDaysSince();
        // return the value of private function daysSince0001_1_1()

        bool isBad();
        // returns true if there is an error ( if errCode != 0 )

        bool isGood();
        // returns true if no errorcode ( if errCode == 0 )
    };

    bool operator==(Date d1, Date d2);

    bool operator!=(Date d1, Date d2);

    bool operator>=(Date d1, Date d2);

    bool operator<=(Date d1, Date d2);

    bool operator>(Date d1, Date d2);

    bool operator<(Date d1, Date d2);

    int operator-(Date d1, Date d2);

    bool operator!(Date d);

    ostream &operator<<(ostream &os, const Date &d);

    istream &operator>>(istream &is, Date &d);
}
