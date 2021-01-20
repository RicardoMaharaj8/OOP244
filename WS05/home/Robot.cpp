#include "Robot.h"

namespace sdds {
    Robot::Robot() {
        nickname[0] = '\0';
        durability = 0;
        arms = 0;
        legs = 0;
    }

    Robot::Robot(const char *name, int frc, int spd, int dur) {
        if (strlen(name) == 0 || name == nullptr) {
            *this = Robot();
        } else if (strlen(name) > 11) {
            strcpy(nickname, name);
            nickname[10] = '\0';
        } else {
            strcpy(nickname, name);
        }

        if (dur < 1) {
            durability = 100;
        } else {
            durability = dur;
        }
        arms = frc;
        legs = spd;
    }

    Robot::~Robot() = default;

    ostream &Robot::display() const {
        if (durability == 0) {
            cout << "This Robot isn't operational" << endl;
        } else {
            cout << "***Robot Summary***" << endl;
            cout << "Nickname: " << nickname << endl;
            cout << "Arm Power: " << arms.getForce() << endl;
            cout << "Durability: " << durability << endl;
            cout << "Legs: " << legs.getSpeed() << endl;
        }
        return cout;
    }

    Robot::operator bool() const {
        return (durability == 0);
    }

    Arms Robot::getArms() const {
        return arms;
    }

    Legs Robot::getLegs() const {
        return legs;
    }

    Robot &Robot::operator-=(int dm) {
        durability -= dm;
        if (durability < 1) {
            durability = 0;
        }
        return *this;
    }

    void box(Robot &r1, Robot &r2) {
        cout << "Attempting to begin a Robot boxing match" << endl;
        if (!r1 && !r2) {
            cout << "Both participants are operational... beginning the bout" << endl;
            if (r1.getLegs().getSpeed() > r2.getLegs().getSpeed()) {
                r2 -= r1.getArms().getForce();
            } else {
                r1 -= r2.getArms().getForce();
            }
            cout << "The bout has concluded... the winner is: " << endl;
            if (r1) {
                r1.display();
            } else {
                r2.display();
            }
        } else {
            cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
        }
    }
}
