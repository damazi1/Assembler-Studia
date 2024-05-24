.data
sign_mask_sd DQ 7FFFFFFFFFFFFFFFh
sign_mask_ss DD 7FFFFFFFh
_1d         DQ 1.0
_10f        DD 10.0
_6f         DD 6.0


.code
;RCX <- double * a
;RDX <- double * b
;R8 <- double * y
;R9d <- uint n
asm01_01pd PROC
    movsxd r9, r9d  ; r9 <- n to 64b
    shl r9, 3       ; convert number of elements to number of bytes (n*sizeof(double))
    _loop:
    sub r9, 32 ; r9 <- displacment for next 4 doubles (32 bytes)
    vmovupd ymm0, ymmword ptr [rcx + r9]    ; ymm[3:0] <- a[i:i+3]
    vaddpd ymm0, ymm0, ymmword ptr [rdx+r9] ; ymm[3:0] <- a[i:i+3] + b[i:i+3]
    vmovupd ymmword ptr [r8 + r9], ymm0     ; y[i:i+3] <- a[i:i+3] + b[i:i+3]
    jnz _loop                               ; while (i != 0). note RFlags was set by sub r9, 32
    ret
asm01_01pd ENDP

; rcx <- float *a
; rdx <- float *b
; r8 <- float *y
; r9d <- uint n size
asm01_02ps PROC
    movsxd r9, r9d  ;r9 <- n to 64b
    shl r9, 2 ; convert number of elements to number of bytes (n*sizeof(float))
    _loop:
    sub r9, 32; r9 <- displacment for next 8 floats (32 bytes)
    vmovups ymm0, ymmword ptr [rcx + r9] ; ymm[3:0] <- a[i:i+7]
    vsubps ymm0, ymm0, ymmword ptr [rdx + r9] ; ymm[3:0] <- a[i:i+7] - b[i:i+7]
    vmovups ymmword ptr [r8+r9], ymm0 ; ymm[i:i+7] <- a[i:i+7] - b[i:i+7]
    jnz _loop
    ret
asm01_02ps ENDP

; RCX <- double *a
; RDX <- double *b
; R8 <- double *y
; R9D <- uint n size
asm01_03pd PROC
    movsxd r9, r9d ; n to 64b
    shl r9, 3; r9*sizeof(double)
    _loop:
    sub r9, 16 ; displacment for next 2 doubles (16 bytes)
    vmovupd xmm0, xmmword ptr [rcx + r9] ; xmm0[1:0] <- a[i:i+1]
    vmulpd xmm0,xmm0, xmmword ptr [rdx + r9] ; xmm0[1:0] <- a[i:i+1] * b[i:i+1]
    vmovupd xmmword ptr [r8 + r9], xmm0 ; xmm[i:i+1] <- a[i:i+1] * b[i:i+1]
    jnz _loop;
    ret
asm01_03pd ENDP

; rcx <- double *a
; rdx <- double *b
; r8 <- double *y
; r9d <- uint n
asm01_04pd PROC
    movsxd r9, r9d; to 64b
    shl r9, 3 ; convert to number of bytes
    _loop:
    sub r9, 32 ; displacment for next 4 doubles (32 bytes)
    vmovupd ymm0, ymmword ptr [rcx + r9];
    vdivpd ymm0, ymm0, ymmword ptr [rdx + r9]
    vmovupd ymmword ptr[r8 + r9], ymm0
    jnz _loop
    ret
asm01_04pd ENDP

; rcx <- float *a
; rdx <- float *b
; r8 <- float * y
; r9d <- uint n

asm01_05ps PROC
    movsxd r9, r9d
    shl r9, 2; convert to number of bytes
    _loop:
    sub r9, 32; displacement for 8 floats 
    vmovups ymm0, ymmword ptr [rcx+r9]
    vbroadcastss ymm1, _10f;
    vmulps ymm0, ymm0, ymm1; 10a
    vmovups ymm1, ymmword ptr [rdx + r9]
    vbroadcastss ymm2, _6f
    vmulps ymm1, ymm1, ymm2;
    vaddps ymm0, ymm0, ymm1; 10a+6b
    vmovups ymmword ptr [r8+r9], ymm0
    jnz _loop
    ret
asm01_05ps ENDP

; rcx <- double *a
; rdx <- double *b
; r8 <- double * y
; r9d <- uint n

asm01_06pd PROC
    movsxd r9, r9d
    shl r9, 3
    _loop:
    sub r9, 32;
    vmovupd ymm0, ymmword ptr[rcx+r9]
    vaddpd ymm0, ymm0, ymmword ptr[rdx+r9]
    vsqrtpd ymm0, ymm0;
    vmovupd ymmword ptr [r8+r9], ymm0
    jnz _loop
    ret
asm01_06pd ENDP


