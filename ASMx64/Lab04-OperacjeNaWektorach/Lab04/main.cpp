#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
#include <iostream>
#include <ctime>
#include "utils.h"
#include "lab04.h"
using namespace std;

extern "C" int asm04_01(int*, uint);
extern "C" int asm04_02(int*, uint);
extern "C" int asm04_03(int*, uint);
extern "C" int asm04_04(int*, uint);
extern "C" int asm04_05(int*, uint);
extern "C" int asm04_06(int*, int*, uint);
extern "C" int64 asm04_07(short*, uint);
extern "C" int asm04_08(int*, uint);
extern "C" int asm04_11(int64*, uint);
extern "C" void asm05_01(short*, short*, uint);
extern "C" void asm05_02(int64*, int*, uint);
extern "C" void asm05_03(int64*, int*, int*, uint);
extern "C" void asm05_05(int64*, short*,short*, uint);
extern "C" void asm05_06(int64*, int64*, int64*, uint);
extern "C" void asm05_07(int*, uint);




int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand((uint)time(0));
    const uint n = 10;
    int* a = newFillPtr<int>(n);
    printPtr(a, n);
    //zad04_01
    {
        int yAsm = asm04_01(a, n);
        int yCpp = cpp04_01<int, int>(a, n);
        resultComparator(yCpp, yAsm);
    }
    //zad04_02
    {
        const uint nn = 4;
        int* aa = newFillPtr<int>(n);
        printPtr(aa, nn);

        int yAsm = asm04_02(aa, nn);
        int yCpp = cpp04_02<int, int>(aa, nn);
        resultComparator(yCpp, yAsm);
        freePtr(aa);
    }
    //zad04_03
    {
        int yAsm = asm04_03(a, n);
        int yCpp = cpp04_03<int,int>(a, n);
        resultComparator(yCpp, yAsm);
    }
    //zad04_04
    {
        int yAsm = asm04_04(a, n);
        int yCpp = cpp04_04<int, int>(a, n);
        resultComparator(yCpp, yAsm);
    }
    //zad04_05
    {
        if (cpp04_05<int,int>(a, n) > 0) {
            int yAsm = asm04_05(a, n);
            int yCpp = cpp04_05<int, int>(a, n);
            resultComparator(yCpp, yAsm);
        }
    }
    //Tutaj jest problem z dzieleniem
    //zad04_06
    {
        int* b = newFillPtr<int>(n);
        int yAsm = asm04_06(a,b, n);
        int yCpp = cpp04_06<int, int>(a,b, n);
        resultComparator(yCpp, yAsm);
        freePtr(b);
    }
    //zad04_07
    {
        short* as = newFillPtr<short>(n);
        int64 yAsm = asm04_07(as, n);
        int64 yCpp = cpp04_07<int64, short>(as, n);
        resultComparator(yCpp, yAsm);

        freePtr(as);
    }
    //zad04_08
    {
        int yAsm = asm04_08(a, n);
        int yCpp = cpp04_08<int, int>(a, n);
        resultComparator(yCpp, yAsm);
    }
    //zad_04_11
    freePtr(a);
    {
        int64* a64 = newFillPtr<int64>(n);
        int64 yAsm = asm04_11(a64, n);
        int64 yCpp = cpp04_11<int64, int64>(a64, n);
        resultComparator(yCpp, yAsm);
        freePtr(a64);
    }
    //zad05_01
    {
        short* a = newFillPtr<short>(n);
        short* yAsm = newFillPtr<short>(n, false);
        short* yCpp = newFillPtr<short>(n, false);
        printPtr(a, n);
        
        asm05_01(yAsm, a, n);
        cpp05_01<short, short>(yCpp, a, n);

        printPtr(yAsm, n);
        printPtr(yCpp, n);

        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(yAsm);
        freePtr(yCpp);
    }
    //zad05_02
    {
        int* a = newFillPtr<int>(n);
        int64* yAsm = newFillPtr<int64>(n, false);
        int64* yCpp = newFillPtr<int64>(n, false);
        printPtr(a, n);

        asm05_02(yAsm, a, n);
        cpp05_02<int64, int>(yCpp, a, n);

        printPtr(yAsm, n);
        printPtr(yCpp, n);


        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(yAsm);
        freePtr(yCpp);
    }
    //zad05_03
    {
        const uint n = 10;
        int* a = newFillPtr<int>(n);
        int* b = newFillPtr<int>(n);
        int64* yCpp = newFillPtr<int64>(n, false);
        int64* yAsm = newFillPtr<int64>(n, false);

        printPtr(a, n);
        printPtr(b, n);

        asm05_03(yAsm, a, b, n);
        cpp05_03<int64, int>(yCpp, a, b, n);
        
        printPtr(yAsm, n);
        printPtr(yCpp, n);

        resultComparator(yCpp, yAsm,n);

        freePtr(yCpp);
        freePtr(yAsm);
        freePtr(a);
        freePtr(b);
    }
    //zad05_05 
    {
        const uint n = 10;
        short* a = newFillPtr<short>(n);
        short* b = newFillPtr<short>(n);
        int64* yCpp = newFillPtr<int64>(n, false);
        int64* yAsm = newFillPtr<int64>(n, false);
        
        printPtr(a, n);
        printPtr(b, n);
        
        asm05_05(yAsm, a, b, n);
        cpp05_05<int64, short>(yCpp, a, b, n);
        
        printPtr(yAsm, n);
        printPtr(yCpp, n);
        
        resultComparator(yCpp, yAsm, n);
        
        freePtr(yCpp);
        freePtr(yAsm);
        freePtr(a);
        freePtr(b);
    }
    //zad05_06
    {
        const uint n = 10;
        int64* a = newFillPtr<int64>(n);
        int64* b = newFillPtr<int64>(n);
        int64* yCpp = newFillPtr<int64>(n, false);
        int64* yAsm = newFillPtr<int64>(n, false);

        printPtr(a, n);
        printPtr(b, n);

        asm05_06(yAsm, a, b, n);
        cpp05_06<int64, int64>(yCpp, a, b, n);

        printPtr(yAsm, n);
        printPtr(yCpp, n);

        resultComparator(yCpp, yAsm, n);

        freePtr(yCpp);
        freePtr(yAsm);
        freePtr(a);
        freePtr(b);
    }
    //zad05_07
    {
        int* a = newFillPtr<int>(n);
        int* b = newCopyPtr<int, int>(a, n);
        printPtr(a,n);

        asm05_07(a, n);
        cpp05_07<int>(b, n);

        printPtr(a, n);
        printPtr(b, n);
        resultComparator(a, b, n);
        freePtr(a);
    }
    system("pause");
    return 0;
}