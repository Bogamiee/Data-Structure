#include "DataGen.h"
#include <cstdlib> // rand
#include <ctime>   // time
using namespace std;

vector<int> generateRandomData(int size) {
    vector<int> data(size);
    for (int& val : data) {
        val = rand();
    }
    return data;
}
