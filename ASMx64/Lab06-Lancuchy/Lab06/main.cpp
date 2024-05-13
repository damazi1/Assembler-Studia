#define _USE_MATH_DEFINES
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
#include <ctime>
#include "utils.h"
/* Put additional user headers below this comment */
#include "lab06.h"

using namespace std;

// Arrays size (variable shared between all asm06_xx_xx functions)
constexpr uint n = 10;

// Copy array a to b -> REP MOVSx
extern "C" void asm06_01_01_01(uint, char*, char*);
extern "C" void asm06_01_01_02(uint, short*, short*);
extern "C" void asm06_01_01_03(uint, int*, int*);
extern "C" void asm06_01_01_04(uint, int64*, int64*);

// Fill array with value - REP STOSx
extern "C" void asm06_02_01_01(uint, char *, char);
extern "C" void asm06_02_01_02(uint, short*, short);
extern "C" void asm06_02_01_03(uint, int*, int);
extern "C" void asm06_02_01_04(uint, int64*, int64);

// Compare arrays a to b and check whether they contains the same elements -> REPE CMPSx
extern "C" int64 asm06_03_01_01(uint, char*, char*);
extern "C" int64 asm06_03_01_02(uint, short*, short*);
extern "C" int64 asm06_03_01_03(uint, int*, int*);
extern "C" int64 asm06_03_01_04(uint, int64*, int64*);

extern "C" int64 asm06_03_02_01(uint, char*, char*);
extern "C" int64 asm06_03_02_02(uint, short*, short*);
extern "C" int64 asm06_03_02_03(uint, int*, int*);
extern "C" int64 asm06_03_02_04(uint, int64*, int64*);

// Find value in the array - SCASx
// If requested value is found return 1, return 0 otherwise
extern "C" int64 asm06_04_01_01(uint, char*, char);
extern "C" int64 asm06_04_01_02(uint, short*, short);
extern "C" int64 asm06_04_01_03(uint, int*, int);
extern "C" int64 asm06_04_01_04(uint, int64*, int64);

// If requested value is found return index, return -1 otherwise
extern "C" int64 asm06_04_02_01(uint, char*, char);
extern "C" int64 asm06_04_02_02(uint, short*, short);
extern "C" int64 asm06_04_02_03(uint, int*, int);
extern "C" int64 asm06_04_02_04(uint, int64*, int64);

// Count occurences of a given value in the array
extern "C" int64 asm06_04_03_01(uint, char*, char);
extern "C" int64 asm06_04_03_02(uint, short*, short);
extern "C" int64 asm06_04_03_03(uint, int*, int);
extern "C" int64 asm06_04_03_04(uint, int64*, int64);

// Count occurences of values different than a given value in the array
extern "C" int64 asm06_04_04_01(uint, char*, char);
extern "C" int64 asm06_04_04_02(uint, short*, short);
extern "C" int64 asm06_04_04_03(uint, int*, int);
extern "C" int64 asm06_04_04_04(uint, int64*, int64);

// Count elements in the array - LODSx
// Count if a[i] % 2 == 0
extern "C" int64 asm06_05_01_01(uint, char*);
extern "C" int64 asm06_05_01_02(uint, short*);
extern "C" int64 asm06_05_01_03(uint, int*);
extern "C" int64 asm06_05_01_04(uint, int64*);

// Count if a[i] % 2 != 0
extern "C" int64 asm06_05_02_01(uint, char*);
extern "C" int64 asm06_05_02_02(uint, short*);
extern "C" int64 asm06_05_02_03(uint, int*);
extern "C" int64 asm06_05_02_04(uint, int64*);

// Count if a[i] < val
extern "C" int64 asm06_05_03_01(uint, char*, char);
extern "C" int64 asm06_05_03_02(uint, short*, short);
extern "C" int64 asm06_05_03_03(uint, int*, int);
extern "C" int64 asm06_05_03_04(uint, int64*, int64);

// Count if a[i] > val
extern "C" int64 asm06_05_04_01(uint, char*, char);
extern "C" int64 asm06_05_04_02(uint, short*, short);
extern "C" int64 asm06_05_04_03(uint, int*, int);
extern "C" int64 asm06_05_04_04(uint, int64*, int64);

