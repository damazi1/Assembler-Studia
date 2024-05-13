.code

; xmm0 <- double a
; xmm1 <- double b
; xmm2 <- double c
; xmm3 <- double d
; stack[0] <- double x
asm01_64 PROC a:qword, b:qword, c:qword, d:qword, x:qword
local y:qword
   movsd a, xmm0;
   movsd b, xmm1;
   movsd c, xmm2;
   movsd d, xmm3;
   fld x    ;x
   fld a    ;a , x
   fabs;
   fyl2x ; xlog_2|a| = z
   fld st ; z, z
   frndint  ;int(z), z
   fsub st(1), st ; int(z), z-int(z) = m => [-1,1]
   fxch     ; m, int(z)
   f2xm1    ; 2^m - 1, int(z)
   fld1
   fadd     ; 2^m, int(z)
   fscale   ; 2^m * 2^n, int(z)
   fstp y   ;
   fstp st

    movsd xmm0, y;
    ret
asm01_64 ENDP

asm02_64 PROC 
  
    ret
asm02_64 ENDP

asm03_64 PROC a:qword, b:qword, c:qword, x:qword
local y:qword, _tmp:qword
    movsd a, xmm0
    movsd b, xmm1
    movsd c, xmm2
    movsd x, xmm3
    
    mov _tmp, 5  ;5
    fild _tmp    ;5
    fchs        ;-5
    fld x       ;x, -5
    fxch        ;-5, x
    fcomip st, st(1) ; compare -5 to x -> ser RFlags
    jae _case1
    fldz        ;0, x
    fcomip st, st(1) ;
    ja _case2
    fild _tmp    ;5, x
    fcomip st, st(1) ;
    ja _case3
    _default:
    mov _tmp, 16
    fild _tmp ;16, x
    fmul        ;16x
    fldpi       ;pi, 16x
    fmul        ;16*x*pi
    fsqrt       ; sqrt(16*x*pi) = a
    mov _tmp, 32
    fld x       ;x, a
    fld st      ;x, x, a
    fmul        ;x^2, a
    fild _tmp ;32, x^2, a
    fmul        ;32x^2, a
    fsqrt       ;sqrt(32x^2) = b, a
    fsub        ;a-b
    jmp _end
    _case1:
    fld st  ;x, x
    fmul    ;x^2
    fld a   ;a, x^2
    fmul    ;a*x^2
    fld x
    fld b
    fmul    ;bx, a*x^2
    fadd    ;(a*x^2+bx)
    fld c
    fadd    ;(a*x^2+bx+c)
    jmp _end
    _case2:

    _case3:

    _end:

    fstp y          ;<empty>
    movsd xmm0, y   ; return fp result via xmm0
    ret
asm03_64 ENDP

asm04_64 PROC
    ret
asm04_64 ENDP

END