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
extern "C" double asm01_06sd(double, double);
extern "C" double asm01_07sd(double);
extern "C" float asm01_08ss(float, float, float);
extern "C" float asm01_09ss(float);
extern "C" double asm01_11sd(double, double, double, double);
extern "C" double asm01_12sd(double, double, double, double, double, double);
extern "C" double asm01_16sd(double);
extern "C" double asm02_01sd(double, double, double);
extern "C" double asm02_02sd(double, double, double);
extern "C" double asm02_03sd(double, double, double);
extern "C" double asm02_04sd(double, double, double);
extern "C" float asm02_05ss(float, float);
extern "C" float asm02_06ss(float, float);
extern "C" double asm02_07sd(double, double, double, double, double);
extern "C" double asm02_08sd(double, double, double, double, double);
extern "C" double asm02_09sd(double, double, double, double, double);
extern "C" double asm02_10sd(double, double, double, double, double);
extern "C" double asm02_11sd(double, double, double, double);
extern "C" double asm02_12sd(double, double, double);

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
    //zad6
    {
        setConsoleTextColor(GOLD);
        cout << "*** 06 ***" << endl;
        setConsoleTextColor();
        double a = 0.23, b = 0.59;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        double yAsm = asm01_06sd(a, b);
        double yCpp = cpp01_06(a, b);
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

    //zad8
    {
        setConsoleTextColor(GOLD);
        cout << "*** 08 ***" << endl;
        setConsoleTextColor();
        float a = rndf<float>();
        float b = rndf<float>();
        float x = rndf<float>();
        cout << "a = " << a << endl;
        float yAsm = asm01_08ss(a,b,x);
        float yCpp = cpp01_08(a,b,x);
        resultComparator(yCpp, yAsm);
    }
    //zad9
    {
        setConsoleTextColor(GOLD);
        cout << "*** 09 ***" << endl;
        setConsoleTextColor();
        float x = rndf<float>();
        cout << "x = " << x << endl;
        float yAsm = asm01_09ss(x);
        float yCpp = cpp01_09(x);
        resultComparator(yCpp, yAsm);
    }

    //zad11
    {
        setConsoleTextColor(GOLD);
        cout << "*** 11 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>();
        double b = rndf<double>();
        double c = rndf<double>();
        double d = rndf<double>();
        cout << "a = " << a;
        cout << "\tb = " << b;
        cout << "\tc = " << c;
        cout << "\td = " << d << endl;
        float yAsm = asm01_11sd(a, b, c, d);
        float yCpp = cpp01_11(a,b,c,d);
        resultComparator(yCpp, yAsm);
    }

    //zad12
    {
        setConsoleTextColor(GOLD);
        cout << "*** 12 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>();
        double b = rndf<double>();
        double c = rndf<double>();
        double d = rndf<double>();
        double e = 0.91;
        double f = 0.51;
        cout << "a = " << a;
        cout << "\tb = " << b;
        cout << "\tc = " << c;
        cout << "\td = " << d;
        cout << "\te = " << e;
        cout << "\tf = " << f << endl;
        float yAsm = asm01_12sd(a, b, c, d,e,f);
        float yCpp = cpp01_12(a, b, c, d,e,f);
        resultComparator(yCpp, yAsm);
    }
    //zad16
    {
        setConsoleTextColor(GOLD);
        cout << "*** 16 ***" << endl;
        setConsoleTextColor();
        double r = rndf<double>();
        cout << "x = " << r << endl;
        double yAsm = asm01_16sd(r);
        double yCpp = cpp01_16(r);
        resultComparator(yCpp, yAsm);
    }
    //zad2.1
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
    //zad2.2
    {
        setConsoleTextColor(GOLD);
        cout << "*** 2.2 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>(), x = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "x = " << x << endl;
        double yAsm = asm02_02sd(a, b, x);
        double yCpp = cpp02_02(a, b, x);
        resultComparator(yCpp, yAsm);
    }
    //zad2.3
    {
        setConsoleTextColor(GOLD);
        cout << "*** 2.3 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>(), x = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "x = " << x << endl;
        double yAsm = asm02_03sd(a, b, x);
        double yCpp = cpp02_03(a, b, x);
        resultComparator(yCpp, yAsm);
    }
    //zad2.4
    {
        setConsoleTextColor(GOLD);
        cout << "*** 2.4 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>(), x = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "x = " << x << endl;
        double yAsm = asm02_04sd(a, b, x);
        double yCpp = cpp02_04(a, b, x);
        resultComparator(yCpp, yAsm);
    }
    //zad2.5
    {
        setConsoleTextColor(GOLD);
        cout << "*** 2.5 ***" << endl;
        setConsoleTextColor();
        float a = rndf<float>(), x = rndf<float>();
        cout << "a = " << a << endl;
        cout << "x = " << x << endl;
        float yAsm = asm02_05ss(a, x);
        float yCpp = cpp02_05(a, x);
        resultComparator(yCpp, yAsm);
    }
    //zad2.6
    {
        setConsoleTextColor(GOLD);
        cout << "*** 2.6 ***" << endl;
        setConsoleTextColor();
        float a = rndf<float>(), x = rndf<float>();
        cout << "a = " << a << endl;
        cout << "x = " << x << endl;
        float yAsm = asm02_06ss(a, x);
        float yCpp = cpp02_06(a, x);
        resultComparator(yCpp, yAsm);
    }
    //zad2.7
    {
        setConsoleTextColor(GOLD);
        cout << "*** 2.7 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>(), c = rndf<double>(), d = rndf<double>(), x = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
        cout << "x = " << x << endl;
        double yAsm = asm02_07sd(a, b, c, d, x);
        double yCpp = cpp02_07(a, b, c, d, x);
        resultComparator(yCpp, yAsm);
    }
    //zad2.8
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
    //zad2.9
    {
        setConsoleTextColor(GOLD);
        cout << "*** 2.9 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>(), c = rndf<double>(), d = rndf<double>(), x = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
        cout << "x = " << x << endl;
        double yAsm = asm02_09sd(a, b, c, d, x);
        double yCpp = cpp02_09(a, b, c, d, x);
        resultComparator(yCpp, yAsm);
    }
    //zad2.10
    {
        setConsoleTextColor(GOLD);
        cout << "*** 2.10 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>(), c = rndf<double>(), d = rndf<double>(), x = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "d = " << d << endl;
        cout << "x = " << x << endl;
        double yAsm = asm02_10sd(a, b, c, d, x);
        double yCpp = cpp02_10(a, b, c, d, x);
        resultComparator(yCpp, yAsm);
    }
    //zad2.11
    {
        setConsoleTextColor(GOLD);
        cout << "*** 2.11 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>(), c = rndf<double>(),  x = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
        cout << "x = " << x << endl;
        double yAsm = asm02_11sd(a, b, c, x);
        double yCpp = cpp02_11(a, b, c, x);
        resultComparator(yCpp, yAsm);
    }
    //zad2.12
    {
        setConsoleTextColor(GOLD);
        cout << "*** 2.12 ***" << endl;
        setConsoleTextColor();
        double a = rndf<double>(), b = rndf<double>(), x = rndf<double>();
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "x = " << x << endl;
        double yAsm = asm02_12sd(a, b, x);
        double yCpp = cpp02_12(a, b, x);
        resultComparator(yCpp, yAsm);
    }
    system("pause");
    return 0;
}