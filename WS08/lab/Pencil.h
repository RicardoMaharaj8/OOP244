#pragma once

#include "WriteInstrument.h"

namespace sdds {
#define HB_MAX 2
#define GRAPHITE_MAX 100

    class Pencil : public WriteInstrument {
    protected:
        char HB_scale[HB_MAX + 1];
        int graphite;

    public:
        Pencil();

        Pencil(const char *c, int g);

        void write(const char *c);

        void refill(int g);

        bool filled() const;

        ostream &display(ostream &os) const;
    };
}
