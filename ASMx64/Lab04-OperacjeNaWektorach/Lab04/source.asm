.code

asm04_01 PROC
	xor eax, eax
	movsxd rdx, edx
_loop:
	add eax, dword ptr [rcx+4*rdx-4]
	dec rdx
	jnz _loop
	ret
asm04_01 ENDP

asm04_02 PROC
	mov eax, 1
	movsxd rdx, edx
_loop:
	mov r8d, dword ptr [rcx+4*rdx-4]
	imul eax, r8d
	dec rdx
	jnz _loop
	ret
asm04_02 ENDP

asm04_03 PROC
	movsxd rdx, edx					;rozszerza rozmiar tablicy z edx do rdx 
	mov eax, dword ptr [rcx+4*rdx-4] ;kopiuje pierwszy wyraz do eax
_loop:
	mov r8d, dword ptr [rcx+4*rdx-4]
	cmp eax, r8d
	CMOVG eax, r8d			;czemu akurat gdy wieksze jak szukamy najmniejszej ?? xD
	dec rdx
	jnz _loop
	ret
asm04_03 ENDP

asm04_04 PROC
	movsxd rdx, edx					;rozszerza rozmiar tablicy z edx do rdx 
	mov eax, dword ptr [rcx+4*rdx-4] ;kopiuje pierwszy wyraz do eax
_loop:
	mov r8d, dword ptr [rcx+4*rdx-4]
	cmp eax, r8d
	CMOVL eax, r8d			;czemu akurat gdy wieksze jak szukamy najmniejszej ?? xD
	dec rdx
	jnz _loop
	ret
asm04_04 ENDP

asm04_05 PROC
	xor rax,rax
	movsxd rdx, edx					 ;rozszerza rozmiar tablicy z edx do rdx 
	mov r9, rdx		;zapamientuje liczbe n ilosc argumentow
_loop:
	mov r8d, dword ptr [rcx+4*rdx-4]
	movsxd r8, r8d		;zamiana zeby dodac
	add rax, r8			;dodanie
	dec rdx				;to do pentli 
	jnz _loop
	cqo				;powiekszenie zeby dzielic (rax:rdx)
	idiv r9			;dzielenie idiv (rax:rdx) / r9
	ret
asm04_05 ENDP

asm04_06 PROC	uses rbx
	xor rax, rax
	movsxd r8, r8d					 ;rozszerza rozmiar tablicy z edx do rdx 
_loop:
	mov r9d, dword ptr [rcx+4*r8-4]		;wypisanie pierwszej zmiennej z tablicy a
	mov r10d, dword ptr [rdx+4*r8-4]	;wypisanie drugiej zmiennej z tablicy b
	mov ebx, r9d	
	imul ebx, r10d
	add eax, ebx
	dec r8				;to do pentli 
	jnz _loop
	movsxd rax, eax		;to trzeba zwracac do rax ? czy wystarczy ze je wyczyscilem i moge zwrocic eax ?? 
	ret
asm04_06 ENDP

asm04_07 PROC
	xor rax, rax
	movsxd rdx, edx
_loop:
	mov r8w, word ptr [rcx+2*rdx-2]
	movsx r8, r8w
	imul r8, 5
	sub r8, 3
	add rax, r8
	dec rdx
	jnz _loop
	ret
asm04_07 ENDP

asm04_08 PROC
	xor eax, eax
	movsxd rdx, edx
_loop:
	mov r8d, dword ptr [rcx+4*rdx-4]
	sal r8d, 4
	add eax, r8d
	add eax, 6
	dec rdx
	jnz _loop
	ret
asm04_08 ENDP

asm04_11 PROC
	xor rax, rax
	movsxd rdx, edx		;przeniesienie indeksu do rdx
_loop:
	mov r8, qword ptr [rcx+8*rdx-8]		;przypisanie wartosci z tablicy
	shr r8, 1
	jnc _skip
	inc rax
_skip:
	dec rdx
	jnz _loop
	ret
asm04_11 ENDP

asm05_01 PROC
	movsxd r8, r8d
_loop:
	mov r9w, word ptr [rdx+2*r8-2]
	shl r9w, 4
	add r9w, 5
	mov word ptr [rcx+2*r8-2], r9w
	dec r8
	jnz _loop
	ret
asm05_01 ENDP

asm05_02 PROC
	movsxd r8, r8d
_loop:
	mov r9d, dword ptr [rdx+4*r8-4]
	movsxd r9, r9d
	imul r9, r9
	mov qword ptr [rcx+8*r8-8], r9
	dec r8
	jnz _loop
	ret
asm05_02 ENDP

asm05_03 PROC
	xor rax, rax
	movsxd r9, r9d
_loop:
	mov rax, qword ptr [rcx + 8 * r9 - 8]
	mov ebx, dword ptr [rdx + 4 * r9 - 4]
	movsxd rbx, ebx
	add rax, rbx
	mov ebx, dword ptr [r8 + 4 * r9 - 4]
	movsxd rbx, ebx
	add rax, rbx
	mov qword ptr [rcx + 8 * r9 - 8], rax
	dec r9
	jnz _loop
	ret

asm05_03 ENDP

asm05_05 PROC uses rbx
	movsxd r9, r9d			;index do r9 
	mov rbx, rdx
_loop:
	mov r10w, word ptr [rbx+2*r9-2]	;wyraz z wektora a
	mov r11w, word ptr [r8+2*r9-2]	;wyraz z wektora b
	mov ax, r10w	;przeniesienie do ax
	cwd		;zamiana na (ax:dx)
	idiv r11w	;dzielenie
	movsx rax, ax	;wynik z dzielenia do rax'a
	mov qword ptr [rcx+8*r9-8], rax ;przeniesienie do tablicy docelowej
	dec r9	;petla
	jnz _loop
	ret
asm05_05 ENDP

asm05_06 PROC uses rbx
	movsxd r9, r9d
	mov rbx, rdx
_loop:
	mov r10, qword ptr [rbx+8*r9-8]
	mov r11, qword ptr [r8+8*r9-8]
	mov rax, r10
	cqo
	idiv r11
	mov qword ptr [rcx+8*r9-8], rdx
	dec r9
	jnz _loop
	ret
asm05_06 ENDP

asm05_07 PROC
	movsxd rdx, edx
_loop:
	mov r8, rdx
	shr r8, 1
	jnc _skip
	mov dword ptr [rcx+4*rdx-4], 0
_skip:
	dec rdx
	jnz _loop
	ret
asm05_07 ENDP


END