// Modify elements in situ -> LODSx - fun - STOSx
// f(x) = (4x + 5) / 2
extern "C" void asm06_05_05_01(uint, char*);
extern "C" void asm06_05_05_02(uint, short*);
extern "C" void asm06_05_05_03(uint, int*);
extern "C" void asm06_05_05_04(uint, int64*);

// Copy elements from a to b and change their values -> LODSx - fun - STOSx
// f(x) = (4x + 5) / 2
extern "C" void asm06_05_06_01(uint, char*, char*);
extern "C" void asm06_05_06_02(uint, short*, short*);
extern "C" void asm06_05_06_03(uint, int*, int*);
extern "C" void asm06_05_06_04(uint, int64*, int64*);

// Copy elements from a to b in reverse order -> LODSx - fun - STOSx
extern "C" void asm06_05_07_01(uint, char*, char*);
extern "C" void asm06_05_07_02(uint, short*, short*);
extern "C" void asm06_05_07_03(uint, int*, int*);
extern "C" void asm06_05_07_04(uint, int64*, int64*);

// Reverse elements order in situ  -> LODSx - fun - STOSx
extern "C" void asm06_05_08_01(uint, char*);
extern "C" void asm06_05_08_02(uint, short*);
extern "C" void asm06_05_08_03(uint, int*);
extern "C" void asm06_05_08_04(uint, int64*);

// ltrim - remove leading whitespaces
extern "C" void asm_ltrim(uint, char*);
// rtrim - remove trailing whitespaces
extern "C" void asm_rtrim(uint, char*);
// trim - remove leading and trailing whitespaces
extern "C" void asm_trim(uint, char*);
// replace_all - replace all occurences of a given char by another char
extern "C" void asm_replace_all(uint, char*, char, char);

