#pragma once

#include "Flower.h"

using namespace std;

namespace sdds {
#define MESS_MAX_LEN 25
#define MAX_FLOWERS 3

    class Bouquet {
    private:
        double b_price;
        char *b_message;
        Flower *b_flowers;
        int b_flowerCount;

    public:
        Bouquet();

        Bouquet(const Flower *Flower, int max = MAX_FLOWERS, const char *message = "Congratulations");

        ~Bouquet();

        const char *message() const;

        double price() const;

        bool isEmpty() const;

        void setEmpty();

        void setMessage(const char *prompt);

        void discardBouquet();

        void arrangeBouquet();

        ostream &display() const;
    };
}
