#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>

using namespace std;

typedef unsigned int uint;

template <typename T>
T rnd(const T min, const T max) {
	return rand() % (max - min) + min;
}

int main() {
	srand((unsigned)time(0));
	int a = rnd(-100, 10), b = rnd(-100, 10), c = rnd(-10, 10), d = rnd(-10, 10), y = 0;
	uint ua = rnd(10, 100), ub = rnd(1, 10), uc = rnd(1, 10), ud = rnd(1, 10), uy = 0;
	cout << "==================================================" << endl;
	cout << "Wartości zmiennych a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
	cout << "\nPolecenia ADD oraz SUB\n";
	cout << "==================================================" << endl;
	//DODAWANIE I ODEJMOWANIE W ASM
	// a) PLATFORMA x86
	//1. y = a + b + 2c
	__asm {
		mov eax, a
		mov ebx, b
		add eax, ebx
		add eax, c
		add eax, c
		mov y, eax

	}
	cout << "1. [CPP]: " << a + b + 2 * c << endl;
	cout << "1. [ASM]: " << y << endl;

	// 2. y = a − (b + c)

	__asm {
		mov eax, a
		mov ebx, b
		add ebx, c
		sub eax, ebx
		mov y, eax

	}
	cout << "2. [CPP]: " << a - (b + c) << endl;
	cout << "2. [ASM]: " << y << endl;

	//3. y = (a + b) − (c + d)

	__asm {
		mov eax, a
		mov ebx, c
		add eax, b
		add ebx, d
		sub eax, ebx
		mov y, eax

	}
	cout << "3. [CPP]: " << (a + b) - (c + d) << endl;
	cout << "3. [ASM]: " << y << endl;

	//4. y = 4a + 2b − c

	__asm {
		mov eax, a
		mov ebx, b
		add eax, eax
		add eax, eax
		add ebx, ebx
		add eax, ebx
		sub eax, c
		mov y, eax
	}
	cout << "4. [CPP]: " << 4 * a + 2 * b - c << endl;
	cout << "4. [ASM]: " << y << endl;

	//5. y = 50 + a

	__asm {
		mov eax, 50
		add eax, a
		mov y, eax
	}
	cout << "5. [CPP]: " << 50 + a << endl;
	cout << "5. [ASM]: " << y << endl;

	//6. y = −40 + a

	__asm {
		mov eax, -40
		add eax,a
		mov y,eax
	}
	cout << "6. [CPP]: " << -40 + a << endl;
	cout << "6. [ASM]: "<< y << endl;
	
	//7. y = (120 + a) − (−90 + b)

	__asm {
		mov eax, 120
		mov ebx, -90
		add eax, a
		add ebx, b
		sub eax,ebx
		mov y,eax
	}
	cout << "7. [CPP]: " << (120 + a) - (-90 + b) << endl;
	cout << "7. [ASM]: " << y << endl;

	//8. y = 5 + 4a − 3b

	__asm {
		mov eax , 5
		mov ebx , a
		mov ecx , b
		add ebx,ebx
		add ebx,ebx
		add ecx,b
		add ecx,b
		add eax,ebx
		sub eax,ecx
		mov y, eax
	}
	cout << "8. [CPP]: " << 5 + 4 * a - 3 * b << endl;
	cout << "8. [ASM]: " << y << endl;

	//9. y = −7 + a − 3b

	__asm {
		mov eax,-7
		mov ebx, b
		add eax,a
		add ebx,b
		add ebx,b
		sub eax,ebx
		mov y, eax
	}
	cout << "9. [CPP]: " << -7 + a - 3 * b << endl;
	cout << "9. [ASM]: " << y << endl;

	//10. y = 65536 + 2a

	__asm {
		mov eax,65536
		mov ebx,a
		add ebx,ebx
		add eax,ebx
		mov y, eax
	}
	cout << "10. [CPP]: " << 65536 + 2*a << endl;
	cout << "10. [ASM]: " << y << endl;

	cout << "==================================================" << endl;
	//Potęgi liczby 2 w assemblerze SHL, SHR bez znaku
	cout << "Wartości liczb: a = " << ua << " , b = " << ub << endl;
	cout << " \nPolecenia SHL i SHR" << endl;
	cout << "==================================================" << endl;
	//1. y = 32a + 16b
	__asm {
		mov eax, ua
		mov ebx ,ub
		shl eax, 5
		shl ebx, 4
		add eax,ebx
		mov uy, eax
	}
	cout << "1. [CPP]: " << 32 * ua + 16 * ub << endl;
	cout << "1. [ASM]: " << uy << endl;

	//2. y = a/4 + b/8
	__asm {
		mov eax, ua
		shr eax, 2
		mov ebx, ub
		shr ebx, 3
		add eax, ebx
		mov uy, eax
	}
	cout << "2. [CPP]: " << ua / 4 + ub / 8 << endl;
	cout << "2. [ASM]: " << uy << endl;

	//3. (128a+64b)/32
	__asm {
		mov eax, ua
		mov ebx, ub
		shl eax, 7
		shl ebx, 6
		add eax, ebx
		shr eax, 5
		mov uy, eax
	}

	cout << "3. [CPP]: " << (128*ua + 64*ub) / 32 << endl;
	cout << "3. [ASM]: " << uy << endl;

	//4. 1024a/512
	__asm {
		mov eax, ua
		shl eax, 10
		shr eax, 9
		mov uy, eax
	}
	cout << "5. [CPP]: " << 1024 * ua / 512 << endl;
	cout << "5. [ASM]: " << uy << endl;

	//5.2^16*a+2^8*b
	__asm {
		mov eax, ua
		mov ebx, ub
		shl eax, 16
		shl ebx, 8
		add eax, ebx
		mov uy, eax
	}
	cout << fixed << setprecision(0) << "5. [CPP]: " << pow(2, 16) * ua + pow(2, 8) * ub << endl;
	cout << "5. [ASM]: " << uy << endl;

	//6. 4^4*a+8^2*b  !!Czy to jest dobrze wykonane ?? 
	__asm {
		mov eax, ua
		mov ebx, ub
		shl eax, 8
		shl ebx, 6
		add eax, ebx
		mov uy, eax
	}
	cout << "6. [CPP]: " << pow(4, 4) * ua + pow(8, 2) * ub << endl;
	cout << "6. [ASM]: " << uy << endl;

	//7. 16^4*a/8^4
	__asm {
		mov eax, ua
		shl eax, 16
		shr eax, 12
		mov uy, eax
	}
	cout << "7, [CPP]: " << pow(16, 4) * ua / pow(8, 4) << endl;
	cout << "7. [ASM]: " << uy << endl;
	//8. 8^8*a/16^2
	__asm {
		mov eax, ua
		shl eax, 24
		shr eax, 8
		mov uy, eax
	}
	cout << "8. [CPP]: " << pow(8, 8) * ua / pow(16, 2) << endl;
	cout << "8. [ASM]: " << uy << endl;

	//9. (2^5*a)/2^2 + (4^8*b)/2^7
	__asm {
		mov eax, ua
		mov ebx, ub
		shl eax, 5
		shr eax, 2
		shl ebx, 16
		shr ebx, 7
		add eax,ebx
		mov uy, eax
	}
	cout << "9. [CPP]: " << pow(2, 5) * ua / pow(2, 2) + pow(4, 8) * ub / pow(2, 7) << endl;
	cout << "9. [ASM]: " << uy << endl;

	//10. (16^2*a+8^4*b)/4^8  !!Inne wyniki ??
	__asm {
		mov eax, ua
		mov ebx, ub
		shl eax, 8
		shl ebx, 12
		add eax, ebx
		shr eax, 16
		mov uy, eax
	}
	cout << "10. [CPP]: " << (pow(16, 2) * ua + pow(8, 4) * ub) / pow(4, 8)  << endl;
	cout << "10. [ASM]: " << uy << endl;

	cout << "==================================================" << endl;
	//Potęgi liczby 2 w assemblerze SAL, SAR ze znakiem
	cout << "Wartości liczb: a = " << a << " , b = " << b << endl;
	cout << " \nPolecenia SAL i SAR" << endl;
	cout << "==================================================" << endl;
	//1. y = 16a - 32b
	__asm {
		mov eax, a
		mov ebx, b
		sal eax, 4
		sal ebx, 5
		sub eax, ebx
		mov y, eax
	}
	cout << "1. [CPP]: " << 16 * a - 32 * b << endl;
	cout << "1. [ASM]: " << y << endl;

	//2. y = a/4 + b/8 !!Inne wyniki
	__asm {
		mov eax, a
		sar eax, 2
		mov ebx, b
		sar ebx, 3
		add eax, ebx
		mov y, eax
	}
	cout << "2. [CPP]: " << a / 4 + b / 8 << endl;
	cout << "2. [ASM]: " << y << endl;

	//3. (128a+64b)/32
	__asm {
		mov eax, a
		mov ebx, b
		sal eax, 7
		sal ebx, 6
		add eax, ebx
		sar eax, 5
		mov y, eax
	}

	cout << "3. [CPP]: " << (128 * a + 64 * b) / 32 << endl;
	cout << "3. [ASM]: " << y << endl;

	//4. 1024a/512
	__asm {
		mov eax, a
		sal eax, 10
		sar eax, 9
		mov y, eax
	}
	cout << "5. [CPP]: " << 1024 * a / 512 << endl;
	cout << "5. [ASM]: " << y << endl;

	//5.2^16*a-2^8*b
	__asm {
		mov eax, a
		mov ebx, b
		sal eax, 16
		sal ebx, 8
		sub eax, ebx
		mov y, eax
	}
	cout << fixed << setprecision(0) << "5. [CPP]: " << pow(2, 16) * a - pow(2, 8) * b << endl;
	cout << "5. [ASM]: " << y << endl;

	//6. 4^4*a+8^2*b  !!Czy to jest dobrze wykonane ?? 
	__asm {
		mov eax, a
		mov ebx, b
		sal eax, 8
		sal ebx, 6
		add eax, ebx
		mov y, eax
	}
	cout << "6. [CPP]: " << pow(4, 4) * a + pow(8, 2) * b << endl;
	cout << "6. [ASM]: " << y << endl;

	//7. 16^4*a/8^4
	__asm {
		mov eax, a
		sal eax, 16
		sar eax, 12
		mov y, eax
	}
	cout << "7, [CPP]: " << pow(16, 4) * a / pow(8, 4) << endl;
	cout << "7. [ASM]: " << y << endl;
	//8. 8^8*a/16^2
	__asm {
		mov eax, a
		sal eax, 24
		sar eax, 8
		mov y, eax
	}
	cout << "8. [CPP]: " << pow(8, 8) * a / pow(16, 2) << endl;
	cout << "8. [ASM]: " << y << endl;

	//9. (2^5*a)/2^2 + (4^8*b)/2^7
	__asm {
		mov eax, a
		mov ebx, b
		sal eax, 5
		sar eax, 2
		sal ebx, 16
		sar ebx, 7
		add eax, ebx
		mov y, eax
	}
	cout << "9. [CPP]: " << pow(2, 5) * a / pow(2, 2) + pow(4, 8) * b / pow(2, 7) << endl;
	cout << "9. [ASM]: " << y << endl;

	//10. (16^2*a-8^4*b)/4^8  !!Inne wyniki ?? /imm8 ? ?
	__asm {
		mov eax, a
		mov ebx, b
		shl eax, 8
		shl ebx, 12
		sub eax, ebx
		shr eax, 16
		mov y, eax
	}
	cout << "10. [CPP]: " << (pow(16, 2) * a + pow(8, 4) * b) / pow(4, 8) << endl;
	cout << "10. [ASM]: " << y << endl;

	cout << "==================================================" << endl;
	//Dzielenie i mnożenie bez znaku MUL i DIV
	uint ux = rnd(2, 5);
	cout << "Wartości liczb: a = " << ua << " , b = " << ub<<" , c = "<<uc<<" , d = "<<ud << " , x = "<< ux << endl;
	cout << " \nPolecenia MUL i DIV" << endl;
	cout << "==================================================" << endl;
	
	//1. y=15ax + b
	__asm {
		mov eax, ua
		cdq
		mov ebx, 15
		mul ebx
		mul ux
		add eax, ub
		mov uy, eax
	}

	cout << "1. [CPP]: "<<15 * ua * ux + ub << endl;
	cout << "1. [ASM]: " << uy << endl;

	//2. 21a - 10b
	__asm {
		mov eax, ua
		cdq
		mov ebx, 21
		mul ebx
		mov ecx, eax
		mov ebx, 10
		mov eax, ub
		cdq
		mul ebx
		sub ecx, eax
		mov uy, ecx
	}
	cout << "2. [CPP]: " << 21 * ua - 10 * ub << endl;
	cout << "2. [ASM]: " << uy << endl;
	//3. 9a/(bx+1)
	__asm {
		mov eax,ua
		cdq
		mov ebx,9
		mul ebx
		mov ebx, eax
		mov eax,ub
		cdq
		mul ux
		add eax, 1
		mov ecx,eax
		mov eax,ebx
		cdq
		div ecx
		mov uy, eax
	}
	cout << "3. [CPP]: " << 9 * ua / (ub * ux + 1) << endl;
	cout << "3. [ASM]: " << uy << endl;

	// 4.(13a+b)/(10c-d)
	__asm {
		mov eax, ua
		cdq
		mov ebx, 13
		mul ebx
		mov ecx, eax
		mov ebx, 10
		mov eax, uc
		cdq
		mul ebx
		add ecx, ub
		sub eax, ud
		mov ebx, eax
		mov eax, ecx
		cdq
		div ebx
		mov uy, eax
	}
	cout << "4. [CPP]: " << (13 * ua + ub) / (10 * uc - ud) << endl;
	cout << "4. [ASM]: " << uy << endl;

	//5. a%b
	__asm {
		mov eax, ua
		cdq
		div ub
		mov uy, edx
	}
	cout << "5. [CPP]: " << ua % ub << endl;
	cout << "5. [ASM]: " << uy << endl;

	//6. 9a-b%c
	__asm {
		mov eax, ua
		cdq
		mov ebx, 9
		mul ebx
		mov ebx,eax
		mov eax, ub
		cdq
		div uc
		sub ebx, edx
		mov uy, ebx
	}
	cout << "6  [CPP]: " << 9*ua - (ub%uc) << endl;
	cout << "6. [ASM]: " << uy << endl;

	//7. (3a + b)%(c - d)
	__asm {
		mov eax, ua
		cdq
		mov ebx, 3
		mul ebx
		add eax, ub
		mov ebx, uc
		sub ebx,ud
		cdq
		div ebx
		mov uy, edx
	}
	cout << "7. [CPP]: " << (3 * ua + ub) % (uc - ud) << endl;
	cout << "7. [ASM]: " << uy << endl;

	//8. a+15b%4-c
	__asm {
		mov eax, ub
		mov ebx, 15
		cdq
		mul ebx
		mov ebx, 4
		div ebx
		add edx, ua
		sub edx, uc
		mov uy, edx
	}
	cout << "8. [CPP]: " << ua + 15 * ub % 4 - uc << endl;
	cout << "8. [ASM]: " << uy << endl;

	//9. (128a-64b)/(32c+16d) !! moge skorzystać z tego rejestru !?
	__asm {
		mov eax, ua
		cdq
		mov ebx, 128
		mul ebx
		mov ecx, eax
		mov eax, ub
		cdq
		mov ebx, 64
		mul ebx
		sub ecx,eax
		mov eax, uc
		mov ebx, 32
		cdq
		mul ebx
		mov esi, eax
		mov eax, ud
		mov ebx, 16
		cdq
		mul ebx
		add esi, eax
		mov eax,ecx
		div esi
		mov uy, eax
	}
	cout << "9. [CPP]: " << (128 * ua - 64 * ub) / (32 * uc + 16 * ud) << endl;
	cout << "9. [ASM]: " << uy << endl;

	//(256a + 10b)/(64c-20d)
	__asm {
		mov eax, ua
		mov ebx, 256
		cdq
		mul ebx
		mov ecx, eax
		mov ebx, 10
		mov eax, ub
		cdq
		mul ebx
		add ecx, eax
		mov ebx, 64
		mov eax, uc
		cdq
		mul ebx
		mov edi, eax
		mov ebx, 20
		mov eax, ud
		cdq
		mul ebx
		sub edi, eax
		mov eax, ecx
		cdq
		div edi
		mov uy, eax
	}

	cout << "10. [CPP]: " << (256 * ua + 10 * ub) / (64 * uc - 20 * ud) << endl;
	cout << "10. [ASM]: " << uy << endl;
	

	cout << "==================================================" << endl;
	//Dzielenie i mnożenie ze znakiem IMUL i IDIV
	int x = rnd(-100, 5);
	cout << "Wartości liczb: a = " << a << " , b = " << b << " , c = " << c << " , d = " << d << " , x = " << x << endl;
	cout << " \nPolecenia IMUL i IDIV" << endl;
	cout << "==================================================" << endl;
	//1. 15ax + b
	__asm {
		mov eax,a
		imul eax,15
		imul eax,x
		add eax, b
		mov y,eax
	}
	cout << "1. [CPP]: " << 15 * a * x + b << endl;
	cout << "1. [ASM]: " << y << endl;

	//2. 21a-10b
	__asm {
		mov eax,a
		imul eax,21
		mov ebx,b
		imul ebx,10
		sub eax,ebx
		mov y,eax
	}
	cout << "2. [CPP]: " << 21 * a - 10 * b << endl;
	cout << "2. [ASM]: " << y << endl;

	//3. 9a/(bx+1)
	__asm {
		mov eax, a
		imul eax, 9
		mov ebx, b
		imul ebx, x
		add ebx, 1
		cdq
		idiv ebx
		mov y, eax
	}
	cout << "3. [CPP]: " << 9 * a / (b * x + 1) << endl;
	cout << "3. [ASM]: " << y << endl;

	//4. (13a+b)/(10c-d)
	__asm {
		mov eax, a
		imul eax, 13
		add eax, b
		mov ebx, c
		imul ebx, 10
		sub ebx,d
		cdq
		idiv ebx
		mov y, eax
	}
	cout << "4. [CPP]: " << (13 * a + b) / (10 * c - d) << endl;
	cout << "4. [ASM]: " << y << endl;

	//5. a%b
	__asm {
		mov eax, a
		cdq
		idiv b
		mov y, edx
	}
	cout << "5. [CPP]: " << a%b << endl;
	cout << "5. [ASM]: " << y << endl;

	//6. 9a-b%c
	__asm {
		mov ebx, a
		imul ebx, 9
		mov eax, b
		cdq
		idiv c
		sub ebx, edx
		mov y, ebx
	}
	cout << "6. [CPP]: " << 9*a-b%c << endl;
	cout << "6. [ASM]: " << y << endl;

	//7. (3a + b) % (c - d)
	__asm {
		mov eax, a
		imul eax, 3
		add eax, b
		mov ebx, c
		sub ebx, d
		cdq
		idiv ebx
		mov y, edx
	}
	cout << "7. [CPP]: " << (3*a + b) % (c - d)<< endl;
	cout << "7. [ASM]: " << y << endl;

	//8. a + 15b%4 -c
	__asm {
		mov eax , b
		imul eax, 15
		cdq
		mov ebx, 4
		idiv ebx
		add edx, a
		sub edx, c
		mov y, edx
	}
	cout << "8. [CPP]: " << a + 15 * b % 4 - c << endl;
	cout << "8. [ASM]: " << y << endl;

	//9. (128a-64b)/(32c+16d)
	__asm {
		mov eax, a
		imul eax, 128
		mov ebx, b
		imul ebx, 64
		sub eax, ebx
		mov ebx, c
		imul ebx, 32
		mov ecx, d
		imul ecx, 16
		add ebx,ecx
		cdq
		idiv ebx
		mov y, eax
	}
	cout << "9. [CPP]: " << (128 * a - 64 * b) / (32 * c + 16 * d) << endl;
	cout << "9. [ASM]: " << y << endl;

	//10. (256a + 10b) / (64c - 20d)
	__asm {
		mov eax, a
		imul eax, 256
		mov ebx, b
		imul ebx, 10
		add eax, ebx
		mov ebx, c
		imul ebx, 64
		mov ecx, d
		imul ecx, 20
		sub ebx,ecx
		cdq
		idiv ebx
		mov y, eax
	}
	cout << "10. [CPP]: " << (256 * a + 10 * b) / (64 * c - 20 * d) << endl;
	cout << "10. [ASM]: " << y << endl;

	system("pause");
	return 0;
}