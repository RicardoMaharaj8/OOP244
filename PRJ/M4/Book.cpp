#include "Book.h"

namespace sdds
{
    Book::Book()
    {
        book_ISBN = 0;
        book_mem_id = 0;
    }

    Book::Book(const Book &given_book) : PubRecord(given_book)
    {
        book_ISBN = given_book.book_ISBN;
        book_mem_id = 0;
        book_return_date = given_book.book_return_date;
    }

    char Book::recID() const
    {
        return 'B';
    }

    int Book::memberID() const
    {
        return book_mem_id;
    }

    void Book::checkIn()
    {
        book_mem_id = 0;
        cout << name() << " checked in!" << '\n';
    }

    void Book::checkOut()
    {
        bool ok;
        cout << "Entere Member id: ";
        do
        {
            cin >> book_mem_id;
            ok = !(book_mem_id > 99999 || book_mem_id < 10000);
        } while (!ok && cout << "Invalid Member ID, Enter again: ");
        cout << "Enter return date: ";
        setReturnDate();
        Date today;
        while (book_return_date - today < 0)
        {
            cout << "Please enter a future date." << '\n';
            setReturnDate();
        }
        while (book_return_date - today > 30)
        {
            cout << "The return date must be earlier than 30 days away from today." << '\n';
            setReturnDate();
        }
    }

    void Book::setReturnDate()
    {
        do
        {
            cin >> book_return_date;
        } while (book_return_date.isBad());
    }

    istream &Book::read(istream &is)
    {
        char t_name[41];
        Date t_date;
        if (mediaType() == SDDS_CONSOLE)
        {
            book_mem_id = 0;
            cout << "Book Name: ";
            ::read(t_name, 40, "Book name too long, Enter again: ");
            name(t_name);
            cout << "ISBN: ";
            cin >> book_ISBN;
            cout << "Shelf Number: ";
            readShelfNo();
        }
        if (mediaType() == SDDS_FILE)
        {
            is.getline(t_name, 40, '\t');
            is >> book_ISBN;
            is.ignore(100, '\t');
            is >> pub_shelf_num;
            is.ignore(100, '\t');
            is >> book_mem_id;
            if (memberID() != 0)
            {
                is.ignore(100, '\t');
                is >> t_date;
                is.ignore(100, '\n');
            }
            book_return_date = t_date;
            name(t_name);
        }
        return is;
    }

    ostream &Book::write(ostream &os) const
    {
        if (mediaType() == SDDS_CONSOLE)
        {
            os.setf(ios::left);
            os.width(41);
            os.fill(' ');
            os << name();
            os << isbn();
            os << "  ";
            os << shelfNo();
            if (memberID() != 0)
            {
                os << " " << memberID();
                os << "   " << returnDate();
            }
            os.unsetf(ios::left);
        }
        if (mediaType() == SDDS_FILE)
        {
            os << recID();
            os << name();
            os << '\t';
            os << isbn();
            os << '\t';
            os << shelfNo();
            os << '\t';
            os << memberID();
            if (memberID() != 0)
            {
                os << '\t';
                os << returnDate();
            }
            os << '\n';
        }
        return os;
    }

    long int Book::isbn() const
    {
        return book_ISBN;
    }

    Date Book::returnDate() const
    {
        return book_return_date;
    }

    Book &Book::operator=(const Book &given_book)
    {
        name(given_book.pub_name);
        mediaType(given_book.mediaType());
        pub_shelf_num = given_book.shelfNo();
        book_ISBN = given_book.book_ISBN;
        book_mem_id = 0;
        book_return_date = given_book.book_return_date;
        return *this;
    }
}
