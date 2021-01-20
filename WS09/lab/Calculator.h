#pragma once

#include <iostream>

using namespace std;

namespace sdds {
    template<typename T, int N>
    class Calculator {
    private:
        T results[N];

    public:
        Calculator() {
            for (int i = 0; i < N; i++) {
                results[i] = 0;
            }
        }

        void add(const T *param_one, const T *param_two) {
            for (int i = 0; i < N; i++) {
                this->results[i] = param_one[i] + param_two[i];
            }
        }

        void subtract(const T *param_one, const T *param_two) {
            for (int i = 0; i < N; i++) {
                this->results[i] = param_one[i] - param_two[i];
            }
        }

        void multiply(const T *param_one, const T *param_two) {
            for (int i = 0; i < N; i++) {
                this->results[i] = param_one[i] * param_two[i];
            }
        }

        void divide(const T *param_one, const T *param_two) {
            for (int i = 0; i < N; i++) {
                this->results[i] = param_one[i] / param_two[i];
            }
        }

        ostream &display(ostream &os) const {
            for (int i = 0; i < N; i++) {
                os << this->results[i];
                if (i != N - 1) {
                    os << ",";
                }
            }
            os << endl;
            return os;
        }

        Calculator &operator+=(const T *param) {
            add(this->results, param);
            return *this;
        }

        Calculator &operator-=(const T *param) {
            subtract(this->results, param);
            return *this;
        }

        Calculator &operator*=(const T *param) {
            multiply(this->results, param);
            return *this;
        }

        Calculator &operator/=(const T *param) {
            divide(this->results, param);
            return *this;
        }
    };
}
