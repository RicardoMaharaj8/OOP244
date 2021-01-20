#include "Robot.h"

namespace sdds {
    Robot::Robot() {
        nickname[0] = '\0';
        durability = 0;
        arms = 0;
    }

    Robot::Robot(const char *name, int f, int dur) {
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
        if (f <= 0) {
            arms.force = 50;
        } else {
            arms.force = f;
        }
    }

    Robot::~Robot() = default;

    ostream &Robot::display() const {
        if (durability == 0) {
            cout << "This Robot isn't operational" << endl;
        } else {
            cout << "***Robot Summary***" << endl;
            cout << "Nickname: " << nickname << endl;
            cout << "Arm Power: " << arms.force << endl;
            cout << "Durability: " << durability << endl;
        }
        return cout;
    }

    Robot::operator bool() const {
        return (durability == 0);
    }
}