;RCX <- double * y
;EDX <- uint n
asm01_07pd PROC
    movsxd RDX, edx ;RDX <- n to 64b
    shl rdx, 3   ; convert number of elements to number of bytes (n*sizeof(double))
    vbroadcastsd ymm1, sign_mask_sd ; ymm1 <- Set mask 7FF..h
    _loop:
    sub rdx, 32 ; r9 <- displacment for next 4 doubles (32 bytes)
    vmovupd ymm0, ymmword ptr [rcx +rdx]    ;ymm0 <- a[i:i+3]
    vandpd ymm0, ymm0, ymm1                 ;ymm0 <- abs(a[i:i+3])
    vmovupd ymmword ptr [rcx+rdx], ymm0     ;a[i:i+3] <- ymm0
    jnz _loop
    ret
asm01_07pd ENDP

; xmm0 <- double a
; xmm1 <- double b
; r8 <- double *x
; r9 <- double *y
; stos <- uint n
asm01_08pd PROC a:qword, b:qword, x:qword, y:qword, n:dword
    movsxd rcx, n
    vbroadcastsd ymm0, xmm0
    vbroadcastsd ymm1, xmm1
    vbroadcastsd ymm4, sign_mask_sd
    shl rcx, 3 ;convert to nuber of bytes
    _loop:
    sub rcx, 32
    vmovupd ymm2, ymmword ptr [r8+rcx]  ; load x
    vmulpd ymm3, ymm2, ymm2 ; x^2
    vmulpd ymm2, ymm3, ymm2 ; x^3
    vmulpd ymm2, ymm0, ymm2 ; ax^3
    vaddpd ymm2, ymm2, ymm1 ; ax^3 + b
    vandpd ymm2, ymm2, ymm4 ; abs(x^3 + b)
    vmovupd ymmword ptr [r9+rcx], ymm2
    jnz _loop
    ret
asm01_08pd ENDP

; xmm0 <- double a
; xmm1 <- double b
; xmm2 <- double c
; xmm3 <- double d
; stos <- double *x
; stos <- double *y
; stos <- n size
asm01_10pd PROC a:qword, b:qword, c:qword, d:qword, x:qword, y:qword, n:dword
    movsxd rcx, n
    mov rsi, x
    mov rdi, y
    vbroadcastsd ymm0, xmm0
    vbroadcastsd ymm1, xmm1
    vbroadcastsd ymm2, xmm2
    vbroadcastsd ymm3, xmm3
    shl rcx, 3 ;convert to number of bytes
    _loop:
    sub rcx, 32
    vmovupd ymm4, ymmword ptr[rsi+rcx] ; ymm4 <- x
    vmulpd ymm5, ymm4, ymm4; ymm5 <- x^2
    vmulpd ymm5, ymm5, ymm4 ; ymm5 <- x^3
    vmulpd ymm5, ymm5, ymm0 ; ymm5 <- ax^3

    vmulpd ymm4, ymm4, ymm4 ; ymm4 <- x^2
    vmulpd ymm4, ymm4, ymm1 ; ymm4 <- bx^2
    vaddpd ymm5, ymm5, ymm4 ; ymm5 <- ax^3 + bx^2
    vmovupd ymm4, ymmword ptr[rsi+rcx] ; ymm4 <- x
    vmulpd ymm4, ymm4, ymm2 ; ymm4 <- cx
    vaddpd ymm5, ymm5, ymm4 ; ymm5 <- ax^3 + bx^2 + cx
    vaddpd ymm5, ymm5, ymm3 ; ymm5 <- wynik
    vmovupd ymmword ptr [rdi+rcx], ymm5
    jnz _loop
    ret
asm01_10pd ENDP

; rcx <- double *a
; rdx <- double *b
; r8 <- double *c
; r9 <- double *d
; stos <- double *y
; stos <- size n
asm01_11pd PROC a:qword, b:qword, c:qword, d:qword, y:qword, n:dword
    movsxd rax, n
    mov rdi, y
    vbroadcastsd ymm5, _1d
    shl rax, 3 ; convert to bytes
    _loop:
    sub rax, 32 ; displacment for 4 doubles (32 bytes)
    vmovupd ymm0, ymmword ptr [rcx+rax] ; ymm0 <- a
    vmovupd ymm1, ymmword ptr [rdx+rax] ; ymm1 <- b
    vaddpd ymm0, ymm1, ymm0     ; ymm0 <- a+b
    vmulpd ymm0, ymm0, ymm0 ; (a+b)^2
    vmovupd ymm1, ymmword ptr [r8+rax] ; ymm1 <- c
    vmovupd ymm2, ymmword ptr [r9+rax] ; ymm2 <- d
    vmulpd ymm1, ymm1, ymm2     ; ymm1 <- cd
    vaddpd ymm1, ymm1, ymm5
    vsqrtpd ymm1, ymm1
    vsubpd ymm0, ymm0, ymm1
    vmovupd ymmword ptr [rdi+rax], ymm0
    jnz _loop
    ret
