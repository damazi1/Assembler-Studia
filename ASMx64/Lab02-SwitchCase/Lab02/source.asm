.code

asm_03_04_01 PROC
	cmp rcx, 0
	jz _case0
	cmp rcx, 1
	jz _case1
	jmp _default
_case0:
	mov rax, 10
	jmp _end
_case1:
	mov rax, 20
	jmp _end
_default:
	mov rax, 30
_end:
	ret
asm_03_04_01 ENDP


asm_03_04_02 PROC
	cmp r8, 0
	jz _case0
	cmp r8, 1
	jz _case1
	cmp r8, 2
	jz _case2
	cmp r8, 3
	jz _case3
	jmp _default
_case0:
	add rcx, rdx
	jmp _end
_case1:
	sub rcx, rdx
	jmp _end
_case2:
	imul rcx, rdx
	jmp _end
_case3:
	mov rax, rcx
	mov rbx, rdx
	cqo
	idiv rbx
	mov rcx, rax
	jmp _end
_default:
	mov rcx, 0
_end:
	mov rax, rcx
	ret
	ret
asm_03_04_02 ENDP

asm_03_04_03 PROC
	cmp r8, 10
	jz _case0
	cmp r8, 20
	jz _case1
	jmp _default
_case0:
	shl rcx, 5
	shl rdx, 4
	add rcx, rdx
	mov rax, rcx
	jmp _end
_case1:
	sub rcx, rdx
	mov rax, rcx
	mov r9, 4
	cqo
	idiv r9
	jmp _end
_default:
	mov rax, rcx
	mov r9, 8
	cqo
	idiv r9
	mov rax, rdx
_end:
	ret

asm_03_04_03 ENDP

asm_03_04_06 PROC
	cmp r9, 5
	jl _case0
	cmp r9, 10
	jl _case1
	jmp _default
_case0:
	imul rcx, -500
	mov rax, rcx
	imul rdx, 20
	mov rbx, rdx
	cqo
	idiv rbx
	jmp _end
_case1:
	imul rcx, -244
	imul rcx, r9
	imul rdx, 12
	add rcx, rdx
	mov rax, rcx
	shl r9, 4
	cqo
	idiv r9
	jmp _end
_default:
	mov rbx, rcx
	imul rcx, -128
	add rcx, rdx
	imul r8, -16
	add rcx ,r8
	add rbx, r9
	add rbx, 1
	mov rax, rbx
	sal rax, 1
	jnc _skip
	neg rbx
_skip:
	mov rax, rcx
	cqo
	idiv rbx
_end:
	ret

asm_03_04_06 ENDP

asm_03_05_01 PROC
	xor rax, rax
_loop:
	add rax, rdx
	cmp rcx, 0
	jnl _jump0
	inc rcx
	jz _jump1
	jmp _loop
_jump0:
	loop _loop
	jmp _end
_jump1:
	neg rax
_end:
	ret
asm_03_05_01 ENDP

asm_03_05_02 PROC
	xor rax, rax
	mov rdx, rcx
	mov rcx, 40
_loop:
	add rax, rdx
	loop _loop
	ret

asm_03_05_02 ENDP

asm_03_05_03 PROC
	xor rax, rax
	mov rbx, rcx
	mov rcx, 150
_loop:
	add rax, rbx
	loop _loop
	add rax, rdx
	ret
asm_03_05_03 ENDP

asm_03_05_04 PROC
	xor rax, rax
	add rdx, rcx
	mov rcx, 10
_loop:
	sub rdx, rcx
	jle _end
	inc rax
	jmp _loop
_end:
	ret
asm_03_05_04 ENDP

asm_03_05_05 PROC
	xor rax, rax
_loop:
	sub rcx, rdx
	jle _end
	inc rax
	jmp _loop
_end:
	ret
asm_03_05_05 ENDP

asm_03_05_09 PROC
	xor rax, rax
	mov rbx, 1
	mov rdx, rcx
	mov rcx, rbx
_loop:
	add rax, rbx
	loop _loop
	cmp rdx, rbx
	jle _end
	inc rbx
	mov rcx, rax
	xor rax, rax
	jmp _loop
_end:
	ret
asm_03_05_09 ENDP

asm_03_05_10 PROC
	mov rax, 1
	mov rbx, 1
_loop:
	add rax, rbx
	mov rdx, rax
	sub rdx, rbx
	mov rbx, rdx
	loop _loop
	mov rax, rbx
	ret
asm_03_05_10 ENDP

asm_03_05_11 PROC
	xor eax, eax
	popcnt rax, rcx
	ret
asm_03_05_11 ENDP

asm_03_05_12 PROC
	xor rax, rax
	mov rdx, rcx
	mov rcx, 64
_loop:
	shl rdx, 1
	jc _skip
	inc rax
_skip:
	loop _loop
	ret
asm_03_05_12 ENDP

END