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
#include "lab06_check.h"
using namespace std;

float asm01_ff(float a, float b, float c) {
    float y = 0.0f;
    __asm {
        fld b       ;//b
        fld st      ;//b, b
        fmul        ;// to samo co fmulp st(1), st(0) => b*b
        mov eax, 4
        push eax
        fild[esp]; //4, b*b
        pop eax
        fmul a  ;//4a, b*b
        fmul c      ;//4ac, bb
        fsub        ;//bb - 4ac
        fstp y      ;//<empty>
    }
    return y;
}

float asm02_ff(float a, float b, float c) {
    float y = 0.0f;
    __asm {
        fld a;// a
        fld b;// a,b
        fadd;//a+b
        fld c;//a+b, c
        fmul;//c(a+b)
        fld1
        fld1
        fadd;//2, c(a+b)
        fdiv;// (c(a+b))/2
        fstp y
    }
    return y;
}

float asm03_ff(float a, float b, float c) {
    float y = 0.0f;
    __asm {
        fld a;// a
        fadd b; //(a+b)
        fld st; //(a+b), (a+b)
        fld st; //(a+b), (a+b), (a+b)
        fmul;   //(a+b)^2, (a+b)
        fmul;   //(a+b)^3
        mov eax, 4; //eax <- 4
        push eax;   // 4
        fild [esp];  //4, (a+b)^3
        pop eax;    // <empty>
        fmul;//4(a+b)^3
        fld a;//a, 4(a+b)^3
        fadd c;//a+b, 4(a+b)^3
        fld st;//a+b, a+b, 4(a+b)^3
        fmul;// (a+b)^2, 4(a+b)^3
        fld1;//1, (a+b)^2, 4(a+b)^3
        fld1;//1, 1, (a+b)^2, 4(a+b)^3
        fadd;// 2, (a+b)^2, 4(a+b)^3
        fmul;//2(a+b)^2, 4(a+b)^3
        fsub;// 2(a+b)^2-4(a+b)^3
        fstp y;//<empty>
    }
    return y;
}

float asm04_ff(float a, float b) {
    float y = 0.0f;
    __asm {
        fld1;//1
        fld1;//1,1
        fld a;//a, 1, 1
        fld st;//a,a,1,1
        fmul;//aa,1,1
        fdiv;// 1/aa,1
        fadd;//1+(1/aa)
        fld1;//1, 1+(1/aa)
        fld b;//b, 1, 1+(1/aa)
        fabs;//|b|, 1, 1+(1/aa)
        fld st;//|b|,|b|, 1, 1+(1/aa)
        fld st;//|b|,|b|,|b|, 1, 1+(1/aa)
        fmul;//|b|^2, |b|,1, 1+(1/aa)
        fmul;//|b|^3, 1, 1+(1/aa)
        fdiv;//1/|b|^3, 1+(1/aa)
        fsqrt;// duzo robi xD
        fadd;// cale dzialanie dodaj
        fld st;//st(0), st(1)
        fmul;//st(0)<- wynik
        fstp y;// <empty>
    }
    return y;
}

float asm05_ff(float a, float b) {
    float y = 0.0f;
    __asm {

    }
    return y;
}

float asm06_ff(float a, float b) {
    float y = 0.0f;
    __asm {

    }
    return y;
}

float asm07_ff(float* a, int n) {
    float y = 0.0f;
    __asm {
        mov ecx, n;// ecx <- size
        mov esi, a; // esi <- base address float * a
        fldz;//0
    _loop:
        fld dword ptr[esi + 4 * ecx - 4];// a[i], sum
        fld st;//a[i], a[i], sum
        fmul;//a[i]^2, sum
        fadd;//sum
        dec ecx;// i--
        jne _loop;//while(i!=0)
        fstp y;// <empty>
    }
    return y;
}

void  asm08_vf(float* a, float* b, int size) {
    __asm {

    }
}

double asm01_dd(double a, double b, double c) {
    double y = 0.0f;
    __asm {

    }
    return y;
}

double asm02_dd(double a, double b, double c) {
    double y = 0.0f;
    __asm {

    }
    return y;
}

double asm03_dd(double a, double b, double c) {
    double y = 0.0f;
    __asm {

    }
    return y;
}

double asm04_dd(double a, double b) {
    double y = 0.0f;
    __asm {

    }
    return y;
}

double asm05_dd(double a, double b) {
    double y = 0.0f;
    __asm {

    }
    return y;
}

double asm06_dd(double a, double b) {
    double y = 0.0f;
    __asm {

    }
    return y;
}

double asm07_dd(double* a, int size) {
    double y = 0.0f;
    __asm {

    }
    return y;
}

void  asm08_vd(double* a, double* b, int size) {
    __asm {

    }
}

double asm01_df(float a, float b, float c) {
    float y = 0.0f;
    __asm {

    }
    return y;
}

double asm02_df(float a, float b, float c) {
    float y = 0.0f;
    __asm {

    }
    return y;
}

double asm03_df(float a, float b, float c) {
    float y = 0.0f;
    __asm {

    }
    return y;
}

double asm04_df(float a, float b) {
    float y = 0.0f;
    __asm {

    }
    return y;
}

double asm05_df(float a, float b) {
    float y = 0.0f;
    __asm {

    }
    return y;
}

