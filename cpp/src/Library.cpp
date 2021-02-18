#include <Library.hpp>

#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <vector>

#include <fstream>
#include <iostream>

extern "C" {
    DLLEXPORT int GetRandom() { return rand(); };

    DLLEXPORT int PreAllocTest(double* ppdoubleArrayReceiver) {
        size_t stSize = sizeof(double) * (3 * 5);
        double doubleArray[3][5];
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                doubleArray[i][j] = i * 10 + j;
            }
        }

        memcpy(ppdoubleArrayReceiver, doubleArray, stSize);
        
        return 0;
    }

    DLLEXPORT int AllocInTest(double* ppdoubleArrayReceiver) {
        size_t stSize = sizeof(double) * (3 * 5);
        double doubleArray[3][5];
        
        ppdoubleArrayReceiver = new double[(3 * 5)];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                doubleArray[i][j] = i * 10 + j;
            }
        }

        memcpy(ppdoubleArrayReceiver, doubleArray, stSize);

        return 3 * 5;
    }

    DLLEXPORT void MyFree(double* ppdoubleArrayReceiver) { delete[] ppdoubleArrayReceiver; }

    DLLEXPORT void write() {
        std::ofstream outfile("test.txt");
        outfile << "my text here!" << std::endl;
        outfile.close();
    }
}
