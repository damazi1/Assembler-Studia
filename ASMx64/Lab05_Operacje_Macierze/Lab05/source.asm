.code
	asm01_01 PROC
		xor rax, rax
		movsxd rdx, edx
		movsxd r8, r8d
	_rows_loop:
		mov r10, qword ptr[rcx + 8 * rdx - 8]
		mov r9,r8
	_cols_loop:
		mov r11d, dword ptr[r10 + 4 * r9 -4]
		add eax, r11d
		dec r9
		jnz _cols_loop
		dec rdx
		jnz _rows_loop

		movsxd rax, eax
		ret
	asm01_01 ENDP

	asm01_02 PROC
		mov rax, 1
		movsxd rdx, edx
		movsxd r8, r8d
	_rows_loop:
		mov r9, qword ptr[rcx+8*rdx-8]
		mov r10, r8
		_cols_loop:
			mov r11, qword ptr[r9+8*r10-8]
			imul rax, r11
			dec r10
			jne _cols_loop
			dec rdx
			jne _rows_loop
		ret
	asm01_02 ENDP

	asm01_04 PROC 
		mov rax, 8000000000000000H
		movsxd rdx, edx
		movsxd r8, r8d
	_rows_loop:
		mov r9, qword ptr [rcx+8*rdx-8]
		mov r10, r8
		_cols_loop:
			mov r11, qword ptr[r9+8*r10-8]
			cmp rax, r11
			cmovl rax, r11
			dec r10
			jne _cols_loop
			dec rdx
			jne _rows_loop
		ret
	asm01_04 ENDP

	asm01_06 PROC USES RSI RDI
		xor eax, eax
		movsxd r8, r8d
		mov rsi, r8			;indeks rows
		movsxd r9, r9d
		mov rdi, r9			;indeks cols
	_rows_loop:
		mov r8, qword ptr[rcx + 8 * rsi - 8] ;col A 
		mov r9, qword ptr[rdx + 8 * rsi - 8] ;col B
		mov r10, rdi
	_cols_loop:
		mov r11d, dword ptr[r8 + 4 * r10 -4]  ;row A
		imul r11d, dword ptr[r9 + 4 * r10 -4] ; row A * row B
		add eax, r11d	;Sum A*B
		dec r10
		jnz _cols_loop
		dec rsi
		jnz _rows_loop

		ret
	asm01_06 ENDP

	asm01_07 PROC
		xor r11, r11	
		movsxd rdx, edx	;przenosze indeks do rdx
		movsxd r8, r8d	;przenosze indeks do r8
		cmp rdx, r8		;sprawdzam najmniejszy indeks
		cmovle rax, rdx
		cmovg rax, r8	;przypisuje najmniejszy indeks
	_loop_rows:
		mov r9, qword ptr[rcx+8*rax-8]		;zaczynam przypisywanie ale od ostatniego elementu na przekontnej
		mov r10, r8			;wchodze do kolumn
		_loop_cols:
			cmp r10, rax	;porownuje czy indeks kolumny = indeksowi wiersza (n=m)
			jne _skip		;jezeli nie to skip
			add r11, qword ptr[r9+8*r10-8]	;jezeli tak to dodaje
			dec rax	;zmniejszam indeks
			jmp _loop_rows	;i skacze do poczatku
		_skip:
			dec r10	;tutaj juz pentle jak zwykle
			jne _loop_cols
			dec rdx
			jne _loop_rows
		mov rax, r11		;na koniec wynik do rax
		ret
	asm01_07 ENDP

	asm01_08 PROC
		mov r11, 1
		movsxd rdx, edx
		movsxd r8, r8d
		cmp rdx, r8
		cmovle rax, rdx
		cmovg rax, r8
	_rows_loop:
		mov r9, qword ptr [rcx+8*rax-8]
		mov r10, r8
		_cols_loop:
			cmp r10, rax
			jne _skip
			imul r11, qword ptr [r9+8*r10-8]
		_skip:
			dec r10
			jne _cols_loop
			dec rax
			jne _rows_loop
		mov rax, r11
		ret
	asm01_08 ENDP

	asm01_09 PROC uses rbx
		mov rax, 7FFFFFFFFFFFFFFFH
		movsxd rdx, edx
		movsxd r8, r8d
		cmp rdx, r8
		cmovle rbx, rdx
		cmovg rbx, r8
	_rows_loop:
		mov r9, qword ptr [rcx+8*rbx-8]
		mov r10,r8
		_cols_loop:
			cmp r10, rbx
			jne _skip
			cmp rax, qword ptr [r9+8*r10-8]
			cmovg rax, qword ptr [r9+8*r10-8]
		_skip:
			dec r10
			jne _cols_loop
			dec rbx
			jne _rows_loop
		ret
	asm01_09 ENDP

	asm01_14 PROC
		xor rax, rax
		movsxd rdx, edx
		movsxd r8, r8d
	_rows_loop:
		mov r9, qword ptr [rcx+8*rdx-8]
		mov r10, r8
		_cols_loop:
			mov r11, qword ptr [r9+8*r10-8]
			shl r11, 4
			add r11, 6
			add rax, r11
			dec r10
			jne _cols_loop
			dec rdx
			jne _rows_loop
		ret
	asm01_14 ENDP

	asm01_17 PROC
		xor rax, rax
		movsxd rdx, edx
		movsxd r8, r8d
	_rows_loop:
		mov r9, qword ptr [rcx+8*rdx-8]
		mov r10, r8
		_cols_loop:
			mov r11, qword ptr [r9+8*r10-8]
			shr r11,1 
			jnc _skip
			inc rax
		_skip:
			dec r10
			jne _cols_loop
			dec rdx
			jne _rows_loop
		ret
	asm01_17 ENDP

	asm01_18 PROC uses rbx r12 r13
		xor rbx, rbx
		mov r13, 4
		movsxd r12, edx
		movsxd r8, r8d
	_rows_loop:
		mov r9, qword ptr [rcx+8*r12-8]
		mov r10, r8
		_cols_loop:
			mov rax, qword ptr [r9+8*r10-8]
			cqo		
			idiv r13
			cmp rdx, 0
			jne _skip
			inc rbx
		_skip:
			dec r10
			jne _cols_loop
			dec r12 
			jne _rows_loop
		mov rax, rbx
		ret
	asm01_18 ENDP

	asm01_20 PROC
		xor rax, rax
		movsxd rdx, edx
		movsxd r8, r8d
	_rows_loop:
		mov r9, qword ptr [rcx+8*rdx-8]
		mov r10, r8
		_cols_loop:
			mov r11, qword ptr [r9+8*r10-8]
			cmp r11, -10
			jle _skip
			cmp r11, 10
			jge _skip
			inc rax
		_skip:
			dec r10
			jne _cols_loop
			dec rdx
			jne _rows_loop
		ret
	asm01_20 ENDP

	asm01_22 PROC
		xor rax, rax
		movsxd rdx, edx
		movsxd r8, r8d
		cmp rdx, r9
		cmovg rdx, r9
	_rows_loop:
		mov r9, qword ptr [rcx+8*rdx-8]
		mov r10, r8
		_cols_loop:
			cmp r10,rdx
			jne _skip
			mov r11, qword ptr [r9+8*r10-8]
			shr r11, 1
			jnc _skip
			inc rax
			_skip:
			dec r10
			jne _cols_loop
			dec rdx
			jne _rows_loop
		ret
	asm01_22 ENDP

	asm02_02 PROC
		movsxd rdx, edx
		movsxd r8, r8d
	_rows_loop:
		mov r9, qword ptr [rcx+8*rdx-8]
		mov r10, r8
		_cols_loop:
			mov r11, qword ptr [r9+8*r10-8]
			imul r11, r11
			mov qword ptr [r9+8*r10-8],r11
			dec r10
			jne _cols_loop
			dec rdx
			jne _rows_loop
		ret
	asm02_02 ENDP

	asm02_04 PROC uses rsi rdi r12 rbx r13 r14
		mov r13d, 3
		mov rbx, rdx
		movsxd rsi, r8d
		movsxd rdi, r9d
	_rows_loop:
		mov r8, qword ptr [rcx+8*rsi-8]
		mov r9, qword ptr [rbx+8*rsi-8]
		mov r10, rdi
		_cols_loop:
			mov r11d, dword ptr [r8+4*r10-4]
			mov r12d, dword ptr [r9+4*r10-4]
			imul r11d, 5
			shl r12d, 2
			add r11d, r12d
			mov eax, r11d
			cdq
			idiv r13d
			mov dword ptr [r8+4*r10-4], eax
			dec r10
			jne _cols_loop
			dec rsi
			jne _rows_loop

		ret
	asm02_04 ENDP

	asm02_08 PROC 
		movsxd rdx, edx
		movsxd r8, r8d
	_rows_loop:
		mov r9, qword ptr[rcx +8 * rdx -8]
		mov r10 ,r8
		bt rdx, 0		;copy rdx[0] (LSB(rdx)) to CF Sprawdza najstarszy bit i je¿eli jest nieparzysta to skacze
		jnc _skip_row
	_cols_loop:
		bt r10, 0		;copy r10[0] (LSB(r10)) to CF	
		jnc _skip_col
		mov word ptr [r9 + 2 * r10 - 2], 0

	_skip_col:
		dec r10
		jnz _cols_loop
	_skip_row:
		dec rdx
		jnz _rows_loop

		ret
	asm02_08 ENDP

	asm02_09 PROC uses r12
		movsxd rdx, edx
		movsxd r8, r8d
	_rows_loop:
		mov r11, rdx
		shr r11, 1
		jc _skip1
		mov r9, qword ptr [rcx+8*rdx-8]
		mov	r10, r8
		_cols_loop:
			mov r11, r10
			shr r11, 1
			jc _skip2
			mov word ptr [r9+2*r10-2], 0
		_skip2:
			dec r10
			jne _cols_loop
		_skip1:
			dec rdx
			jne _rows_loop
		ret
	asm02_09 ENDP

	asm02_11 PROC
		movsxd rdx, edx
		movsxd r8, r8d
	_rows:
		mov r9, r8
		mov r10, qword ptr [rcx+8*rdx-8]
		_cols:
			cmp rdx, r9
			jle _skip
			mov qword ptr [r10+8*r9-8], 0
		_skip:
			dec r9
			jnz _cols
		dec rdx
		jnz _rows
		ret
	asm02_11 ENDP

	asm02_18 PROC uses r12 r13
		movsxd r8, r8d
		movsxd r9, r9d
	_rows_loop:
		mov r10, qword ptr [rcx+8*r8-8]
		mov r11, qword ptr [rdx+8*r8-8]
		mov r12, r9
		_cols_loop:
			mov r13d, dword ptr [r10+4*r12-4]
			cmp r12, r8
			jg _skip
			mov dword ptr [r11+4*r12-4], r13d
			_skip:
			dec r12
			jne _cols_loop
			dec r8
			jne _rows_loop
		ret
	asm02_18 ENDP

END
