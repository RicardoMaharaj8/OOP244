#include "PubRecord.h"

namespace sdds
{
    PubRecord::PubRecord()
    {
        pub_name = nullptr;
        pub_shelf_num = 0;
        pub_media_type = 0;
    }

    void PubRecord::name(const char *given_name)
    {
        if (given_name == nullptr)
        {
            pub_name = nullptr;
        }
        else
        {
            pub_name = new char[strlen(given_name) + 1];
            strcpy(pub_name, given_name);
        }
    }

    const char *PubRecord::name() const
    {
        return pub_name;
    }

    PubRecord::PubRecord(const PubRecord &given_pub)
    {
        name(given_pub.pub_name);
        mediaType(given_pub.mediaType());
        pub_shelf_num = given_pub.shelfNo();
    }

    PubRecord::~PubRecord()
    {
        delete[] pub_name;
    }

    PubRecord &PubRecord::operator=(const PubRecord &given_pub)
    {
        name(given_pub.pub_name);
        pub_shelf_num = given_pub.pub_shelf_num;
        pub_media_type = given_pub.pub_media_type;
        return *this;
    }

    int PubRecord::mediaType() const
    {
        return pub_media_type;
    }

    void PubRecord::mediaType(int given_media_type)
    {
        pub_media_type = given_media_type;
    }

    int PubRecord::shelfNo() const
    {
        return pub_shelf_num;
    }

    void PubRecord::readShelfNo()
    {
        sdds::read(pub_shelf_num, 100, 999, "Invalid Shelf Number, Enter again: ");
    }

    bool PubRecord::operator==(char given_char) const
    {
        return (given_char == recID());
    }

    bool PubRecord::operator==(const char *given_string) const
    {
        bool isSubstr = false;
        if (strstr(pub_name, given_string) != nullptr)
        {
            isSubstr = true;
        }
        return isSubstr;
    }

    PubRecord::operator bool() const
    {
        return (pub_name != nullptr);
    }
}