asm01_11pd ENDP

;RCX <- double * a
;RDX <- double * b
;R8 <- double * y
;R9d <- uint n
asm01_15pd PROC
    movsxd r9, r9d  ; r9 <- n to 64b
    shl r9, 3
    _loop:
    sub r9, 32
    vmovupd ymm0, ymmword ptr [rcx + r9]    ;ymm0 <- a[i:i+3]
    vaddsubpd ymm0, ymm0, ymmword ptr [rdx + r9]
    vmovupd ymmword ptr [r8 + r9], ymm0
    jnz _loop
    ret
asm01_15pd ENDP


; rcx <- double *a
; rdx <- double *b
; r8 <- double *x
; r9 <- double *y
; stos <- uint n
asm01_16pd PROC a:qword, b:qword, x:qword, y:qword, n:dword
    movsxd rax, n; size to 64b
    shl rax, 3 ; convert to number of bytes
    _loop:
    sub rax, 32
    vmovupd ymm0, ymmword ptr [rcx + rax]
    vaddsubpd ymm0, ymm0, ymmword ptr [rdx +rax]
    vmulpd ymm0, ymm0, ymmword ptr [r8 + rax]
    vmovupd ymmword ptr [r9 + rax], ymm0
    jnz _loop
    ret
asm01_16pd ENDP

;xmm0 <- double a
;xmm1 <- double b
;R8 <- double *x
;R9 <- double *y
;n <- uint n
asm02_01pd PROC a:qword, b:qword, x:qword, y:qword, n:dword
    movsxd rax, n
    vbroadcastsd ymm0, xmm0
    vbroadcastsd ymm1, xmm1
    shl rax, 3
    _loop:
    sub rax, 32
    vmovupd ymm2, ymmword ptr[r8+rax] ; ymm2 <- x[i]
    vfmadd132pd ymm2, ymm1, ymm0 ; ymm2 <- xa + b
    vmovupd ymmword ptr[r9+rax], ymm2
    jnz _loop
    ret
asm02_01pd ENDP

; xmm0 <- double a
; xmm1 <- double b
; xmm2 <- double c
; xmm3 <- double d
; stos <- double *x
; stos <- double *y
; stos <- n size
; return x(x(-ax+b)+c)+d
asm02_09pd PROC a:qword, b:qword, c:qword, d:qword, x:qword, y:qword, n:dword
    movsxd rcx, n
    mov rsi, x
    mov rdi, y
    vbroadcastsd ymm0, xmm0
    vbroadcastsd ymm1, xmm1
    vbroadcastsd ymm2, xmm2
    vbroadcastsd ymm3, xmm3
    shl rcx, 3
    _loop:
    sub rcx, 32
    vmovupd ymm4, ymmword ptr [rsi+rcx]
    vfnmadd132pd ymm4, ymm1, ymm0 ; ymm4 <- -ax+b
    vmovupd ymm5, ymmword ptr [rsi+rcx]
    vfmadd132pd ymm4, ymm2, ymm5
    vfmadd132pd ymm4, ymm3, ymm5
    vmovupd ymmword ptr[rdi + rcx], ymm4
    jnz _loop
    ret
asm02_09pd ENDP

; rcx <- float *a
; rdx <- float *b
; r8 <- float *x
; r9 <- float *y
; stos <- size n
asm02_17ps PROC a:dword, b:dword, x:dword, y:dword, n:dword
    movsxd rax, n
    shl rax, 2
    _loop:
    sub rax, 32
    vmovups ymm0, ymmword ptr [rcx+rax] ;ymm0 <- a
    vmovups ymm1, ymmword ptr [rdx+rax] ;ymm1 <- b
    vfmaddsub132ps ymm0, ymm1, ymm0   ;ymm0 <- a^2-b/+b
    vmovupd ymm2, ymmword ptr [r8+rax]  ;ymm2 <- x
    vmovups ymm3, ymmword ptr [rcx+rax] ;ymm3 <- a
    vfmaddsub132ps ymm3, ymm1, ymm2 ;ymm3 <- ax +/- b
    vdivps ymm0, ymm0, ymm3   ;ymm0 <- wynik
    vmovups ymmword ptr [r9+rax], ymm0
    jnz _loop
    ret
asm02_17ps ENDP

