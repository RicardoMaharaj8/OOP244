#pragma once

#include "ReadWriteable.h"
#include "Utils.h"

#define SDDS_CONSOLE 0
#define SDDS_FILE 1

namespace sdds
{
    // class derived from ReadWriteable
    class PubRecord : public ReadWriteable
    {
    protected:
        char *pub_name;
        int pub_shelf_num;
        int pub_media_type;

        void shelfNo(int given_num);
        // set pub_shelf_num

        void name(const char *given_name);
        // set pub_name

        const char *name() const;
        // get pub_name

    public:
        virtual void checkIn() = 0;
        // virtual function for derived classes

        virtual void checkOut() = 0;
        // virtual function for derived classes

        virtual char recID() const = 0;
        // virtual function without implementation for child classes to derive

        PubRecord();
        // default constructor to set to safe empty state

        PubRecord(const PubRecord &given_pub);
        // copy constructor to initialize object based on another

        virtual ~PubRecord();
        // destructor to clean up dynamic memory and avoid leaks

        PubRecord &operator=(const PubRecord &given_pub);
        // same as the copy constructor but allows for easy assignment using = operator

        void mediaType(int given_media_type);
        // sets pub_media_type

        int mediaType() const;
        // get pub_media_type

        void readShelfNo();
        // set pub_shelf_num with validation

        int shelfNo() const;
        // get pub_shelf_num

        bool operator==(char given_char) const;
        // comparision operator for given_char to the result of recID()

        bool operator==(const char *given_string) const;
        // comparison operator for determining if the given_string is found anywhere within the pub_name string

        operator bool() const;
        // bool operator to determine if pub_name is empty
    };
}
