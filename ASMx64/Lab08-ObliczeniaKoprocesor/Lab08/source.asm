.data
_180f   DD 180.0    ; fld
_180i   DD 180      ; fild

.code

; xmm0  <- float a
; xmm1  <- float b
; xmm2  <- float c
; xmm3  <- float d
; stack <- float x
; xmm0 -> return float y = |a|^x
asm01 PROC a:dword, b:dword, c:dword, d:dword, x:dword
local y:dword ;declare local variable y in scope of this procedure
    movss a, xmm0
    fld x               ; x
    fld a               ; a, x
    fabs                ; |a|, x
    fyl2x               ; x*log_2(|a|)
    fld st              ; x*log_2(|a|), x*log_2(|a|)
    frndint             ; int(x*log_2(|a|)), x*log_2(|a|)
    fsub st(1), st      ; int(x*log_2(|a|)), frac(m)
    fxch st(1)          ; frac(m), int()
    f2xm1               ; 2^frac(m) - 1, int()
    fld1                ; 1, 2^frac(m) - 1, int()
    fadd                ; 2^frac(m), int()
    fscale              ; 2^frac(m) * 2^int(), int()
    fstp y              ; int()
    fstp st             ; <empty>
    movss xmm0, y       ; prepare xmm0 for return
    ret
asm01 ENDP

asm02 PROC a:dword, x:dword
    local y:dword
    movss a, xmm0
    movss x, xmm1;
    fld a
    fld x
    fmul    ;ax
    fld1
    fld1
    fadd;
    fld st;
    fld st;
    fadd;
    fadd    ;6, ax
    fadd    ;6+ax
    fsqrt   ;root(ax+6)
    fld1;
    fld1;
    fadd; 2, r
    fld st
    fadd; 4, r
    fld st;
    fadd; 8, r
    fmul    ;8*sqrt(ax+6) <- w1
    fld x;
    fld st;
    fmul;
    fld st;
    fmul; x^4, w1
    fld1;
    fadd; 1+x^4, w1
    fld1 ;1, 1+x^4, w1
    fxch
    fyl2x
    fldl2e
    fdiv
    fld a
    fmul
    fadd
    fstp y
    movss xmm0, y
    ret
asm02 ENDP

; xmm0 <- float a
; xmm1 <- float b
; xmm2 <- float c
; xmm3 <- float x
asm03 PROC a:dword, b:dword, c:dword, x:dword
local y:dword, _switch:dword
    movss a, xmm0
    movss b, xmm1
    movss c, xmm2
    movss x, xmm3

    fld x               ; x
    mov _switch, -5
    fild _switch         ; -5, x
    fcomip st, st(1)    ; x
    jae _case1           ; jump if (-5 > x)
    fldz                ; 0, x
    fcomip st, st(1)    ; x
    jae _case2           ; jump if (0 > x)
    mov _switch, 5      
    fild _switch         ; 5, x
    fcomip st, st(1)    ; x
    jae _case3           ; jump if (5 > x)
    
    fldpi
    fmul
    mov _switch, 16
    fild _switch
    fmul
    fsqrt
    fld x
    fld st
    fmul
    mov _switch, 32
    fild _switch
    fmul
    fsqrt
    fsub
    
    jmp _end

_case1:
    fld st ;x, x
    fmul    ;x^2
    fld a; a, x^2
    fmul ;a*x^2
    fld b
    fld x
    fmul ;bx, ax^2
    fld c
    fadd
    fadd    ;wynik
    jmp _end

_case2:
    fldpi ;pi, x
    fmul;pi*x
    fld _180f ;180.0 , pix
    fdiv ;radians1
    fld st
    fmul ; radians1^2
    fsin ; w1
    fld x
    fldpi
    fmul
    fld _180f;
    fdiv
    fld st
    fmul
    fcos
    fadd
    jmp _end

_case3:
    fld st
    fmul
    fld a
    fmul
    fld x
    fld1
    fadd
    fyl2x
_end:
    fstp y  ;<empty>
    movss xmm0, y
    ret
asm03 ENDP
; rcx <- float * x
; rdx <- float * y
; r8d <- u int n
; xmm3 <- float a
; esp <- float b
; esp <- float xMin
; esp <- float xMax

asm04 PROC x:dword, y:dword, n:dword, a:dword, b:dword, xMin:dword, xMax:dword
local _s:dword
    mov rsi, rcx
    mov rdi, rdx
    movsxd r8, r8d
    push r8
    movss a, xmm3
    fld xMax ;xMax
    fld xMin ; xMin, xMax
    fsub    ; xMax-xMin
    fild dword ptr [rsp] ; n, xMax-xMin
    pop r8
    fdiv    ; s
    fstp _s ; _s <- s <empty>
_loop:
    fld dword ptr [rsi +4 * r8 - 4]; x[i]
    fld st;
    fldpi ; pi, x[i]
    fmul
    fld _180f
    fdiv;
    fld st;
    fmul
    fsin;
    fld a;
    fmul ; asin(pix/180)^2, x[i]
    fxch ;
    fldpi;
    fmul
    fld _180f
    fdiv
    fcos
    fld b
    fmul
    fadd
    fstp dword ptr [rdi +4 * r8 - 4];
    dec r8
    jnz _loop
    ret
asm04 ENDP

END