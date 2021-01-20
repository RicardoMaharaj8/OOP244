#pragma once

#include "PubRecord.h"
#include "Date.h"

namespace sdds
{

    // class Book derived from PubRecord
    class Book : public PubRecord
    {

    protected:
        long int book_ISBN; // holds the ISBN ( long used for 13 digits capability )

        int book_mem_id; // holds member id of checked out books

        Date book_return_date; // holds the return by date for books

    public:
        Book();
        // no arg constructor for default values

        Book(const Book &given_book);
        // copy constructor to copy the values of another Book

        char recID() const;
        // returns a 'B' char for Book

        int memberID() const;
        // returns book_mem_id

        long int isbn() const;
        // return book_isbn

        void checkIn();
        // sets the mem_id to zero to indicate book is returned

        void checkOut();
        // reads a member id and return date from console with validation

        Date returnDate() const;
        // return book_return_date

        Book &operator=(const Book &b);
        // assignment operator with same function as copy constructor

        void setReturnDate();
        // sets the protected var book_return_date, validates by checking Date::isbad() ( checks Date.errCode )

        istream &read(istream &is);
        // reads in Book details from console or from a file

        ostream &write(ostream &os) const;
        // prints Book details to the console or to a file
    };
}
