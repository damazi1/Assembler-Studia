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
extern "C" void asm01_02ps(float* a, float* b, float* y, uint n);
extern "C" void asm01_03pd(double* a, double* b, double* y, uint n);
extern "C" void asm01_04pd(double* a, double* b, double* y, uint n);
extern "C" void asm01_05ps(float* a, float* b, float* y, uint n);
extern "C" void asm01_06pd(double* a, double* b, double* y, uint n);
extern "C" void asm01_07pd(double* y, uint n);
extern "C" void asm01_08pd(double a, double b, double*x, double* y, uint n);
extern "C" void asm01_10pd(double a, double b, double c, double d, double*x, double* y, uint n);
extern "C" void asm01_11pd(double *a, double *b, double *c, double *d, double* y, uint n);
extern "C" void asm01_15pd(double* a, double* b, double* y, uint n);
extern "C" void asm01_16pd(double* a, double* b, double* x, double* y, uint n);
extern "C" void asm02_01pd(double a, double b,double* x, double* y, uint n);
extern "C" void asm02_09pd(double a, double b, double c, double d, double* x, double* y, uint n);
extern "C" void asm02_17ps(float *a, float *b, float* x, float* y, uint n);
extern "C" double asm03_01pd(double* a, uint n);
extern "C" double asm03_02pd(double* a, uint n);
extern "C" double asm03_03pd(double* a, uint n);
extern "C" double asm03_04pd(double* a, uint n);
extern "C" double asm03_05pd(double* a, double* b, uint n);
extern "C" float asm03_09ps(float* a, float* b, float c, uint n);

