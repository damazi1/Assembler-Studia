#define _USE_MATH_DEFINES
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
#include <vector>
#include <ctime>
#include "utils.h"
#include "lab10.h"

using namespace std;

extern "C" double asm01_01sd(double, double);
extern "C" double asm01_02sd(double, double);
extern "C" double asm01_03sd(double, double);
extern "C" double asm01_04sd(double, double);
extern "C" double asm01_05sd(double, double);
extern "C" double asm01_07sd(double);
extern "C" double asm02_01sd(double, double, double);
extern "C" double asm02_08sd(double, double, double, double, double);

int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand((uint)time(0));

    //zad1
    {
        setConsoleTextColor(GOLD);
        cout << "*** 01 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        double yAsm = asm01_01sd(a, b);
        double yCpp = cpp01_01(a, b);
        resultComparator(yCpp, yAsm);
    }
    //zad2
    {
        setConsoleTextColor(GOLD);
        cout << "*** 02 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        double yAsm = asm01_02sd(a, b);
        double yCpp = cpp01_02(a, b);
        resultComparator(yCpp, yAsm);
    }
    //zad3
    {
        setConsoleTextColor(GOLD);
        cout << "*** 03 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        double yAsm = asm01_03sd(a, b);
        double yCpp = cpp01_03(a, b);
        resultComparator(yCpp, yAsm);
    }
    //zad4
    {
        setConsoleTextColor(GOLD);
        cout << "*** 04 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        double yAsm = asm01_04sd(a, b);
        double yCpp = cpp01_04(a, b);
        resultComparator(yCpp, yAsm);
    }
    //zad5
    {
        setConsoleTextColor(GOLD);
        cout << "*** 05 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        double yAsm = asm01_05sd(a, b);
        double yCpp = cpp01_05(a, b);
        resultComparator(yCpp, yAsm);
    }
    //zad7
    {
        setConsoleTextColor(GOLD);
        cout << "*** 07 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>();
        cout << "a = " << a << endl;
        double yAsm = asm01_07sd(a);
        double yCpp = cpp01_07(a);
        resultComparator(yCpp, yAsm);
    }

    {
        setConsoleTextColor(GOLD);
        cout << "*** 2.1 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>(), x = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "x = " << x << endl;
        double yAsm = asm02_01sd(a, b, x);
        double yCpp = cpp02_01(a, b, x);
        resultComparator(yCpp, yAsm);
    }

    {
        setConsoleTextColor(GOLD);
        cout << "*** 2.8 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>(), c = rndf<double>(), d = rndf<double>(), x = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
        cout << "x = " << x << endl;
        double yAsm = asm02_08sd(a, b, c, d, x);
        double yCpp = cpp02_08(a, b, c, d, x);
        resultComparator(yCpp, yAsm);
    }
    system("pause");
    return 0;
}