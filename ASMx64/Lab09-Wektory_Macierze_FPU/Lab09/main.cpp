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
extern "C" double asm09_01_09_02(uint, double*);
extern "C" double asm09_01_10_03(uint, float*, float);
extern "C" float asm09_01_11_01(uint, float*);
extern "C" void asm09_02_01_03(uint, float*, double*);
extern "C" void asm09_02_03_02(uint, double*, double*, double*);
extern "C" void asm09_02_04_01(uint, float*, float*, float*);
extern "C" void asm09_02_05_01(uint, float*, float*, float*);
extern "C" void asm09_02_06_01(uint, float*);
extern "C" double asm09_03_01_02(uint,uint, double**);

int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand((uint)time(0));

    const uint n = 10;
    //zad1.1
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
    //zad1.4
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
    //zad1.5
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
    //zad1.9
    {
        double* a = newFillPtr<double>(n);
        double yAsm = asm09_01_09_02(n, a);
        double yCpp = 0;
        for (uint i = 0; i < n; i++) {
            yCpp += sqrt((a[i] * a[i] + 20) / 4);
        }
        printPtr(a, n);
        cout << "[ASM]: " << yAsm << endl;
        cout << "[C++]: " << yCpp << endl;
        resultComparator(yCpp, yAsm);
        freePtr(a);
    }
    //zad1.10
    {
        float x = rnd<float>(0,100);
        float* a = newFillPtr<float>(n);
        double yAsm = asm09_01_10_03(n, a, x);
        double yCpp = 0;
        for (uint i = 0; i < n; i++) {
            yCpp += log2(a[i]*x+1);
        }
        cout << "----- 1.10 -----" << endl;
        printPtr(a, n);
        cout << "x = " << x << endl;
        cout << "[ASM]: " << yAsm << endl;
        cout << "[C++]: " << setprecision(4) <<yCpp << endl;
        resultComparator(yCpp, yAsm);
        freePtr(a);
    }
    //zad1.11
    {
        float* a = newFillPtr<float>(n);
        float yAsm = asm09_01_11_01(n, a);
        float yCpp = 0;

        for (uint i = 0; i < n; i++) {
            if (a[i] > 0)
                yCpp++;
        }
        cout << "----- 1.11 -----" << endl;
        printPtr(a, n);
        cout << "[ASM]: " << yAsm << endl;
        cout << "[C++]: " << yCpp << endl;
        resultComparator(yCpp, yAsm);
        freePtr(a);
    }

    //zad2.1
    {
        float* a = newFillPtr<float>(n);
        double* yAsm = newFillPtr<double>(n, false, 0);
        double* yCpp = newFillPtr<double>(n, false, 0);
        asm09_02_01_03(n, a, yAsm);
        for (uint i = 0; i < n; ++i) {
            yCpp[i] = 16*(pow(a[i],5))+5;
        }
        cout << " ----- 2.1 ----- " << endl;
        cout << "[ASM]: ";
        printPtr(yAsm, n);
        cout << "[C++]: ";
        printPtr(yCpp, n);
        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(yAsm);
        freePtr(yCpp);
    }

    //zad2.3
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
    //zad2.5
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
    //zad2.4
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
    //zad2.6
    {
        float* a = newFillPtr<float>(n);
        cout << "----- 2.6 -----" << endl;
        printPtr(a, n);
        asm09_02_06_01(n, a);
        printPtr(a, n);
        freePtr(a);
    }
    //zad3.1
    {
        uint m = 5;
        double** a = newFillPtr<double>(n, m);
        double yAsm = asm09_03_01_02(n, m, a);
        double yCpp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                yCpp += a[i][j];
            }
        }
        cout << " ----- 3.1 -----" << endl;
        printPtr(a, n,m);
        resultComparator(yCpp, yAsm);
        freePtr(a, n);
    }

    system("pause");
    return 0;
}