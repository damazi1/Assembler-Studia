.data
sign_mask_sd DQ 7FFFFFFFFFFFFFFFh
PI           DQ 3.14159265358979323846
_l6          DQ 6.0
_l10         DQ 10.0
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

;xmm0 <- double a 
asm01_07sd PROC
    vandpd xmm0, xmm0, sign_mask_sd
    ret
asm01_07sd ENDP

; xmm0 <- a
; xmm1 <- b
; xmm2 <- x
asm02_01sd PROC
    vfmadd132sd xmm0, xmm1, xmm2 
    ret
asm02_01sd ENDP 

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
END