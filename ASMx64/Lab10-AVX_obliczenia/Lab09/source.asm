.data
sign_mask_ss DD 7FFFFFFFh
sign_mask_sd DQ 7FFFFFFFFFFFFFFFh
PI           DQ 3.14159265358979323846
_l6          DQ 6.0
_l10         DQ 10.0
_l1          DQ 1.0
_l2          DQ 2.0
_l4          DQ 4.0
_l3          DQ 3.0
_15          DD 15.0
_5           DD 5.0
_6           DD 6.0
_2           DD 2.0
.code

; xmm0 <- double a
; xmm1 <- double b
; return double a + b -> xmm0

asm01_01sd PROC
    vaddsd xmm0, xmm0, xmm1 ; xmm0 <- a + b    
    ret
asm01_01sd ENDP


asm01_02sd PROC
    vsubsd xmm0, xmm0, xmm1 ; xmm0 <- a - b    
    ret
asm01_02sd ENDP

asm01_03sd PROC
    vmulsd xmm0, xmm0, xmm1 ; xmm0 <- a * b    
    ret
asm01_03sd ENDP

asm01_04sd PROC
    vdivsd xmm0, xmm0, xmm1 ; xmm0 <- a / b    
    ret
asm01_04sd ENDP

; xmm0 <- double a
; xmm1 <- double b
; return double 10a + 6b -> xmm0

asm01_05sd PROC
local _tmp:qword
    vmulsd xmm0, xmm0, _l10 ; xmm0 <- 10a  
    vmulsd xmm1, xmm1, _l6 ; xmm1 <- 6b    
    vaddsd xmm0, xmm0, xmm1 ; xmm0 <- 10a + 6b    
    ret
asm01_05sd ENDP

; xmm0 <- double a
; xmm1 <- double b;
; return double sqrt(a+b) -> xmm0
asm01_06sd PROC
    vaddsd xmm0, xmm0, xmm1; a+b
    vsqrtsd xmm0, xmm0, xmm0; sqrt(a+b)
    ret
asm01_06sd ENDP

;xmm0 <- double a 
asm01_07sd PROC
    vandpd xmm0, xmm0, sign_mask_sd
    ret
asm01_07sd ENDP

; xmm0 <- float a
; xmm1 <- float b
; xmm2 <- float x
asm01_08ss PROC
    vmulss xmm3, xmm2, xmm2; xmm3 <- x*x
    vmulss xmm2, xmm3, xmm2; xmm2 <- x*x*x
    vmulss xmm0, xmm0, xmm2; xmm0 <- ax^3
    vaddss xmm0, xmm0, xmm1; xmm0 <- ax^3+b
    vandps xmm0, xmm0, sign_mask_ss; xmm0 <- |ax^3+b|
    ret
asm01_08ss ENDP

; xmm0 <- float x
asm01_09ss PROC
local _tmp:dword
    vmulss xmm1, xmm0, xmm0; xmm1 <- x*x
    vmulss xmm2, xmm1, xmm0; xmm2 <- x*x*x
    vmulss xmm2, xmm2, _15; xmm2 <- 15x^3
    vmulss xmm1, xmm1, _5; xmm1 <- 5x^2
    vmulss xmm0, xmm0, _6; xmm0 <- 6x
    vaddss xmm2, xmm2, xmm1; xmm2 <- 15x^3 + 5x^2
    vsubss xmm0, xmm2, xmm0; xmm0 <- 15x^3 + 5x^2 - 6x
    vaddss xmm0, xmm0, _2; xmm0 <- wynik
    ret
asm01_09ss ENDP

; xmm0 <- double a
; xmm1 <- double b
; xmm2 <- double c
; xmm3 <- double d
asm01_11sd PROC
    vaddsd xmm0, xmm0, xmm1; xmm0 <- a+b
    vmulsd xmm0, xmm0, xmm0; xmm0 <- (a+b)^2
    vmulsd xmm2, xmm2, xmm3; xmm2 <- cd
    vaddsd xmm2, xmm2, _l1; xmm2 <- cd+1
    vsqrtsd xmm2,xmm2,xmm2; xmm2 <- sqrt(content)
    vsubsd xmm0, xmm0, xmm2; xmm0 <- wynik
    ret
asm01_11sd ENDP

; xmm0 <- double a
; xmm1 <- double b
; xmm2 <- double c
; xmm3 <- double d
; stos <- double e
; stos <- double f
asm01_12sd PROC a:qword, b:qword, c:qword, d:qword, e:qword, f:qword
    vmulsd xmm0, xmm0, xmm1; xmm0 <- ab
    vmulsd xmm1, xmm2, xmm3; xmm2 <- cd
    vaddsd xmm0, xmm0, xmm1 ; xmm0 <- ab+cd
    movsd xmm1, e
    vmulsd xmm1, xmm1, f; xmm1 <- ef
    vsqrtsd xmm1, xmm1, xmm1; xmm2 <- sqrt(ef)  
    vdivsd xmm0, xmm0, xmm1; xmm0 <- ab+cd / sqrt(ef)
    ret
asm01_12sd ENDP

