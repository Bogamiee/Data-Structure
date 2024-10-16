#include <iostream>
#include <ctime>
#include "Matrix.h"
#include "MatrixCalc.h"
#include "TimeMsr.h"
#include "MatrixOperation.h"
using namespace std;

#define PERCENT 50

int main() {
    MatrixOperation mo(PERCENT);

    mo.run();

    return 0;
}
