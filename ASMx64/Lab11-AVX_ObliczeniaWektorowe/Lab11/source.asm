.data
sign_mask_sd DQ 7FFFFFFFFFFFFFFFh

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

;RCX <- double a
;RDX <- double b
;R8 <- double *x
;R9 <- double *y
;n <- uint n
asm02_01pd PROC a:qword, b:qword, x:qword, y:qword, n:dword
    ret
asm02_01pd ENDP

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

END