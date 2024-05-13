#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

typedef unsigned int uint;

template <typename T>
T rnd(T min, T max) {
	return rand() % (max - min) + min;
}

template <typename T>
T mincpp(T a=0, T b=0) {
	return a < b ? a : b;
}
template <typename T>
T maxcpp(T a = 0, T b = 0) {
	return a > b ? a : b;

}

int signedmin(int a, int b) {
	int min = 0;
	__asm {
		mov eax, a
		mov ebx, b
		cmp eax, ebx
		jl _skip
		mov eax, ebx
	_skip:
		mov min , eax
	}
	return min;
}
int signedmax(int a, int b) {
	int max = 0;
	__asm {
		mov eax, a
		mov ebx, b
		cmp eax, ebx
		jg _skip
		mov eax, ebx
			_skip:
		mov max, eax
	}
	return max;
}

int unsignedcfmin(int a, int b) {
	int min = 0;
	__asm {
		mov eax, a
		mov ebx, b
		cmp eax, ebx
		jc _skip
		mov eax, ebx
		_skip :
		mov min, eax
	}
	return min;
}
int unsignedcfmax(int a, int b) {
	int max = 0;
	__asm {
		mov eax, a
		mov ebx, b
		cmp eax, ebx
		jnc _skip
		mov eax, ebx
		_skip :
		mov max, eax
	}
	return max;
}

int unsignedmin(int a, int b) {
	int min = 0;
	__asm {
		mov eax, a
		mov ebx, b
		cmp eax, ebx
		jb _skip
		mov eax, ebx
		_skip :
		mov min, eax
	}
	return min;
}
int unsignedmax(int a, int b) {
	int max = 0;
	__asm {
		mov eax, a
		mov ebx, b
		cmp eax, ebx
		jnb _skip
		mov eax, ebx
		_skip :
		mov max, eax
	}
	return max;
}

int movmin(int a, int b) {
	int min = 0;
	__asm {
		mov eax, a
		mov ebx, b
		cmp eax, ebx
		cmovg eax, ebx
		mov min, eax
	}
	return min;
}
int movmax(int a, int b) {
	int max = 0;
	__asm {
		mov eax, a
		mov ebx, b
		cmp eax, ebx
		cmovl eax, ebx
		mov max, eax
	}
	return max;
}

int absolute(int a) {
	int wyn = 0;
	__asm {
		mov eax, a
		mov ebx, a
		sal ebx, 1
		jnc _skip
		neg eax
	_skip:
		mov wyn, eax
	}
	return wyn;
}
char even_odd(int a) {
	char str;
	__asm {
		mov eax, a
		shr eax, 1
		jc _skip
		mov bl, 'e'
		mov str, bl
		jmp _end
	_skip:
		mov bl , 'o'
		mov str, bl
	_end:
	}
	return str;
}

int spr1(int a, int b) {
	int wyn = 0;
	__asm {
		mov eax, a
		mov ebx, b
		cmp eax, ebx
		jge _ge
		mov eax, -10
		jmp _end
		_ge:
		mov eax, 20
		_end:
		mov wyn, eax
	}
	return wyn;
}

int spr2(int a, int b) {
	int wyn = 0;
	__asm {
		mov eax, a
		mov ebx, b
		cmp eax, ebx
		jge _ge
		sub eax, ebx
		jmp _end
		_ge:
		add eax, ebx
		_end:
		mov wyn, eax
	}
	return wyn;
}

char reszta1(int a) {
	char y_n;
	__asm {
		mov eax, a
		cdq
		mov ebx, 5
		idiv ebx
		cmp edx, 0
		jz _skip
		mov al, 'n'
		jmp _end
	_skip:
		mov al, 'T'
	_end:
		mov y_n, al
	}
	return y_n;
}

char reszta2(int a) {
	char y_n;
	__asm {
		mov eax, a
		cdq
		mov ebx, 16
		idiv ebx
		cmp edx, 0
		jz _skip
		mov al, 'n'
		jmp _end
		_skip :
		mov al, 'T'
			_end :
			mov y_n, al
	}
	return y_n;
}
char znak(int a) {
	char z;
	__asm {
		mov eax, a
		shl eax, 1
		jc _skip
		mov al, 'n'
		jmp _end
	_skip:
		mov al, 'T'
	_end:
		mov z, al
	}
	return z;
}

