#define _USE_MATH_DEFINES
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
#include <iostream>
#include <ctime>
#include <iomanip>
#include "ptr_helpers.h"
#include "algebra_helpers.h"
#include "console_helpers.h"
#include "lab07_check.h"
using namespace std;

extern "C" float asm01(float, float, float, float, float);
extern "C" float asm02(float, float);
extern "C" float asm03(float, float, float, float);
extern "C" void asm04(float*, float*, int, float, float, float, float);

extern "C" double asm01_64(double, double, double, double, double);
extern "C" double asm02_64(double, double);
extern "C" double asm03_64(double, double, double, double);
extern "C" void asm04_64(double*, double*, int, double, double, double, double);

void printSummary(bool result) {
    std::cout << "Results are equal: ";
    if (result) {
        print("True", GREEN);
    }
    else {
        print("False", RED);
    }
}

template <typename T>
void resultComparator(T* expected, T* actual, const int size) {
    printSummary(assertEquals<T>(expected, actual, size));
}

template <typename T>
void resultComparator(T expected, T actual) {
    printSummary(almostEqual(expected, actual));
}

template <typename T>
void run(T(*cppFun)(T, T, T, T, T), T(*asmFun)(T, T, T, T, T), const char * str) {
    T a = rnd<T>(), b = rnd<T>(), c = rnd<T>(), d = rnd<T>(), x = rnd<T>();
    std::cout << str << std::endl;

    std::cout << "a    = " << std::setw(8) << a << std::endl;
    std::cout << "b    = " << std::setw(8) << b << std::endl;
    std::cout << "c    = " << std::setw(8) << c << std::endl;
    std::cout << "d    = " << std::setw(8) << d << std::endl;
    std::cout << "x    = " << std::setw(8) << x << std::endl;

    T yAsm = asmFun(a, b, c, d, x);
    T yCpp = cppFun(a, b, c, d, x);

    std::cout << "[ASM]: " << std::setw(8) << yAsm << std::endl;
    std::cout << "[C++]: " << std::setw(8) << yCpp << std::endl;

    resultComparator(yCpp, yAsm);
}

template <typename T>
void run(T(*cppFun)(T, T), T(*asmFun)(T, T), const char* str) {
    T a = rnd<T>(), x = rnd<T>();
    std::cout << str << std::endl;

    std::cout << "a    = " << std::setw(8) << a << std::endl;
    std::cout << "x    = " << std::setw(8) << x << std::endl;

    T yAsm = asmFun(a, x);
    T yCpp = cppFun(a, x);

    std::cout << "[ASM]: " << std::setw(8) << yAsm << std::endl;
    std::cout << "[C++]: " << std::setw(8) << yCpp << std::endl;

    resultComparator(yCpp, yAsm);
}

template <typename T>
void run(T(*cppFun)(T, T, T, T), T(*asmFun)(T, T, T, T), const char* str) {
    T a = rnd<T>(), b = rnd<T>(), c = rnd<T>(), x =-5;
    std::cout << str << std::endl;

    std::cout << "a    = " << std::setw(8) << a << std::endl;
    std::cout << "b    = " << std::setw(8) << b << std::endl;
    std::cout << "c    = " << std::setw(8) << c << std::endl;
    std::cout << "x    = " << std::setw(8) << x << std::endl;

    T yAsm = asmFun(a, b, c, x);
    T yCpp = cppFun(a, b, c, x);

    std::cout << "[ASM]: " << std::setw(8) << yAsm << std::endl;
    std::cout << "[C++]: " << std::setw(8) << yCpp << std::endl;

    resultComparator(yCpp, yAsm);
}

template <typename T>
void run(void(*cppFun)(T*, T*, const int, T, T, T, T), void(*asmFun)(T*, T*, const int, T, T, T, T), const char* str, const int size = 6) {
    T* xCpp = newPtr<T>(size), *xAsm = newPtr<T>(size);
    T* yCpp = newPtr<T>(size), * yAsm = newPtr<T>(size);
    T a = rnd<T>(), b = rnd<T>(), xMin = rnd<T>(-1000, -900), xMax = rnd<T>(1000, 900);
    std::cout << str << std::endl;

    std::cout << "a    = " << std::setw(8) << a << std::endl;
    std::cout << "b    = " << std::setw(8) << b << std::endl;
    std::cout << "xMin = " << std::setw(8) << xMin << std::endl;
    std::cout << "xMax = " << std::setw(8) << xMax << std::endl;

    asmFun(xAsm, yAsm, size, a, b, xMin, xMax);
    std::cout << "[ASM]: " << std::endl;
    std::cout << "   y = ";
    printPtr<T>(xAsm, size);
    std::cout << "   x = ";
    printPtr<T>(yAsm, size);

    cppFun(xCpp, yCpp, size, a, b, xMin, xMax);
    std::cout << "[C++]: " << std::endl;
    std::cout << "   y = ";
    printPtr<T>(xCpp, size);
    std::cout << "   x = ";
    printPtr<T>(yCpp, size);

    resultComparator(yCpp, yAsm, size);
    resultComparator(xCpp, xAsm, size);

    freePtr<T>(xCpp);
    freePtr<T>(xAsm);
    freePtr<T>(yCpp);
    freePtr<T>(yAsm);
}

int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand((unsigned)time(0));

    cout << "* * * * * * * * * * float * * * * * * * * * *" << endl;
    run(cpp01<float>, asm01, "*** Issue 01: ***");
    run(cpp02<float>, asm02, "*** Issue 02: ***");
    run(cpp03<float>, asm03, "*** Issue 03: ***");
    run(cpp04<float>, asm04, "*** Issue 04: ***");
    cout << endl;

    cout << "* * * * * * * * * * double * * * * * * * * * *" << endl;
    run(cpp01<double>, asm01_64, "*** Issue 01: ***");
    run(cpp02<double>, asm02_64, "*** Issue 02: ***");
    run(cpp03<double>, asm03_64, "*** Issue 03: ***");
    run(cpp04<double>, asm04_64, "*** Issue 04: ***");
    cout << endl;

    system("pause");
    return 0;
}