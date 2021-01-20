#include "Parts.h"

namespace sdds {
    Arms::Arms() {
        force = 0;
    }

    Arms::Arms(int f) {
        if (f <= 0) {
            force = 50;
        } else {
            force = f;
        }
    }

    Arms::~Arms() = default;

    int Arms::getForce() const {
        return force;
    }

    Arms &Arms::operator++() {
        Arms preFix = *this;
        force += 10;
        return *this;
    }

    Arms Arms::operator++(int) {
        Arms postFix = *this;
        force += 10;
        return postFix;
    }

    Arms &Arms::operator+=(int in) {
        force += in;
        if (force < 1) {
            force = 0;
        }
        return *this;
    }
}
