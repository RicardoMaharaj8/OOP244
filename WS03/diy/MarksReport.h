#pragma once

#include "Mark.h"

namespace sdds {

    class MarksReport {
        Mark *Marks;
        char title[70];
        int marks;

    public:
        void initialize();

        void getMarks();

        void print();

        void terminate();
    };
}