int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand((uint)time(0));
    //zad1.01
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
    //zad 1.02
    {
        print("*** 01.02 ***", GOLD);
        uint n = 512;
        float* a = newFillPtr<float>(n);
        float* b = newFillPtr<float>(n);
        float* yAsm = newFillPtr<float>(n, false);
        float* yCpp = newFillPtr<float>(n, false);
        printPtr(a, n);
        printPtr(b, n);
        auto start = getTime();
        asm01_02ps(a, b, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp01_02(a, b, yCpp, n);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(b);
        freePtr(yAsm);
        freePtr(yCpp);
    }
    //zad 1.03
    {
        print("*** 01.03 ***", GOLD);
        uint n = 512;
        double* a = newFillPtr<double>(n);
        double* b = newFillPtr<double>(n);
        double* yAsm = newFillPtr<double>(n, false);
        double* yCpp = newFillPtr<double>(n, false);
        printPtr(a, n);
        printPtr(b, n);
        auto start = getTime();
        asm01_03pd(a, b, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp01_03(a, b, yCpp, n);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(b);
        freePtr(yAsm);
        freePtr(yCpp);
    }
    //zad 1.04
    {
        print("*** 01.04 ***", GOLD);
        uint n = 8;
        double* a = newFillPtr<double>(n);
        double* b = newFillPtr<double>(n);
        double* yAsm = newFillPtr<double>(n, false);
        double* yCpp = newFillPtr<double>(n, false);
        printPtr(a, n);
        printPtr(b, n);
        auto start = getTime();
        asm01_04pd(a, b, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp01_04(a, b, yCpp, n);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(b);
        freePtr(yAsm);
        freePtr(yCpp);
    }
    //zad1.05
    {
        print("*** 01.05 ***", GOLD);
        uint n = 512;
        float* a = newFillPtr<float>(n);
        float* b = newFillPtr<float>(n);
        float* yAsm = newFillPtr<float>(n, false);
        float* yCpp = newFillPtr<float>(n, false);
        printPtr(a, n);
        printPtr(b, n);
        auto start = getTime();
        asm01_05ps(a, b, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp01_05(a, b, yCpp, n);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(b);
        freePtr(yAsm);
        freePtr(yCpp);
    }
    //zad1.06
    {
        print("*** 01.06 ***", GOLD);
        uint n = 8;
        double* a = newFillPtr<double>(n);
        double* b = newFillPtr<double>(n);
        double* yAsm = newFillPtr<double>(n, false);
        double* yCpp = newFillPtr<double>(n, false);
        printPtr(a, n);
        printPtr(b, n);
        auto start = getTime();
        asm01_06pd(a, b, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp01_06(a, b, yCpp, n);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(b);
        freePtr(yAsm);
        freePtr(yCpp);
    }
    //zad1.07
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
    //zad1.08
    {
        print("*** 01.08 ***", GOLD);
        uint n = 512;
        double a = rndf<double>();
        double b = rndf<double>();
        double* x = newFillPtr<double>(n);
        double* yAsm = newFillPtr<double>(n, false);
        double* yCpp = newFillPtr<double>(n, false);
        cout << "a = " << a << "\tb = " << b << endl;
        printPtr(x, n);
        auto start = getTime();
        asm01_08pd(a, b, x, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp01_08(x, yCpp, n, a, b);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);
        freePtr(x);
        freePtr(yAsm);
        freePtr(yCpp);
    }
    //zad1.10
    {
        print("*** 01.10 ***", GOLD);
        uint n = 512;
        double a = rndf<double>();
        double b = rndf<double>();
        double c = rndf<double>();
        double d = rndf<double>();
        double* x = newFillPtr<double>(n);
        double* yAsm = newFillPtr<double>(n, false);
        double* yCpp = newFillPtr<double>(n, false);
        cout << "a = " << a << "\tb = " << b << endl;
        printPtr(x, n);
        auto start = getTime();
        asm01_10pd(a, b, c, d, x, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp01_10(x, yCpp, n, a, b, c, d);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);
        freePtr(x);
        freePtr(yAsm);
        freePtr(yCpp);
    }
    //zad1.11
    {
        print("*** 01.11 ***", GOLD);
        uint n = 512;
        double* a = newFillPtr<double>(n);
        double* b = newFillPtr<double>(n);
        double* c = newFillPtr<double>(n);
        double* d = newFillPtr<double>(n);
        double* yAsm = newFillPtr<double>(n, false);
        double* yCpp = newFillPtr<double>(n, false);
        printPtr(a, n);
        printPtr(b, n);
        printPtr(c, n);
        printPtr(d, n);
        auto start = getTime();
        asm01_11pd(a, b,c , d, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp01_11(a, b, c, d, yCpp, n);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(b);
        freePtr(c);
        freePtr(d);
        freePtr(yAsm);
        freePtr(yCpp);
    }
    //zad1.15
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
    //zad1.16
    {
        print("*** 01.16 ***", GOLD);
        uint n = 512;
        double* a = newFillPtr<double>(n);
        double* b = newFillPtr<double>(n);
        double* x = newFillPtr<double>(n);
        double* yAsm = newFillPtr<double>(n, false);
        double* yCpp = newFillPtr<double>(n, false);
        printPtr(a, n);
        printPtr(b, n);
        printPtr(x, n);
        auto start = getTime();
        asm01_16pd(a, b, x, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp01_16(a, b, x, yCpp, n);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(b);
        freePtr(x);
        freePtr(yAsm);
        freePtr(yCpp);
    }
    //zad2.01
    {
        print("*** 02.01 ***", GOLD);
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
    //zad2.09
    {
        print("*** 02.09 ***", GOLD);
        uint n = 512;
        double a = rndf<double>(), b = rndf<double>(), c = rndf<double>(), d = rndf<double>();
        double* x = newFillPtr<double>(n);
        double* yAsm = newFillPtr<double>(n, false);
        double* yCpp = newFillPtr<double>(n, false);
        cout << "a = " << a << "\tb = " << b << endl;
        printPtr(x, n);
        auto start = getTime();
        asm02_09pd(a, b, c, d, x, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp02_09(x, yCpp, n, a, b, c, d);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);

        freePtr(x);
        freePtr(yCpp);
        freePtr(yAsm);
    }
    //zad2.17
    {
        print("*** 02.17 ***", GOLD);
        uint n = 512;
        float* x = newFillPtr<float>(n);
        float* a = newFillPtr<float>(n);
        float* b = newFillPtr<float>(n);
        float* yAsm = newFillPtr<float>(n, false);
        float* yCpp = newFillPtr<float>(n, false);
        printPtr(x, n);
        printPtr(a, n);
        printPtr(b, n);
        auto start = getTime();
        asm02_17ps(a, b, x, yAsm, n);
        auto end = getTime();
        printPtr(yAsm, n);
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        cpp02_17(a, b, x , yCpp, n);
        end = getTime();
        printPtr(yCpp, n);
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm, n);

        freePtr(x);
        freePtr(a);
        freePtr(b);
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
    {
        print("*** 03.02 ***", GOLD);
        uint n = 512;
        double* a = newFillPtr<double>(n);
        printPtr(a, n);
        auto start = getTime();
        double yAsm = asm03_02pd(a, n);
        auto end = getTime();
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        double yCpp = cpp03_02(a, n);
        end = getTime();
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm);

        freePtr(a);
    }
    {
        print("*** 03.03 ***", GOLD);
        uint n = 512;
        double* a = newFillPtr<double>(n);
        printPtr(a, n);
        auto start = getTime();
        double yAsm = asm03_03pd(a, n);
        auto end = getTime();
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        double yCpp = cpp03_03(a, n);
        end = getTime();
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm);

        freePtr(a);
    }
    {
        print("*** 03.04 ***", GOLD);
        uint n = 512;
        double* a = newFillPtr<double>(n);
        printPtr(a, n);
        auto start = getTime();
        double yAsm = asm03_04pd(a, n);
        auto end = getTime();
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        double yCpp = cpp03_04(a, n);
        end = getTime();
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm);

        freePtr(a);
    }
    {
        print("*** 03.05 ***", GOLD);
        uint n = 512;
        double* a = newFillPtr<double>(n);
        double* b = newFillPtr<double>(n);
        printPtr(a, n);
        printPtr(b, n);
        auto start = getTime();
        double yAsm = asm03_05pd(a,b, n);
        auto end = getTime();
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        double yCpp = cpp03_05(a, b, n);
        end = getTime();
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm);

        freePtr(a);
        freePtr(b);
    }
    /*
    {
        print("*** 03.09 ***", GOLD);
        uint n = 512;
        float c = rndf<float>();
        float* a = newFillPtr<float>(n);
        float* b = newFillPtr<float>(n);
        printPtr(a, n);
        printPtr(b, n);
        auto start = getTime();
        float yAsm = asm03_09ps(a, b, c, n);
        auto end = getTime();
        cout << "ASM: " << getDurationNs(start, end) << " ns" << endl;
        start = getTime();
        float yCpp = cpp03_09(a, b, n, c);
        end = getTime();
        cout << "C++: " << getDurationNs(start, end) << " ns" << endl;
        resultComparator(yCpp, yAsm);

        freePtr(a);
        freePtr(b);
    }
    */
    system("pause");
    return 0;
}