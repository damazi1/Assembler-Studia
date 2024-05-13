#include <iostream>
#include <iomanip>
#include <ctime>
#include <bitset>
#include <limits>
#include <type_traits>

template<typename T>
//static inline  // static if you want to compile with -mpopcnt in one compilation unit but not others
typename std::enable_if<std::is_integral<T>::value, unsigned >::type
popcount(T x)
{
	static_assert(std::numeric_limits<T>::radix == 2, "non-binary type");

	// sizeof(x)*CHAR_BIT
	constexpr int bitwidth = std::numeric_limits<T>::digits + std::numeric_limits<T>::is_signed;
	// std::bitset constructor was only unsigned long before C++11.  Beware if porting to C++03
	static_assert(bitwidth <= std::numeric_limits<unsigned long long>::digits, "arg too wide for std::bitset() constructor");

	typedef typename std::make_unsigned<T>::type UT;        // probably not needed, bitset width chops after sign-extension

	std::bitset<bitwidth> bs(static_cast<UT>(x));
	return bs.count();
}

unsigned test_u64(unsigned long long a) { return popcount(a); }

using namespace std;

typedef long long int INT64;
typedef unsigned int uint;

extern "C" INT64 asm_03_04_01(INT64);
extern "C" INT64 asm_03_04_02(INT64, INT64, INT64);
extern "C" INT64 asm_03_04_03(INT64, INT64, INT64);
extern "C" INT64 asm_03_04_06(INT64, INT64, INT64, INT64);
extern "C" INT64 asm_03_05_01(INT64, INT64);
extern "C" INT64 asm_03_05_02(INT64);
extern "C" INT64 asm_03_05_03(INT64, INT64);
extern "C" INT64 asm_03_05_04(INT64, INT64);
extern "C" INT64 asm_03_05_05(INT64, INT64);
extern "C" INT64 asm_03_05_09(INT64);
extern "C" INT64 asm_03_05_10(INT64); 
extern "C" INT64 asm_03_05_11(INT64);
extern "C" INT64 asm_03_05_12(INT64);

template <typename T>
T factorial(T n) {
	return (n == 0) || (n == 1) ? 1 : n * factorial(n - 1);
}
template <typename T>
T fibonacci(T n)
{
	T a = 1, b = 1;
	for (T i = 0; i < n; i++)
	{
		b += a; //pod zmiennš b przypisujemy wyraz następny czyli a+b
		a = b - a; //pod zmiennš a przypisujemy wartoć zmiennej b
	}
	return a;
}

template <typename T>
T rnd(T min, T max) {
	return rand() % (max - min) + min;
}

int main() {
	srand((unsigned)time(0));
	INT64 a = rnd(-100, 100), b = rnd(-100, 100),c = rnd(-100, 100), y = 0, i = rnd(0, 4);
	cout << "Wylosowane liczby to a = " << a << ", b = " << b << " , i =" << i << endl;

	// zad 1
	switch (i)
	{
	case 0:
		y = 10;
		break;
	case 1:
		y = 20;
		break;
	default:
		y = 30;
	}
	INT64 wyn_01 = asm_03_04_01(i);
	cout << "1. [CPP]: " << y << endl;
	cout << "1. [ASM]: " << wyn_01 << endl;



	INT64 wyn_02 = asm_03_04_02(a, b, i);

	switch (i)
	{
	case(0):
		y = a + b;
		break;
	case(1):
		y = a - b;
		break;
	case(2):
		y = a * b;
		break;
	case(3):
		y = a / b;
		break;
	default:
		y = 0;
		break;
	}

	cout << "2. [CPP]: " << y << endl;
	cout << "2. [ASM]: " << wyn_02 << endl;
	i = 20;
	switch (i)
	{
	case(10):
		y = 32 * a + 16 * b;
		break;
	case(20):
		y = (a - b) / 4;
		break;
	default:
		y=a % 8;
		break;
	}

	INT64 wyn_03 = asm_03_04_03(a, b, i);


	cout << "3. [CPP]: " << y << endl;
	cout << "3. [ASM]: " << wyn_03 << endl;
	i = 10;
	if (i < 5) {
		y = (-500 * a) / (20 * b);
	}
	else if (i >= 10) {
		y = (-128 * a + b - 16 * c) / (abs(a + i + 1));
	}
	else {
		y = (-244 * a * i + 12 * b) / (16 * i);
	}

	INT64 wyn_06 = asm_03_04_06(a, b, c, i);

	cout << "6. [CPP]: " << y << endl;
	cout << "6. [ASM]: " << wyn_06 << endl;

	//Petle For
	cout << "=========================================================" << endl;
	cout << "+			PETLE FOR			+" << endl;
	cout << "=========================================================" << endl;
	INT64 wyn_05_01 = asm_03_05_01(a, b);
	cout << "1. [CPP]: " << a * b << endl;
	cout << "1. [ASM]: " << wyn_05_01 << endl;

	INT64 wyn_05_02 = asm_03_05_02(a);

	cout << "2. [CPP]: " << a * 40 << endl;
	cout << "2. [ASM]: " << wyn_05_02 << endl;
	
	INT64 wyn_05_03 = asm_03_05_03(a,b);

	cout << "3. [CPP]: " << a * 150+b << endl;
	cout << "3. [ASM]: " << wyn_05_03 << endl;

	INT64 wyn_05_04 = asm_03_05_04(a, b);

	cout << "4. [CPP]: " << (a+b)/10 << endl;
	cout << "4. [ASM]: " << wyn_05_04 << endl;

	INT64 wyn_05_05 = asm_03_05_05(a, b);

	//cout << "5. [CPP]: " << a/b << endl;
	//cout << "5. [ASM]: " << wyn_05_05 << endl;

	INT64 aa = 10;
	INT64 wyn_05_09 = asm_03_05_09(aa);
	cout << "9. [CPP]: " << factorial(aa) << endl;
	cout << "9. [ASM]: " << wyn_05_09 << endl;

	INT64 wyn_05_10 = asm_03_05_10(aa);
	cout << "10. [CPP]: " << fibonacci(aa) << endl;
	cout << "10. [ASM]: " << wyn_05_10 << endl;

	y = test_u64(430);
	INT64 wyn_05_11 = asm_03_05_11(430);
	cout << "11. [CPP]: " << y << endl;
	cout << "11. [ASM]: " << wyn_05_11 << endl;


	INT64 wyn_05_12 = asm_03_05_12(32);
	cout << "12. [ASM]: " << wyn_05_12 << endl;

	return 0;
}