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

int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand((uint)time(0));
    uint n = 10;
    {
        float* a = newFillPtr<float>(n);
        float yAsm = 0;
        float yCpp = 1;
        for (int i = 0; i < n; i++) {
            yCpp *= a[i];
        }
        __asm {
            mov ecx, n;
            mov esi, a;
            fld1;//sum
        _loop:
            fld dword ptr[esi + 4 * ecx - 4];
            fmul;
            dec ecx;
            jnz _loop;
            fstp yAsm;
        }
        cout << "----- 1.2 -----" << endl;
        printPtr(a, n);
        resultComparator(yCpp, yAsm);
        freePtr(a);
    }

    {
        double* a = newFillPtr<double>(n);
        double _15 = 15.0;
        double _9 = 9.0;
        double _10 = 10.0;
        double* yAsm = newFillPtr<double>(n);
        double* yCpp = newFillPtr<double>(n);
        for (int i = 0; i < n; i++) {
            yCpp[i] = 15 * a[i] * a[i] - 9 * a[i] + log2(10);
        }
        __asm {
            mov ecx, n;
            mov esi, a;
            mov edi, yAsm;
        _loop1:
            fld qword ptr[esi + 8 * ecx - 8];
            fld st;
            fld st;
            fmul;// a[i]^2, a[i]
            fld _15;
            fmul;//15a[i]^2, a[i]
            fxch;
            fld _9;
            fmul;//9a[i], 15a[i]^2
            fsub;
            fld1;
            fld _10;
            fyl2x;
            fadd;
            fstp qword ptr[edi + 8 * ecx - 8];
            dec ecx;
            jnz _loop1;
        }
        cout << "Zad 2.2" << endl;
        printPtr(a, n);
        resultComparator(yCpp, yAsm, n);

        freePtr(a);
    }
    system("pause");
    return 0;
}