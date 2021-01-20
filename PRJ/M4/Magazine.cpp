#include "Magazine.h"

namespace sdds
{
    Magazine::Magazine()
    {
        mag_num = 0;
        mag_vol = 0;
    }

    Magazine::Magazine(const Magazine &given_mag) : PubRecord(given_mag)
    {
        mag_vol = given_mag.mag_vol;
        mag_num = given_mag.mag_num;
    }

    char Magazine::recID() const
    {
        return 'M';
    }

    void Magazine::checkIn()
    {
        cout << "Magazines cannot be checked in or out!" << endl;
    }

    void Magazine::checkOut()
    {
        cout << "Magazines cannot be checked in or out!" << endl;
    }

    istream &Magazine::read(istream &is)
    {
        char t_name[41];
        if (mediaType() == SDDS_CONSOLE)
        {
            cout << "Magazine Name: ";
            ::read(t_name, 40, "Magazine name too long, Enter again: ");
            name(t_name);
            cout << "Volume: ";
            ::read(mag_vol, 1, 99, "Invalid Volume number, Enter again: ");
            cout << "Issue: ";
            ::read(mag_num, 1, 99, "Invalid Issue number, Enter again: ");
            cout << "Shelf Number: ";
            readShelfNo();
        }
        if (mediaType() == SDDS_FILE)
        {
            is.getline(t_name, 40, '\t');
            is >> mag_vol;
            is.ignore(100, '\t');
            is >> mag_num;
            is.ignore(100, '\t');
            is >> pub_shelf_num;
            is.ignore(100, '\n');
            name(t_name);
        }
        return is;
    }

    ostream &Magazine::write(ostream &os) const
    {
        if (mediaType() == SDDS_CONSOLE)
        {
            os.width(41);
            os.setf(ios::left);
            os << name();
            os << "       ";
            os.setf(ios::right);
            os << setw(2);
            os << setfill('0');
            os << vol();
            os << '(';
            os.setf(ios::right);
            os << setw(2);
            os << setfill('0');
            os << issue();
            os << ')';
            os << "  ";
            os << shelfNo();
            os << setfill(' ');
            os.unsetf(ios::right);
        }
        if (mediaType() == SDDS_FILE)
        {
            os << recID();
            os << name();
            os << '\t';
            os << vol();
            os << '\t';
            os << issue();
            os << '\t';
            os << shelfNo();
            os << '\n';
        }
        return os;
    }

    int Magazine::vol() const
    {
        return mag_vol;
    }

    int Magazine::issue() const
    {
        return mag_num;
    }
}