int main() {
	srand((unsigned)time(0));
	int a = rnd(-100, 100), b = rnd(-100, 100);
	uint ua = rnd(0, 100), ub = rnd(0, 100);
	cout << "==================================================" << endl;
	cout << "Wartoœci liczb Ujemne/dodatnie: a = " << a << " , b = " << b << endl;
	cout << "Wartoœci liczb nieujemne: ua = " << ua << " , ub = " << ub << endl;
	cout << " Skoki warunkowe dla znaczionków flagowych" << endl;
	cout << "==================================================" << endl;
	//1. min(a,b)
	
	cout << "+---------------+-----+-----+" << endl;
	cout << "|Ujemne/Dodatnie| MIN | MAX |" << endl;
	cout << "+---------------+-----+-----+" << endl;
	cout << "| CPP           | " << setw(3) << mincpp(a, b) << " | " << setw(3) << maxcpp(a, b) << " | " << endl;
	cout << "| Signed ASM    | " << setw(3) << signedmin(a, b) << " | " << setw(3) << signedmax(a, b) << " | " << endl;
	cout << "|Unsigned CF ASM| " << setw(3) << unsignedcfmin(a, b) << " | " << setw(3) << unsignedcfmax(a, b) << " | " << endl;
	cout << "| Unsigned ASM  | " << setw(3) << unsignedmin(a, b) << " | " << setw(3) << unsignedmax(a, b) << " | " << endl;
	cout << "| CMOVcc ASM    | " << setw(3) << movmin(a, b) << " | " << setw(3) << movmax(a, b) << " | " << endl;
	cout << "+---------------+-----+-----+" << endl;

	cout << "+---------------+-----+-----+" << endl;
	cout << "|Dodatnie       | MIN | MAX |" << endl;
	cout << "+---------------+-----+-----+" << endl;
	cout << "| CPP           | " << setw(3) << mincpp(ua, ub) << " | " << setw(3) << maxcpp(ua, ub) << " | " << endl;
	cout << "| Signed ASM    | " << setw(3) << signedmin(ua, ub) << " | " << setw(3) << signedmax(ua, ub) << " | " << endl;
	cout << "|Unsigned CF ASM| " << setw(3) << unsignedcfmin(ua, ub) << " | " << setw(3) << unsignedcfmax(ua, ub) << " | " << endl;
	cout << "| Unsigned ASM  | " << setw(3) << unsignedmin(ua, ub) << " | " << setw(3) << unsignedmax(ua, ub) << " | " << endl;
	cout << "| CMOVcc ASM    | " << setw(3) << movmin(ua, ub) << " | " << setw(3) << movmax(ua, ub) << " | " << endl;
	cout << "+---------------+-----+-----+" << endl;

	cout << "Wartoœæ bezwglêdna [CPP]: " << abs(a) << endl;
	cout << "Wartoœæ bezwglêdna [ASM]: " << absolute(a) << endl;

	cout << "Parzystosc [CPP]: " << (a % 2 ? "nieparzysta" : "parzysta" )<< endl;
	cout << "Liczba parzysta (e) / Liczba nieparzysta (o) : "<<even_odd(a) << endl;

	//9. instrukcja warunkowa
	cout << "Liczby [CPP]: " <<( a >= b ? 20 : -10 ) << endl;
	cout << "Liczby [ASM]: " << spr1(a, b) << endl;
	//10.
	cout << "Liczby [CPP]: " << (a >= b ? a + b : a - b) << endl;
	cout << "Liczby [ASM]: " << spr2(a, b) << endl;

	cout << "Reszta [CPP]: " << (a % 5 ? "n" : "T") << endl;
	cout << "Reszta [ASM]: " << reszta1(a) << endl;

	cout << "Reszta [CPP]: " << (a % 16 ? "n" : "T") << endl;
	cout << "Reszta [ASM]: " << reszta2(a) << endl;

	cout << "Znak [CPP]: " << a << endl;
	cout << "Znak [ASM]: " << znak(a) << endl;


	return 0;
}