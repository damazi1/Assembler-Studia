#define _USE_MATH_DEFINES
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
#include <ctime>
#include "utils.h"
/* Put additional user headers below this comment */

using namespace std;

extern "C" double asm09_01_01_02(uint, double*);
extern "C" float asm09_01_04_01(uint, float*);
extern "C" double asm09_01_05_03(uint, float*);
extern "C" void asm09_02_03_02(uint, double*, double*, double*);
extern "C" void asm09_02_04_01(uint, float*, float*, float*);
extern "C" void asm09_02_05_01(uint, float*, float*, float*);

int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand((uint)time(0));

    const uint n = 10;

    {
        double* a = newFillPtr<double>(n);
        double yAsm = asm09_01_01_02(n, a);
        double yCpp = 0;
        for (uint i = 0; i < n; ++i) {
            yCpp += a[i];
        }
        printPtr(a, n);
        cout << "[ASM]: " << yAsm << endl;
        cout << "[C++]: " << yCpp << endl;
        resultComparator(yCpp, yAsm);
        freePtr(a);
    }
    {
        float* a = newFillPtr<float>(n);
        float yAsm = asm09_01_04_01(n, a);
        float yCpp = a[0];
        for (uint i = 1; i < n; ++i) {
            if (a[i] > yCpp) {
                yCpp = a[i];
            }
        }
        printPtr(a, n);
        cout << "[ASM]: " << yAsm << endl;
        cout << "[C++]: " << yCpp << endl;
        resultComparator(yCpp, yAsm);
        freePtr(a);
    }
    {
        float* a = newFillPtr<float>(n);
        double yAsm = asm09_01_05_03(n, a);
        double yCpp = 0;
        for (uint i = 0; i < n; ++i) {
            yCpp += a[i];
        }
        yCpp /= n;
        printPtr(a, n);
        cout << "[ASM]: " << yAsm << endl;
        cout << "[C++]: " << yCpp << endl;
        resultComparator(yCpp, yAsm);
        freePtr(a);
    }
    {
        double* a = newFillPtr<double>(n);
        double* b = newFillPtr<double>(n);
        double* yAsm = newFillPtr<double>(n, false, 0);
        double* yCpp = newFillPtr<double>(n, false, 0);
        asm09_02_03_02(n, a, b, yAsm);
        for (uint i = 0; i < n; ++i) {
            yCpp[i] = (pow(a[i], 4) + pow(b[i], 3)) / log(2);
        }
        cout << "[ASM]: ";
        printPtr(yAsm, n);
        cout << "[C++]: ";
        printPtr(yCpp, n);
        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(b);
        freePtr(yAsm);
        freePtr(yCpp);
    }
    {
        float* a = newFillPtr<float>(n);
        float* b = newFillPtr<float>(n);
        float* yAsm = newFillPtr<float>(n, false, 0);
        float* yCpp = newFillPtr<float>(n, false, 0);
        asm09_02_05_01(n, a, b, yAsm);
        for (uint i = 0; i < n; ++i) {
            yCpp[i] = 20 * sin((a[i] * M_PI) / 180.0) + pow(tan((b[i] * M_PI) / 180.0), 2);
        }
        cout << "[ASM]: ";
        printPtr(yAsm, n);
        cout << "[C++]: ";
        printPtr(yCpp, n);
        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(b);
        freePtr(yAsm);
        freePtr(yCpp);
    }
    {
        float* a = newFillPtr<float>(n);
        float* b = newFillPtr<float>(n);
        float* yAsm = newFillPtr<float>(n, false, 0);
        float* yCpp = newFillPtr<float>(n, false, 0);
        asm09_02_04_01(n, a, b, yAsm);
        for (uint i = 0; i < n; ++i) {
            yCpp[i] = sqrt(fabs(5.0 * a[i] + 4.0 * b[i]) / 3.0);
        }
        cout << "[ASM]: ";
        printPtr(yAsm, n);
        cout << "[C++]: ";
        printPtr(yCpp, n);
        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(b);
        freePtr(yAsm);
        freePtr(yCpp);
    }

    system("pause");
    return 0;
}