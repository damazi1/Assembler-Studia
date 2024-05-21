.data
_180f   dd 180.0
_20f    dd 20.0
_min    dd 80000000h
.code

; ecx <- size n
; rdx <- double * a
asm09_01_01_02 PROC
local y:qword
    movsxd rcx, ecx
    fldz; sum
    _loop:
    fld qword ptr [rdx + 8 * rcx - 8]; a[i], sum
    fadd;//sum+=a[i]
    dec rcx
    jnz _loop
    fstp y; <empty>
    movsd xmm0, y
    ret
asm09_01_01_02 ENDP

; ecx <- size n
; rdx <- float * a
asm09_01_04_01 PROC
local y:dword
    movsxd rcx, ecx
    fld _min
    _loop:
    fld dword ptr [rdx + 4 * rcx -4];a[i], min
    fcomi st, st(1); set flags with st and st(1)
    jbe _end
    fxch
    _end:
    fstp st(0)
    dec rcx
    jnz _loop
    fstp y
    movss xmm0, y
    ret
asm09_01_04_01 ENDP

; ecx <- size n
; rdx <- float * a
asm09_01_05_03 PROC
local y:qword
    movsxd rcx, ecx
    mov r8, rcx
    fldz ;sum
    _loop:
    fld dword ptr [rdx +4 * rcx -4];a[i], sum
    fadd;sum+=a[i]
    dec rcx
    jnz _loop
    push r8
    fild qword ptr[rsp];n, sum
    pop r8
    fdiv
    fstp y
    movsd xmm0, y
    ret
asm09_01_05_03 ENDP

; ecx <- n size
; rdx <- double * a
; r8 <- double * b
; r9 <- double * y
asm09_02_03_02 PROC
    movsxd rcx, ecx ; size to 64b
    _loop:
    fld qword ptr [rdx + 8 * rcx - 8]; a[i]
    fld st
    fmul; a[i]^2
    fld st
    fmul; a[i]^4
    fld qword ptr [r8 + 8 * rcx - 8];b[i], a[i]^4
    fld st
    fld st
    fmul
    fmul; b[i]^3, a[i]^4
    fadd; (a[i]^4+b[i]^3)
    fldln2; ln(2), (a[i]^4+b[i]^3)
    fdiv
    fstp qword ptr [r9 + 8 * rcx - 8]; <empty>

    dec rcx
    jnz _loop
    ret
asm09_02_03_02 ENDP

; ecx <- size n
; rdx <- float * a
; r8 <- float * b
; r9 <- float * y
asm09_02_04_01 PROC
    movsxd rcx, ecx
    _loop:
    fld dword ptr [rdx + 4 * rcx -4]; a[i]
    fld1
    fld1
    fadd; 2, a[i]
    fld st
    fld1
    fadd
    fadd; 5, a[i]
    fmul; 5a[i]
    fld dword ptr [r8 + 4 * rcx - 4];b[i], 5a[i]
    fld1
    fld1;
    fadd
    fld st
    fadd
    fmul; 4b[i], 5a[i]
    fadd;
    fabs; abs(5a[i]+4b[i])
    fld1;
    fld1;
    fadd;
    fld1;
    fadd; 3, w1
    fdiv; w1/3
    fsqrt
    fstp dword ptr [r9 + 4 * rcx - 4]
    dec rcx
    jnz _loop
    ret
asm09_02_04_01 ENDP

; ecx <- size n
; rdx <- float * a
; r8 <- float * b
; r9 <- float * y
asm09_02_05_01 PROC
    movsxd rcx, ecx
    _loop:
    fld dword ptr [rdx + 4 * rcx - 4]; a[i]
    fldpi   ;pi, a[i]
    fmul    ;pi*a[i]
    fdiv _180f; pi*a[i]/180
    fsin; sin(a[i])
    fld _20f
    fmul; 20sin(a[i])
    fld dword ptr [r8 + 4 * rcx - 4]; b[i], 20sin(a[i])
    fldpi; pi, b[i], 20sin(a[i])
    fmul
    fdiv _180f
    fld st
    fsin; sin(b[i]), b[i], 20sin(a[i]) 
    fxch
    fcos; cos(b[i]), sin(b[i]), 20sin(a[i])
    fdiv; tg(b[i]), 20sin(a[i])
    fld st
    fmul
    fadd;
    fstp dword ptr [r9 + 4 * rcx - 4]
    dec rcx
    jnz _loop
    ret
asm09_02_05_01 ENDP

END