int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand((uint)time(0));

    //movsWrapper<char> (n, asm06_01_01_01, "asm06_01_01_01");              //+
    //movsWrapper<short>(n, asm06_01_01_02, "asm06_01_01_02");              //+
    //movsWrapper<int>  (n, asm06_01_01_03, "asm06_01_01_03");              //+
    //movsWrapper<int64>(n, asm06_01_01_04, "asm06_01_01_04");              //+
    //
    //stosWrapper<char> (n, asm06_02_01_01, "asm06_02_01_01");              //+
    //stosWrapper<short>(n, asm06_02_01_02, "asm06_02_01_02");              //+
    //stosWrapper<int>  (n, asm06_02_01_03, "asm06_02_01_03");              //+
    //stosWrapper<int64>(n, asm06_02_01_04, "asm06_02_01_04");              //+
    //
    //cmpsBoolWrapper<char> (n, asm06_03_01_01, "asm06_03_01_01", true);    //+
    //cmpsBoolWrapper<short>(n, asm06_03_01_02, "asm06_03_01_02", true);    //+
    //cmpsBoolWrapper<int>  (n, asm06_03_01_03, "asm06_03_01_03", true);    //+
    //cmpsBoolWrapper<int64>(n, asm06_03_01_04, "asm06_03_01_04", true);    //+
    ////                                                                    //+
    //cmpsBoolWrapper<char> (n, asm06_03_01_01, "asm06_03_01_01", false);   //+
    //cmpsBoolWrapper<short>(n, asm06_03_01_02, "asm06_03_01_02", false);   //+
    //cmpsBoolWrapper<int>  (n, asm06_03_01_03, "asm06_03_01_03", false);   //+
    //cmpsBoolWrapper<int64>(n, asm06_03_01_04, "asm06_03_01_04", false);   //+
    //
    //cmpsIdxWrapper<char> (n, asm06_03_02_01, "asm06_03_02_01", true);     //+
    //cmpsIdxWrapper<short>(n, asm06_03_02_02, "asm06_03_02_02", true);     //+
    //cmpsIdxWrapper<int>  (n, asm06_03_02_03, "asm06_03_02_03", true);     //+
    //cmpsIdxWrapper<int64>(n, asm06_03_02_04, "asm06_03_02_04", true);     //+
    ////                                                                    //+
    //cmpsIdxWrapper<char> (n, asm06_03_02_01, "asm06_03_02_01", false);    //+
    //cmpsIdxWrapper<short>(n, asm06_03_02_02, "asm06_03_02_02", false);    //+
    //cmpsIdxWrapper<int>  (n, asm06_03_02_03, "asm06_03_02_03", false);    //+
    //cmpsIdxWrapper<int64>(n, asm06_03_02_04, "asm06_03_02_04", false);    //+
    //
    //scasBoolWrapper<char> (n, asm06_04_01_01, "asm06_04_01_01", true);    //raz dziala raz nie ?!?!
    //scasBoolWrapper<short>(n, asm06_04_01_02, "asm06_04_01_02", true);    //raz dziala raz nie ?!?!
    //scasBoolWrapper<int>  (n, asm06_04_01_03, "asm06_04_01_03", true);    //raz dziala raz nie ?!?!
    //scasBoolWrapper<int64>(n, asm06_04_01_04, "asm06_04_01_04", true);    //raz dziala raz nie ?!?!
    ////                                                                    //raz dziala raz nie ?!?!
    //scasBoolWrapper<char> (n, asm06_04_01_01, "asm06_04_01_01", false);   //raz dziala raz nie ?!?!
    //scasBoolWrapper<short>(n, asm06_04_01_02, "asm06_04_01_02", false);   //raz dziala raz nie ?!?!
    //scasBoolWrapper<int>  (n, asm06_04_01_03, "asm06_04_01_03", false);   //raz dziala raz nie ?!?!
    //scasBoolWrapper<int64>(n, asm06_04_01_04, "asm06_04_01_04", false);   //raz dziala raz nie ?!?!
    //
    //scasIdxWrapper<char> (n, asm06_04_02_01, "asm06_04_02_01", true);       //+
    //scasIdxWrapper<short>(n, asm06_04_02_02, "asm06_04_02_02", true);       //+
    //scasIdxWrapper<int>  (n, asm06_04_02_03, "asm06_04_02_03", true);       //+
    //scasIdxWrapper<int64>(n, asm06_04_02_04, "asm06_04_02_04", true);       //+
    //                                                                        //+
    //scasIdxWrapper<char> (n, asm06_04_02_01, "asm06_04_02_01", false);      //+
    //scasIdxWrapper<short>(n, asm06_04_02_02, "asm06_04_02_02", false);      //+
    //scasIdxWrapper<int>  (n, asm06_04_02_03, "asm06_04_02_03", false);      //+
    //scasIdxWrapper<int64>(n, asm06_04_02_04, "asm06_04_02_04", false);      //+
    ////
    //scasCntWrapper<char> (n, asm06_04_03_01, "asm06_04_03_01", cpp06_04_cnt_eq, 0);     //+
    //scasCntWrapper<short>(n, asm06_04_03_02, "asm06_04_03_02", cpp06_04_cnt_eq, 0);     //+
    //scasCntWrapper<int>  (n, asm06_04_03_03, "asm06_04_03_03", cpp06_04_cnt_eq, 0);     //+
    //scasCntWrapper<int64>(n, asm06_04_03_04, "asm06_04_03_04", cpp06_04_cnt_eq, 0);     //+
    //
    //scasCntWrapper<char> (n, asm06_04_04_01, "asm06_04_04_01", cpp06_04_cnt_neq, 0);      //+
    //scasCntWrapper<short>(n, asm06_04_04_02, "asm06_04_04_02", cpp06_04_cnt_neq, 0);      //+
    //scasCntWrapper<int>  (n, asm06_04_04_03, "asm06_04_04_03", cpp06_04_cnt_neq, 0);      //+
    //scasCntWrapper<int64>(n, asm06_04_04_04, "asm06_04_04_04", cpp06_04_cnt_neq, 0);      //+
    //
    //trimWrapper(asm_ltrim, "ltrim");
    //trimWrapper(asm_rtrim, "rtrim");
    //trimWrapper(asm_trim, "trim");
    //replaceWrapper(' ', (const char)0x03, asm_replace_all, "replace_all");
    //
    //lodsParityWrapper<int>  (n, asm06_05_01_03, "asm06_05_01_03", cpp06_05_cnt_even);     //+
    //lodsParityWrapper<char> (n, asm06_05_01_01, "asm06_05_01_01", cpp06_05_cnt_even);     //+
    //lodsParityWrapper<int64>(n, asm06_05_01_04, "asm06_05_01_04", cpp06_05_cnt_even);     //+
    //lodsParityWrapper<short>(n, asm06_05_01_02, "asm06_05_01_02", cpp06_05_cnt_even);     //+
    //                                                                                      //+
    //lodsParityWrapper<char> (n, asm06_05_02_01, "asm06_05_02_01", cpp06_05_cnt_odd);      //+
    //lodsParityWrapper<short>(n, asm06_05_02_02, "asm06_05_02_02", cpp06_05_cnt_odd);      //+
    //lodsParityWrapper<int>  (n, asm06_05_02_03, "asm06_05_02_03", cpp06_05_cnt_odd);      //+
    //lodsParityWrapper<int64>(n, asm06_05_02_04, "asm06_05_02_04", cpp06_05_cnt_odd);      //+
    //
    //lodsCntWrapper<short>(n, asm06_05_03_02, "asm06_05_03_02", cpp06_05_cnt_less, 0);       //+
    //lodsCntWrapper<int>  (n, asm06_05_03_03, "asm06_05_03_03", cpp06_05_cnt_less, 0);       //+
    //lodsCntWrapper<int64>(n, asm06_05_03_04, "asm06_05_03_04", cpp06_05_cnt_less, 0);       //+
    //lodsCntWrapper<char> (n, asm06_05_03_01, "asm06_05_03_01", cpp06_05_cnt_less, 0);       //+
    //                                                                                        //+
    //lodsCntWrapper<char> (n, asm06_05_04_01, "asm06_05_04_01", cpp06_05_cnt_greater, 0);    //+
    //lodsCntWrapper<short>(n, asm06_05_04_02, "asm06_05_04_02", cpp06_05_cnt_greater, 0);    //+
    //lodsCntWrapper<int>  (n, asm06_05_04_03, "asm06_05_04_03", cpp06_05_cnt_greater, 0);    //+
    //lodsCntWrapper<int64>(n, asm06_05_04_04, "asm06_05_04_04", cpp06_05_cnt_greater, 0);    //+
    //
    //lodsInSituWrapper<char> (n, asm06_05_05_01, "asm06_05_05_01", cpp06_05_fun);
    //lodsInSituWrapper<short>(n, asm06_05_05_02, "asm06_05_05_02", cpp06_05_fun);
    //lodsInSituWrapper<int>  (n, asm06_05_05_03, "asm06_05_05_03", cpp06_05_fun);
    //lodsInSituWrapper<int64>(n, asm06_05_05_04, "asm06_05_05_04", cpp06_05_fun);
    //
    //lodsOtherWrapper<char> (n, asm06_05_06_01, "asm06_05_06_01", cpp06_05_fun);
    //lodsOtherWrapper<short>(n, asm06_05_06_02, "asm06_05_06_02", cpp06_05_fun);
    //lodsOtherWrapper<int>  (n, asm06_05_06_03, "asm06_05_06_03", cpp06_05_fun);
    //lodsOtherWrapper<int64>(n, asm06_05_06_04, "asm06_05_06_04", cpp06_05_fun);
    //
    //lodsOtherWrapper<char> (n, asm06_05_07_01, "asm06_05_07_01", cpp06_05_cpy);
    //lodsOtherWrapper<short>(n, asm06_05_07_02, "asm06_05_07_02", cpp06_05_cpy);
    //lodsOtherWrapper<int>  (n, asm06_05_07_03, "asm06_05_07_03", cpp06_05_cpy);
    //lodsOtherWrapper<int64>(n, asm06_05_07_04, "asm06_05_07_04", cpp06_05_cpy);
    //
    //lodsInSituWrapper<char> (n, asm06_05_08_01, "asm06_05_08_01", cpp06_05_cpy);
    //lodsInSituWrapper<short>(n, asm06_05_08_02, "asm06_05_08_02", cpp06_05_cpy);
    //lodsInSituWrapper<int>  (n, asm06_05_08_03, "asm06_05_08_03", cpp06_05_cpy);
    //lodsInSituWrapper<int64>(n, asm06_05_08_04, "asm06_05_08_04", cpp06_05_cpy);

    system("pause");
    return 0;
}