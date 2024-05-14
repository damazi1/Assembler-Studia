#define _USE_MATH_DEFINES
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
#include <vector>
#include <ctime>
#include "utils.h"
#include "lab11.h"

using namespace std;

extern "C" void asm01_01pd(double* a, double* b, double* y, uint n);
extern "C" void asm01_07pd(double* y, uint n);
extern "C" void asm01_15pd(double* a, double* b, double* y, uint n);
extern "C" void asm02_01pd(double a, double b,double* x, double* y, uint n);
extern "C" double asm03_01pd(double* a, uint n);

int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand((uint)time(0));

    {
        print("*** 01.01 ***", GOLD);
        uint n = 512;
        double* a = newFillPtr<double>(n);
        double* b = newFillPtr<double>(n);
        double* yAsm = newFillPtr<double>(n, false);
        double* yCpp = newFillPtr<double>(n, false);
        printPtr(a, n);
        printPtr(b, n);
        auto start = getTime();
        asm01_01pd(a, b, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp01_01(a, b, yCpp, n);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(b);
        freePtr(yAsm);
        freePtr(yCpp);
    }

    {
        print("*** 01.07 ***", GOLD);
        uint n = 512;
        double* yAsm = newFillPtr<double>(n);
        double* yCpp = newCopyPtr<double>(yAsm, n);
        printPtr(yAsm, n);
        auto start = getTime();
        asm01_07pd(yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp01_07(yCpp, n);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);
        freePtr(yAsm);
        freePtr(yCpp);
    }

    {
        print("*** 01.15 ***", GOLD);
        uint n = 512;
        double* a = newFillPtr<double>(n);
        double* b = newFillPtr<double>(n);
        double* yAsm = newFillPtr<double>(n, false);
        double* yCpp = newFillPtr<double>(n, false);
        printPtr(a, n);
        printPtr(b, n);
        auto start = getTime();
        asm01_15pd(a, b, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp01_15(a, b, yCpp, n);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(b);
        freePtr(yAsm);
        freePtr(yCpp);
    }

    {
        print("*** 02.15 ***", GOLD);
        uint n= 512;
        double a = rndf<double>(), b = rndf<double>();
        double* x = newFillPtr<double>(n);
        double* yAsm = newFillPtr<double>(n, false);
        double* yCpp = newFillPtr<double>(n, false);
        cout << "a = " << a << "\tb = " << b << endl;
        printPtr(x, n);
        auto start = getTime();
        asm02_01pd(a, b, x, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp02_01(x, yCpp, n, a, b);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);

        freePtr(x);
        freePtr(yCpp);
        freePtr(yAsm);
    }

    {
        print("*** 03.01 ***", GOLD);
        uint n = 512;
        double* a = newFillPtr<double>(n);
        printPtr(a, n);
        auto start = getTime();
        double yAsm = asm03_01pd(a, n);
        auto end = getTime();
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        double yCpp=cpp03_01(a, n);
        end = getTime();
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm);

        freePtr(a);
    }
    system("pause");
    return 0;
}