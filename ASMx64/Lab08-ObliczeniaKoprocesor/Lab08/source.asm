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

asm02 PROC
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
    fld _switch         ; -5, x
    fcomip st, st(1)    ; x
    ja _case1           ; jump if (-5 > x)
    fldz                ; 0, x
    fcomip st, st(1)    ; x
    ja _case2           ; jump if (0 > x)
    ; _case3
_default:
    ;...
    jmp _end

_case1:
    ;...
    jmp _end

_case2:
    ;...
    jmp _end

_end:
    fstp y
    movss xmm0, y
    ret
asm03 ENDP

asm04 PROC
    ret
asm04 ENDP

END