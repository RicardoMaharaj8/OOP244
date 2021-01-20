#pragma once

#include "WriteInstrument.h"

namespace sdds {
#define INK_MAX 50

    class Pen : public WriteInstrument {
    private:
        char *style;
        int ink;

    public:
        Pen();

        Pen(const char *c, int i);

        ~Pen();

        void write(const char *c);

        void refill(int i);

        bool filled() const;

        ostream &display(ostream &os) const;
    };
}
