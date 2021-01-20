#pragma once

#include "PubRecord.h"

namespace sdds
{
    // Magazine class derived from PubRecord
    class Magazine : public PubRecord
    {

    protected:
        int mag_vol; // holds the volume of a magazine

        int mag_num; // holds the number ( issue ) of a magazine

    public:
        Magazine();
        // no arg constructor for default values

        Magazine(const Magazine &given_mag);
        // copy constructor to copy the values of another magazine

        char recID() const;
        // returns a 'M' char for magazine

        int vol() const;
        // return mag_vol

        int issue() const;
        // return mag_vol

        void checkIn();
        // returns a error message that magazines are not to be checked in or out

        void checkOut();
        // returns a error message that magazines are not to be checked in or out

        istream &read(istream &is);
        // reads in magazine details from console or from a file

        ostream &write(ostream &os) const;
        // prints magazine details to the console or to a file
    };
}
