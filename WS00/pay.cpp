#include <iostream>
#include <cstring>

using namespace std;

/* 1. Inheritance
   2. shadow/override a base-class member function
   3. static(i.e. compile-time) function binding
 */

// a base class
class Employee {
protected:
    char name[30];
    char payroll_id[8];

public:
    Employee();

    Employee(const char *, const char *);

    const char *get_name() const;

    const char *get_id() const;

    double pay() const;
};

// a derived class
class Manager : public Employee {
protected:
    double salary; // monthly salary
public:
    Manager();

    Manager(const char *, const char *, double s);

    double pay() const; // redefined (i.e. overriden)!
    // shadow the base-class function
};

class Staff : public Employee {
protected:
    double hourly_rate;
    int weekly_hours;

public:
    Staff();

    Staff(const char *, const char *, double r, int h);

    double get_rate() const;

    int get_hours() const;

    double pay() const; // redefined (i.e. overriden)!
    // shadow the base-class function
};

int main() {

    cout << "Ricardo Maharaj" << endl;

    Manager b("Mona Lisa", "ML29035", 3500);
    Staff s("John Doe", "SF11117", 65, 7);
    Employee e("Daniel Price", "DP12345");

    // Part 1
    cout.setf(ios::fixed); // control format
    cout.precision(2);     // precision control

    cout << "+Employee object " << endl
         << "name: " << e.get_name() << endl
         << "pay: $" << e.pay() << endl;

    cout << "+Manager object " << endl
         << "name: " << b.get_name() << endl
         << "pay (by salary): $" << b.pay() << endl;

    cout << "+Staff object " << endl
         << "name: " << s.get_name() << endl
         << "pay (by hours): $" << s.pay() << endl;

    // Part 2
    // - use a base-class pointer to do polymorphism

    Employee *e1; // a base-class pointer!

    e1 = &b;

    cout << "\n........" << endl;

    cout << "Manager object: "
         << e1->get_name() << ", " << e1->get_id() << endl;

    cout << "Monthly pay: $" << e1->pay() << endl
         << endl; // (*e1).pay();

    e1 = &s;

    cout << "Staff object: "
         << e1->get_name() << ", " << e1->get_id() << endl;

    cout << "Weekly pay: $" << e1->pay() << endl;

    e1 = &e;
    cout << e1->pay() << endl;

    return 0;
}

// ***** Implementation of the class Employee
Employee::Employee() {
    cout << "1." << endl;
    strcpy(name, "");
    strcpy(payroll_id, "");
}

Employee::Employee(const char *sn, const char *sid) {
    strcpy(name, sn);
    strcpy(payroll_id, sid);
}

const char *Employee::get_name() const {
    return name;
}

const char *Employee::get_id() const {
    return payroll_id;
}

double Employee::pay() const {
    return 1234;
}

// ***** Implementation of the class Manager
Manager::Manager(const char *sn, const char *sid, double sal) : Employee(sn, sid) {
    salary = sal;
    //strcpy(name, "HaHaHa");
}

double Manager::pay() const {
    return salary + Employee::pay();
}

// ***** Implementation of the class Staff
Staff::Staff(const char *sn, const char *sid, double r, int h) : Employee(sn, sid) {
    hourly_rate = r;
    weekly_hours = h;
}

double Staff::pay() const {
    return hourly_rate * weekly_hours;
}
