#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
#include <iostream>
#include <ctime>
#include "utils.h"
#include "lab05.h"
using namespace std;

extern "C" int64 asm01_01(int**, uint, uint);
extern "C" int64 asm01_02(int64**, uint, uint);
extern "C" int64 asm01_04(int64**, uint, uint);
extern "C" int asm01_06(int**,int**, uint, uint);
extern "C" int64 asm01_07(int64**, uint, uint);
extern "C" int64 asm01_08(int64**, uint, uint);
extern "C" int64 asm01_09(int64**, uint, uint);
extern "C" int64 asm01_14(int64**, uint, uint);
extern "C" int64 asm01_17(int64**, uint, uint);
extern "C" int64 asm01_18(int64**, uint, uint);
extern "C" int64 asm01_20(int64**, uint, uint);
extern "C" int64 asm01_22(int64**, uint, uint);
extern "C" void asm02_02(int64**, uint, uint);
extern "C" void asm02_08(short**, uint, uint);
extern "C" void asm02_04(int**, int**, uint, uint);
extern "C" void asm02_09(short**, uint, uint);
extern "C" void asm02_11(int64**, uint, uint);
extern "C" void asm02_18(int**,int**, uint, uint);

int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand((uint)time(0));
    int n = 0;
    cout << "Podaj numer zadania w formacie x= temat y=numer zadania xy: ";
    cin >> n;
    switch (n)
    {
    case 11:
    {
        uint rows = 4, cols = 3;
        int** A = newFillPtr<int>(rows, cols);
        printPtr(A, rows, cols);
        int64 yAsm = asm01_01(A, rows, cols);
        int64 yCpp = cpp01_01<int64, int>(A, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        break;
    }
    case 12:
    {
        uint rows = 3, cols = 3;
        int64** A = newFillPtr<int64>(rows, cols);
        printPtr(A, rows, cols);
        int64 yAsm = asm01_02(A, rows, cols);
        int64 yCpp = cpp01_02<int64, int64>(A, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        break;
    }
    case 14:
    {
        uint rows = 3, cols = 3;
        int64** A = newFillPtr<int64>(rows, cols, false, -5);
        printPtr(A, rows, cols);
        int64 yAsm = asm01_04(A, rows, cols);
        int64 yCpp = cpp01_04<int64, int64>(A, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        break;
    }
    case 16:
    {
        uint rows = 4, cols = 3;
        int** A = newFillPtr<int>(rows, cols), **B =newFillPtr<int>(rows,cols);
        printPtr(A,rows,cols);
        printPtr(B, rows, cols);
        int yAsm = asm01_06(A, B, rows, cols);
        int yCpp = cpp01_06<int,int>(A, B, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        freePtr(B, rows);
    }   
    case 17:
    {
        uint rows = 5, cols = 2;
        int64** A = newFillPtr<int64>(rows, cols);
        printPtr(A, rows, cols);
        int64 yAsm = asm01_07(A, rows, cols);
        int64 yCpp = cpp01_07<int64, int64>(A, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        break;
    }
    case 18:
    {
        uint rows = 5, cols = 2;
        int64** A = newFillPtr<int64>(rows, cols);
        printPtr(A, rows, cols);
        int64 yAsm = asm01_08(A, rows, cols);
        int64 yCpp = cpp01_08<int64, int64>(A, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        break;
    }
    case 19:
    {
        uint rows = 5, cols = 3;
        int64** A = newFillPtr<int64>(rows, cols);
        printPtr(A, rows, cols);
        int64 yAsm = asm01_09(A, rows, cols);
        int64 yCpp = cpp01_09<int64, int64>(A, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        break;
    }
    case 114:
    {
        uint rows = 5, cols = 3;
        int64** A = newFillPtr<int64>(rows, cols);
        printPtr(A, rows, cols);
        int64 yAsm = asm01_14(A, rows, cols);
        int64 yCpp = cpp01_14<int64, int64>(A, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        break;
    }
    case 117:
    {
        uint rows = 5, cols = 3;
        int64** A = newFillPtr<int64>(rows, cols);
        printPtr(A, rows, cols);
        int64 yAsm = asm01_17(A, rows, cols);
        int64 yCpp = cpp01_17<int64, int64>(A, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        break;
    }
    case 118:
    {
        uint rows = 5, cols = 3;
        int64** A = newFillPtr<int64>(rows, cols);
        printPtr(A, rows, cols);
        int64 yAsm = asm01_18(A, rows, cols);
        int64 yCpp = cpp01_18<int64, int64>(A, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        break;
    }
    case 120:
    {
        uint rows = 5, cols = 3;
        int64** A = newFillPtr<int64>(rows, cols);
        printPtr(A, rows, cols);
        int64 yAsm = asm01_20(A, rows, cols);
        int64 yCpp = cpp01_20<int64, int64>(A, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        break;
    }
    case 122:
    {
        uint rows = 5, cols = 3;
        int64** A = newFillPtr<int64>(rows, cols);
        printPtr(A, rows, cols);
        int64 yAsm = asm01_22(A, rows, cols);
        int64 yCpp = cpp01_22<int64, int64>(A, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        break;
    }
    case 22:
    {   
        uint rows = 5, cols = 6;
        int64** a = newFillPtr<int64>(rows, cols);
        int64** b = newCopyPtr<int64,int64>(a,rows, cols);

        printPtr<int64>(a, rows, cols);

        asm02_02(a, rows, cols);
        cpp02_02<int64>(b, rows, cols);

        printPtr<int64>(a, rows, cols);
        printPtr<int64>(b, rows, cols);
        resultComparator<int64>(b, a, rows, cols);

        freePtr(a, rows);
        break;
    }
    case 24:
    {
        uint rows = 3, cols = 3;
        int** a = newFillPtr<int>(rows, cols);
        int** b = newFillPtr<int>(rows, cols);
        int** c = newCopyPtr<int,int>(a,rows, cols);
        int** d = newCopyPtr<int, int>(b, rows, cols);
        printPtr(a, rows, cols);
        printPtr(b, rows, cols);

        asm02_04(a, b, rows, cols);
        cpp02_04<int>(c, d, rows, cols);

        printPtr(a, rows, cols);
        printPtr(c, rows, cols);

        resultComparator(c, a, rows, cols);

        freePtr(a, rows);
        freePtr(b, rows);
        break;
    }
    case 28:
    {
        uint rows = 8, cols = 6;
        short** A = newFillPtr<short>(rows, cols);
        short** B = newCopyPtr<short,short>(A,rows, cols);
        printPtr(A, rows, cols);
        printPtr(B, rows, cols);
        asm02_08(A, rows, cols);
        cpp02_08(B, rows, cols);
        
        printPtr(A, rows, cols);
        printPtr(B, rows, cols);
        
        resultComparator(B, A, rows, cols);
        freePtr(A, rows);
        freePtr(B, rows);
        break;
    }
    case 29:
    {
        uint rows = 8, cols = 6;
        short** A = newFillPtr<short>(rows, cols);
        short** B = newCopyPtr<short, short>(A, rows, cols);
        printPtr(A, rows, cols);
        printPtr(B, rows, cols);
        asm02_09(A, rows, cols);
        cpp02_09(B, rows, cols);

        printPtr(A, rows, cols);
        printPtr(B, rows, cols);

        resultComparator(B, A, rows, cols);
        freePtr(A, rows);
        freePtr(B, rows);
        break;
    }
    case 211: 
    {
        uint rows = 10, cols = 8;
        int64** a = newFillPtr<int64>(rows, cols);
        int64** b = newCopyPtr<int64>(a, rows, cols);
        printPtr(a, rows, cols);
        asm02_11(a, rows, cols);
        cpp02_11<int64>(b, rows, cols);

        printPtr(a, rows, cols);
        printPtr(b, rows, cols);

        resultComparator(b, a, rows, cols);

        freePtr(b, rows);
        freePtr(a, rows);
        break;
    }
    case 218:
    {
        uint rows = 10, cols = 8;
        int** a = newFillPtr<int>(rows, cols);
        int** b = newFillPtr<int>( rows, cols, false);
        int** c = newFillPtr<int>(rows, cols, false);
        printPtr(a, rows, cols);

        asm02_18(a,b, rows, cols);
        cpp02_18<int>(a,c, rows, cols);

        printPtr(b, rows, cols);
        printPtr(c, rows, cols);

        resultComparator(c,b, rows, cols);

        freePtr(b, rows);
        freePtr(a, rows);
        break;
    }
    default:
        break;
    }


    system("pause");
    return 0;
}