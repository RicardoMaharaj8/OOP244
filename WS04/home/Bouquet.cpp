#include "Bouquet.h"

namespace sdds {
    Bouquet::Bouquet() {
        b_price = 0;
        b_message = nullptr;
        b_flowers = nullptr;
        b_flowerCount = 0;
    }

    Bouquet::Bouquet(const sdds::Flower *Flower, int max, const char *message) {
        if (Flower != nullptr) {
            b_flowerCount = max;
            b_flowers = new class Flower[b_flowerCount];
            int i;
            double total = 0;
            for (i = 0; i < b_flowerCount; i++) {
                b_flowers[i].setName(Flower[i].name(), strlen(Flower[i].name()));
                b_flowers[i].setColour(Flower[i].colour(), strlen(Flower[i].colour()));
                b_flowers[i].setPrice(Flower[i].price());
                total += Flower[i].price();
            }
            b_message = new char[strlen(message) + 1];
            strcpy(b_message, message);
            b_price = total;
        }
    }

    Bouquet::~Bouquet() {
        if (!isEmpty()) {
            cout << "A bouquet has departed with the following flowers..." << endl;
        } else {
            cout << "An unknown bouquet has departed..." << endl;
        }
        delete[] b_message;
        b_message = nullptr;
        delete[] b_flowers;
        b_flowers = nullptr;
    }

    const char *Bouquet::message() const {
        return b_message;
    }

    double Bouquet::price() const {
        return b_price;
    }

    bool Bouquet::isEmpty() const {
        return (b_flowers == nullptr);
    }

    void Bouquet::setEmpty() {
        b_price = 0;
        b_message = nullptr;
        b_flowers = nullptr;
        b_flowerCount = 0;
    }

    void Bouquet::setMessage(const char *prompt) {
        cout << prompt;
        char mess[31];
        read(mess, 31, "A bouquets's message (non-empty) is limited to 30 characters... Try again: ");
        b_message = new char[strlen(mess) + 1];
        strcpy(b_message, mess);
    }

    void Bouquet::discardBouquet() {
        cout << "Discarding the current bouquet..." << endl;
        delete[] b_flowers;
        delete[] b_message;
        setEmpty();
    }

    void Bouquet::arrangeBouquet() {
        cout << "Arranging a new bouquet..." << endl;
        char choice = 'Y';
        if (!isEmpty()) {
            cout << "This bouquet has an arrangement currently, discard it? (Y/N): ";
            read(&choice, 1, "The decision is either Y or N... Try again: ");
            if (choice == 'Y') {
                discardBouquet();
            } else if (choice == 'N') {
                cout << "No new arrangement performed..." << endl;
            }
        }
        if (choice == 'Y') {
            cout << "Enter the number of flowers in this bouquet (Valid: 1-3)... : ";
            read(b_flowerCount, 1, 3, "The valid range is 1-3... Try again: ");
            b_flowers = new class Flower[b_flowerCount];
            int i;
            double total = 0;
            for (i = 0; i < b_flowerCount; i++) {
                b_flowers[i].setFlower();
                cin.clear();
                while (cin.get() != '\n');
                total += b_flowers[i].price();
            }
            b_price = total;
            cout << "A bouquet has been arranged..." << endl;
            setMessage("Enter a message to send with the bouquet...: ");
        }
    }

    ostream &Bouquet::display() const {
        if (isEmpty()) {
            cout << "This is an empty bouquet..." << endl;
        } else {
            cout << fixed << setprecision(2);
            cout << "This bouquet worth " << b_price << " has the following flowers..." << endl;
            for (int i = 0; i < b_flowerCount; ++i) {
                b_flowers[i].display();
            }
            cout << "with a message of: " << b_message << endl;
        }
        return cout;
    }
}