;RCX <- double *a
;EDX <- uint n
asm03_01pd PROC
    movsxd rdx, edx ;rdx <- n to 64b
    shl rdx, 3  ;convert number of elements to number of bytes (n*sizeof(double))
    vxorpd ymm0, ymm0, ymm0 ;ymm0[3:0] <- 0 (identity element) Element neutralny
    _loop:
    sub rdx, 32 ;
    vaddpd ymm0, ymm0, ymmword ptr [rcx + rdx] ; ymm0 [3:0]<- sum [3:0] += a[i:i+3]
    jnz _loop
    vperm2f128 ymm1, ymm0, ymm0, 1 ; ymm1[1:0] <-ymm0[3:2]
    vaddpd xmm0, xmm0, xmm1 ; xmm0 <- xmm0+xmm1 (mlodsza+starsza czesc)
    vpermilpd xmm1, xmm0, 1 ;xmm1[1:0]
    vaddsd xmm0, xmm0, xmm1;
    ret
asm03_01pd ENDP

; rcx <- dobule *a
; edx <- size n
asm03_02pd PROC
    movsxd rdx, edx
    vmovupd ymm0, _1d ; one to the ymm register
    shl rdx, 3
    _loop:
    sub rdx, 32
    vmulpd ymm0, ymm0, ymmword ptr[rcx+rdx] ;prod(a)
    jnz _loop
    vperm2f128 ymm1, ymm0, ymm0, 1 ; ymm1[1:0] <- ymm0[3:2]
    vaddpd xmm0, xmm0, xmm1 ; xmm0 <- xmm0 + xmm1 (mlodsza + starsza czêœæ)
    vpermilpd xmm1, xmm0, 1 ;xmm1[1:0]
    vaddsd xmm0, xmm0 ,xmm1
    ret
asm03_02pd ENDP

; rcx <- double *a
; edx <- uint n
asm03_03pd PROC
    movsxd rdx, edx
    mov rax, rdx ; rax <- n
    shl rdx, 3
    vxorpd ymm0, ymm0, ymm0
    _loop:
    sub rdx, 32
    vmovupd ymm1, ymmword ptr [rcx+rdx]
    vaddpd ymm0, ymm0, ymm1;
    jnz _loop
    vperm2f128 ymm1, ymm0, ymm0, 1 ; 
    vaddpd xmm0, xmm0, xmm1;
    vpermilpd xmm1, xmm0, 1
    vaddsd xmm0, xmm0, xmm1;
    cvtsi2sd xmm1, rax
    divsd xmm0, xmm1
    ret
asm03_03pd ENDP

; rcx <- double *a
; edx <- uint n
asm03_04pd PROC
    movsxd rdx, edx
    shl rdx, 3
    vxorpd ymm0, ymm0, ymm0
    _loop:
    sub rdx, 32
    vmovupd ymm1, ymmword ptr [rcx+rdx]
    vmulpd ymm1, ymm1, ymm1 ; ymm1 <- x^2
    vaddpd ymm0, ymm0, ymm1
    jnz _loop
    vperm2f128 ymm1, ymm0, ymm0, 1 ; ymm1 [1:0] <- ymm0 [2:3]
    vaddpd xmm0, xmm0, xmm1
    vpermilpd xmm1, xmm0, 1
    vaddsd xmm0, xmm0, xmm1
    vsqrtsd xmm0, xmm0, xmm0
    ret
asm03_04pd ENDP

; rcx <- double *a
; rdx <- double *b
; r8d <- uint n
asm03_05pd PROC
    movsxd r8, r8d
    shl r8, 3
    vxorpd ymm0, ymm0, ymm0
    _loop:
    sub r8, 32
    vmovupd ymm1, ymmword ptr [rcx + r8]
    vmulpd ymm1, ymm1, ymmword ptr [rdx + r8]
    vaddpd ymm0, ymm0, ymm1
    jnz _loop
    vperm2f128 ymm1, ymm0, ymm0, 1;
    vaddpd xmm0, xmm1, xmm0;
    vpermilpd xmm1, xmm0, 1
    vaddsd xmm0, xmm1, xmm0
    
    ret
asm03_05pd ENDP

; rcx <- float *a
; rdx <- float *b
; xmm2 <- float c
; r9d <- size n
asm03_09ps PROC
    movsxd r9, r9d
    vbroadcastss ymm2, xmm2
    shl r9, 2
    vxorps ymm0, ymm0, ymm0
    _loop:
    sub r9, 32
    vmovups ymm1, ymmword ptr [rcx+r9]
    vdivps ymm1, ymm1, ymm2
    vaddps ymm1, ymm1, ymmword ptr [rdx+r9]
    vaddps ymm0, ymm0, ymm1
    jnz _loop
    vperm2f128 ymm1, ymm0, ymm0, 1
    vaddps xmm0, xmm1, xmm0
    vpermilps xmm1, xmm0, 1
    vaddps xmm0 , xmm1, xmm0
    vpermilps xmm1, xmm0, 1
    vaddss xmm0, xmm0, xmm1
    ret
asm03_09ps ENDP

END