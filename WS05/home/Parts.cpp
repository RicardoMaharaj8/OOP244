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

    Legs::Legs() {
        speed = 0;
    }

    Legs::Legs(int s) {
        if (s < MIN_SPEED) {
            speed = MIN_SPEED;
        } else {
            speed = s;
        }
    }

    Legs::~Legs() = default;

    int Legs::getSpeed() const {
        return speed;
    }

    Legs &Legs::operator-=(int s) {
        speed -= s;
        if (speed < 1) {
            speed = 0;
        }
        return *this;
    }

    bool operator>(const Legs &l1, const Legs &l2) {
        return (l1.getSpeed() > l2.getSpeed());
    }

    bool operator<(const Legs &l1, const Legs &l2) {
        return (l2.getSpeed() > l1.getSpeed());
    }

    bool operator>(const Arms &a1, const Arms &a2) {
        return (a1.getForce() > a2.getForce());
    }

    bool operator<(const Arms &a1, const Arms &a2) {
        return (a1.getForce() < a2.getForce());
    }
}