; xmm0 <- double r
asm01_16sd PROC
    vmulsd xmm1, xmm0, xmm0
    vmulsd xmm0, xmm1, xmm0; xmm0 <-r^3
    vmulsd xmm0, xmm0, PI; xmm0 <- PIr^3
    vmulsd xmm0, xmm0, _l4;
    vdivsd xmm0, xmm0, _l3;
    ret
asm01_16sd ENDP

; xmm0 <- a
; xmm1 <- b
; xmm2 <- x
asm02_01sd PROC
    vfmadd132sd xmm0, xmm1, xmm2 
    ret
asm02_01sd ENDP 

; xmm0 <- double a
; xmm1 <- double b
; xmm2 <- double x
asm02_02sd PROC
    vfmsub132sd xmm0, xmm1, xmm2
    ret
asm02_02sd ENDP

; xmm0 <- double a
; xmm1 <- double b
; xmm2 <- double x
asm02_03sd PROC
    vfnmadd132sd xmm0, xmm1, xmm2
    ret
asm02_03sd ENDP

; xmm0 <- double a
; xmm1 <- double b
; xmm2 <- double x
asm02_04sd PROC
    vfnmsub132sd xmm0, xmm1, xmm2
    ret
asm02_04sd ENDP

; xmm0 <- float a
; xmm1 <- float x
asm02_05ss PROC
    vfmadd231ss xmm0, xmm1, xmm1
    ret
asm02_05ss ENDP

; xmm0 <- float a
; xmm1 <- float x
asm02_06ss PROC
    vfmsub231ss xmm0, xmm1, xmm1
    ret
asm02_06ss ENDP

; xmm0 <- double a
; xmm1 <- double b
; xmm2 <- double c
; xmm3 <- double d
; stos <- double x
; return x(x(ax+b)+c)+d
asm02_07sd PROC a:qword, b:qword, c:qword, d:qword, x:qword
    movsd xmm4, x
    vfmadd132sd xmm0, xmm1, xmm4; xmm0 <- ax+b
    vfmadd132sd xmm0, xmm2, xmm4; xmm0 <- x(ax+b)
    vfmadd132sd xmm0, xmm3, xmm4; xmm0 <- wynik
    ret
asm02_07sd ENDP

; xmm0 <- a
; xmm1 <- b
; xmm2 <- c
; xmm3 <- d
; xmm4 <- x
; return ax^3- bx^2 - cx - d -> xmm0
; x (ax^2-bx-c) - d
; x(x(ax-b)-c)-d
asm02_08sd PROC a:qword, b:qword, c:qword, d:qword, x:qword

    vfmsub132sd xmm0, xmm1 ,x ; xmm0 <- ax-b = w
    vfmsub132sd xmm0, xmm2, x ; xmm0 <- xw-c = ww
    vfmsub132sd xmm0, xmm3, x ; xmm0 <- xww-d
    ret
asm02_08sd ENDP

; xmm0 <- double a
; xmm1 <- double b
; xmm2 <- double c
; xmm3 <- double d
; stos <- double x
; return x(x(-ax+b)+c)+d
asm02_09sd PROC a:qword, b:qword, c:qword, d:qword, x:qword
    movsd xmm4, x
    vfnmadd132sd xmm0, xmm1, xmm4; xmm0 <- -ax+b
    vfmadd132sd xmm0, xmm2, xmm4; xmm0 <- x(-ax+b)+c
    vfmadd132sd xmm0, xmm3, xmm4; xmm0 <- wynik;
    ret
asm02_09sd ENDP

; xmm0 <- double a
; xmm1 <- double b
; xmm2 <- double c
; xmm3 <- double d
; stos <- double x
; return x(x(-ax+b)+c)-d
asm02_10sd PROC a:qword, b:qword, c:qword, d:qword, x:qword
    movsd xmm4, x
    vfnmadd132sd xmm0, xmm1, xmm4
    vfmadd132sd xmm0, xmm2, xmm4
    vfmsub132sd xmm0, xmm3, xmm4
    ret
asm02_10sd ENDP

; xmm0 <- double a
; xmm1 <- double b
; xmm2 <- double c
; xmm3 <- double x
; return ax^2+bc
asm02_11sd PROC
    vmulsd xmm3, xmm3, xmm3; x^2
    vmulsd xmm0, xmm0, xmm3; ax^2
    vfmadd231sd xmm0, xmm1, xmm2; xmm0 <- wynik
    ret
asm02_11sd ENDP

; xmm0 <- double a
; xmm1 <- double b
; xmm2 <- double x
; return x(a+2b+x)+b^2
asm02_12sd PROC
    vmulsd xmm3, xmm1, _l2; xmm3  <- 2b
    vaddsd xmm0, xmm0, xmm3; xmm0 <- a+2b
    vaddsd xmm0, xmm0, xmm2; xmm0 <- a+2b+x
    vmulsd xmm1, xmm1, xmm1; xmm1 <- b*b
    vfmadd132sd xmm0, xmm1, xmm2; xmm0 <- wynik
    ret
asm02_12sd ENDP
END