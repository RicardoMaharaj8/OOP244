#include "MarksReport.h"

int main() {
    sdds::MarksReport mr;
    mr.initialize();
    mr.getMarks();
    mr.print();
    mr.terminate();
    return 0;
}