double asm06_df(float a, float b) {
    float y = 0.0f;
    __asm {

    }
    return y;
}

double asm07_df(float* a, int size) {
    float y = 0.0f;
    __asm {

    }
    return y;
}

void  asm08_vd(float* a, float* b, int size) {
    __asm {

    }
}

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

template <typename R, typename T>
void run(R(*cppFun)(T, T, T), R(*asmFun)(T, T, T), const char * str) {
    T a = rnd<T>(), b = rnd<T>(), c = rnd<T>();
    std::cout << str << std::endl;

    std::cout << "a = " << std::setw(8) << a << std::endl;
    std::cout << "b = " << std::setw(8) << b << std::endl;
    std::cout << "c = " << std::setw(8) << c << std::endl;

    R yAsm = asmFun(a, b, c);
    R yCpp = cppFun(a, b, c);

    std::cout << "[C++]: " << std::setw(8) << yCpp << std::endl;
    std::cout << "[ASM]: " << std::setw(8) << yAsm << std::endl;

    resultComparator(yCpp, yAsm);
}

template <typename R, typename T>
void run(R(*cppFun)(T, T), R(*asmFun)(T, T), const char* str) {
    T a = rnd<T>(), b = rnd<T>();
    std::cout << str << std::endl;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    R yAsm = asmFun(a, b);
    R yCpp = cppFun(a, b);

    std::cout << "[C++]: " << yCpp << std::endl;
    std::cout << "[ASM]: " << yAsm << std::endl;

    resultComparator(yCpp, yAsm);
}

template <typename R, typename T>
void run(R(*cppFun)(T*, const int), R(*asmFun)(T*, const int), const char* str, const int size = 6) {
    T* a = newFillPtr<T>(size);
    std::cout << str << std::endl;

    std::cout << "Input: ";
    printPtr<T>(a, size);

    R yAsm = asmFun(a, size);
    R yCpp = cppFun(a, size);

    std::cout << "[C++]: " << yCpp << std::endl;
    std::cout << "[ASM]: " << yAsm << std::endl;

    resultComparator(yCpp, yAsm);

    freePtr<T>(a);
}

template <typename T>
void run(void(*cppFun)(T*, T*, const int), void(*asmFun)(T*, T*, const int), const char* str, const int size = 6) {
    T* aCpp = newFillPtr<T>(size), *aAsm = newCopyPtr<T>(aCpp, size), *b = newFillPtr<T>(size);
    std::cout << str << std::endl;

    std::cout << "Input: ";
    printPtr<T>(aCpp, size);
    std::cout << "Input: ";
    printPtr<T>(b, size);

    asmFun(aAsm, b, size);
    std::cout << "[ASM]: ";
    printPtr<T>(aAsm, size);

    cppFun(aCpp, b, size);
    std::cout << "[C++]: ";
    printPtr<T>(aCpp, size);

    resultComparator(aCpp, aAsm, size);

    freePtr<T>(aCpp);
    freePtr<T>(aAsm);
    freePtr<T>(b);
}

int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand((unsigned)time(0));

    cout << "* * * * * * * * * * float float * * * * * * * * * *" << endl;
    run(cpp01<float, float>, asm01_ff, "*** Issue 01: ***");
    run(cpp02<float, float>, asm02_ff, "*** Issue 02: ***");
    run(cpp03<float, float>, asm03_ff, "*** Issue 03: ***");
    run(cpp04<float, float>, asm04_ff, "*** Issue 04: ***");
    run(cpp05<float, float>, asm05_ff, "*** Issue 05: ***");
    run(cpp06<float, float>, asm06_ff, "*** Issue 06: ***");
    run(cpp07<float, float>, asm07_ff, "*** Issue 07: ***");
    run(cpp08<float>, asm08_vf, "*** Issue 08: ***");
    cout << endl;
    
    cout << "* * * * * * * * * * double double * * * * * * * * * *" << endl;
    run(cpp01<double, double>, asm01_dd, "*** Issue 01: ***");
    run(cpp02<double, double>, asm02_dd, "*** Issue 02: ***");
    run(cpp03<double, double>, asm03_dd, "*** Issue 03: ***");
    run(cpp04<double, double>, asm04_dd, "*** Issue 04: ***");
    run(cpp05<double, double>, asm05_dd, "*** Issue 05: ***");
    run(cpp06<double, double>, asm06_dd, "*** Issue 06: ***");
    run(cpp07<double, double>, asm07_dd, "*** Issue 07: ***");
    run(cpp08<double>, asm08_vd, "*** Issue 08: ***");
    cout << endl;

    cout << "* * * * * * * * * * double float * * * * * * * * * *" << endl;
    run(cpp01<double, float>, asm01_df, "*** Issue 01: ***");
    run(cpp02<double, float>, asm02_df, "*** Issue 02: ***");
    run(cpp03<double, float>, asm03_df, "*** Issue 03: ***");
    run(cpp04<double, float>, asm04_df, "*** Issue 04: ***");
    run(cpp05<double, float>, asm05_df, "*** Issue 05: ***");
    run(cpp06<double, float>, asm06_df, "*** Issue 06: ***");
    run(cpp07<double, float>, asm07_df, "*** Issue 07: ***");
    cout << endl;

    system("pause");
    return 0;
}