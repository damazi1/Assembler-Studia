.code

asm06_01_01_01 PROC uses rsi rdi
    movsxd rcx, ecx     ; convert 32-b to 64-b
    mov rsi, rdx        ;rsi <- base address of source string
    mov rdi, r8         ;rdi <- base address of target string
    cld                 ; DF <- 0 (Increment index registers)
    rep movsb           ; while (rcx !=0) b[i] <- a[i]    
    ret
asm06_01_01_01 ENDP

asm06_01_01_02 PROC uses rsi rdi
    movsxd rcx, ecx
    mov rsi, rdx
    mov rdi, r8
    cld
    rep movsw
    ret
asm06_01_01_02 ENDP

asm06_01_01_03 PROC uses rsi rdi
 movsxd rcx, ecx
    mov rsi, rdx
    mov rdi, r8
    cld
    rep movsd
    ret
asm06_01_01_03 ENDP

asm06_01_01_04 PROC uses rsi rdi
    movsxd rcx, ecx
    mov rsi, rdx
    mov rdi, r8
    cld
    rep movsq
    ret
asm06_01_01_04 ENDP

asm06_02_01_01 PROC uses rdi
    movsxd rcx, ecx ;index do 64-b
    mov rdi, rdx    ;rdi <-
    mov al, r8b     ;
    cld
    rep stosb
    ret
asm06_02_01_01 ENDP

asm06_02_01_02 PROC
    movsxd rcx, ecx ;index do 64-b
    mov rdi, rdx    ;rdi <-
    mov ax, r8w     ;
    cld
    rep stosw
    ret
asm06_02_01_02 ENDP

asm06_02_01_03 PROC
    movsxd rcx, ecx ;index do 64-b
    mov rdi, rdx    ;rdi <-
    mov eax, r8d     ;
    cld
    rep stosd
    ret
asm06_02_01_03 ENDP

asm06_02_01_04 PROC
    movsxd rcx, ecx ;index do 64-b
    mov rdi, rdx    ;rdi <-
    mov rax, r8     ;
    cld
    rep stosq
    ret
asm06_02_01_04 ENDP

asm06_03_01_01 PROC uses rsi rdi
    movsxd rcx, ecx     ; convert 32-b to 64-b
    mov rsi, rdx        ;rsi <- base address of source string
    mov rdi, r8         ;rdi <- base address of target string
    cld                 ;DF <- 0
    mov rax, 1          ;assume rax <-1
    repe cmpsb          ; while (rcx != 0 && src==dst)
    je _skip            
    mov rax, 0
_skip:
    ret
asm06_03_01_01 ENDP

asm06_03_01_02 PROC uses rsi rdi
    movsxd rcx, ecx
    mov rsi, rdx
    mov rdi, r8
    cld
    mov rax, 1      ;assume rax <-1
    repe cmpsw
    je _skip
    mov rax, 0
_skip:
    ret
asm06_03_01_02 ENDP

asm06_03_01_03 PROC uses rsi rdi
        movsxd rcx, ecx     ; convert 32-b to 64-b
    mov rsi, rdx        ;rsi <- base address of source string
    mov rdi, r8         ;rdi <- base address of target string
    cld                 ;DF <- 0
    mov rax, 1          ;assume rax <-1
    repe cmpsd          ; while (rcx != 0 && src==dst)
    je _skip            
    mov rax, 0
_skip:
    ret
asm06_03_01_03 ENDP

asm06_03_01_04 PROC uses rsi rdi
        movsxd rcx, ecx     ; convert 32-b to 64-b
    mov rsi, rdx        ;rsi <- base address of source string
    mov rdi, r8         ;rdi <- base address of target string
    cld                 ;DF <- 0
    mov rax, 1          ;assume rax <-1
    repe cmpsq          ; while (rcx != 0 && src==dst)
    je _skip            
    mov rax, 0
_skip:
    ret
asm06_03_01_04 ENDP

asm06_03_02_01 PROC uses rsi rdi
    movsxd rcx, ecx     ; convert 32-b to 64-b
    mov r9, rcx
    mov rsi, rdx        ;rsi <- base address of source string
    mov rdi, r8         ;rdi <- base address of target string
    cld                 ;DF <- 0
    mov rax, 1          ;assume rax <-1
    repe cmpsb          ; while (rcx != 0 && src==dst)
    je _skip            
    sub r9, rcx
    sub r9, 1
    mov rax, r9
_skip:
    ret
asm06_03_02_01 ENDP

asm06_03_02_02 PROC uses rsi rdi
    movsxd rcx, ecx     ; convert 32-b to 64-b
    mov r9, rcx
    mov rsi, rdx        ;rsi <- base address of source string
    mov rdi, r8         ;rdi <- base address of target string
    cld                 ;DF <- 0
    mov rax, 1          ;assume rax <-1
    repe cmpsw          ; while (rcx != 0 && src==dst)
    je _skip            
    sub r9, rcx
    sub r9, 1
    mov rax, r9
_skip:
    ret
asm06_03_02_02 ENDP

asm06_03_02_03 PROC uses rsi rdi
    movsxd rcx, ecx     ; convert 32-b to 64-b
    mov r9, rcx
    mov rsi, rdx        ;rsi <- base address of source string
    mov rdi, r8         ;rdi <- base address of target string
    cld                 ;DF <- 0
    mov rax, 1          ;assume rax <-1
    repe cmpsd          ; while (rcx != 0 && src==dst)
    je _skip            
    sub r9, rcx
    sub r9, 1
    mov rax, r9
_skip:
    ret
asm06_03_02_03 ENDP

asm06_03_02_04 PROC uses rsi rdi
    movsxd rcx, ecx     ; convert 32-b to 64-b
    mov r9, rcx
    mov rsi, rdx        ;rsi <- base address of source string
    mov rdi, r8         ;rdi <- base address of target string
    cld                 ;DF <- 0
    mov rax, 1          ;assume rax <-1
    repe cmpsq          ; while (rcx != 0 && src==dst)
    je _skip            
    sub r9, rcx
    sub r9, 1
    mov rax, r9
_skip:
    ret
asm06_03_02_04 ENDP

asm06_04_01_01 PROC uses rdi
    movsxd rcx, ecx
    mov rdi, rdx
    cld
    mov rax, r8
    repne scasb
    mov rax, 1
    je _skip
    xor rax, rax
_skip:
    ret
asm06_04_01_01 ENDP

asm06_04_01_02 PROC uses rdi
    movsxd rcx, ecx
    mov rdi, rdx
    cld
    mov rax, r8
    repne scasw
    mov rax, 1
    je _skip
    xor rax, rax
_skip:
    ret
asm06_04_01_02 ENDP
    ;ecx <- uint n
    ;rdx <- int* a
    ;r8 <- int v(alue)
asm06_04_01_03 PROC uses rdi
    movsxd rcx, ecx
    mov rdi, rdx
    cld
    mov rax, r8
    repne scasd
    mov rax, 1
    je _skip
    xor rax, rax
_skip:
    ret
asm06_04_01_03 ENDP

asm06_04_01_04 PROC
    movsxd rcx, ecx
    mov rdi, rdx
    cld
    mov rax, r8
    repne scasq
    mov rax, 1
    je _skip
    xor rax, rax
_skip:
    ret
asm06_04_01_04 ENDP

asm06_04_02_01 PROC
    movsxd rcx, ecx
    mov rdi, rdx
    mov r9, rcx
    cld
    mov rax, r8
    repne scasb
    je _skip
    mov rax, 0
    ret
_skip: 
    sub r9, rcx
    sub r9, 1
    mov rax, r9
    ret
asm06_04_02_01 ENDP

asm06_04_02_02 PROC
    movsxd rcx, ecx
    mov rdi, rdx
    mov r9, rcx
    cld
    mov rax, r8
    repne scasw
    je _skip
    mov rax, 0
    ret
_skip: 
    sub r9, rcx
    sub r9, 1
    mov rax, r9
    ret
asm06_04_02_02 ENDP

asm06_04_02_03 PROC uses rdi
    movsxd rcx, ecx
    mov rdi, rdx
    mov r9, rcx
    cld
    mov rax, r8
    repne scasd
    je _skip
    mov rax, 0
    ret
_skip: 
    sub r9, rcx
    sub r9, 1
    mov rax, r9
    ret
asm06_04_02_03 ENDP

asm06_04_02_04 PROC
    movsxd rcx, ecx
    mov rdi, rdx
    mov r9, rcx
    cld
    mov rax, r8
    repne scasq
    je _skip
    mov rax, 0
    ret
_skip: 
    sub r9, rcx
    sub r9, 1
    mov rax, r9
    ret
asm06_04_02_04 ENDP

asm06_04_03_01 PROC
    movsxd rcx, ecx
    mov rdi, rdx
    cld
    xor r9, r9
    xor rax, rax
    jmp _start
_eq:
    inc r9
_start:
    repne scasb
    je _eq
    mov rax, r9
    ret
asm06_04_03_01 ENDP

asm06_04_03_02 PROC
    movsxd rcx, ecx
    mov rdi, rdx
    cld
    xor r9, r9
    xor rax, rax
    jmp _start
_eq:
    inc r9
_start:
    repne scasw
    je _eq
    mov rax, r9
    ret
asm06_04_03_02 ENDP

asm06_04_03_03 PROC
    movsxd rcx, ecx
    mov rdi, rdx
    cld
    xor r9, r9
    jmp _start
_eq:
    inc r9
_start:
    repne scasd
    je _eq
    mov rax, r9
    ret
asm06_04_03_03 ENDP

asm06_04_03_04 PROC
    movsxd rcx, ecx
    mov rdi, rdx    ;przenoszenie
    cld
    xor r9, r9      ;zerowanie
    xor rax, rax    ;zerowanie
    jmp _start      ;skok do while (T[rdi] == 0) do ++r9
_eq:
    inc r9
_start:
    repne scasq
    je _eq
    mov rax, r9
    ret
asm06_04_03_04 ENDP

asm06_04_04_01 PROC
    movsxd rcx, ecx
    mov r8, rcx
    mov rdi, rdx    ;przenoszenie
    cld
    xor r9, r9      ;zerowanie
    xor rax, rax    ;zerowanie
    jmp _start      ;skok do while (T[rdi] == 0) do ++r9
_eq:
    inc r9
_start:
    repne scasb
    je _eq
    sub r8, r9
    mov rax, r8
    ret
asm06_04_04_01 ENDP

asm06_04_04_02 PROC
    movsxd rcx, ecx
    mov r8, rcx
    mov rdi, rdx    ;przenoszenie
    cld
    xor r9, r9      ;zerowanie
    xor rax, rax    ;zerowanie
    jmp _start      ;skok do while (T[rdi] == 0) do ++r9
_eq:
    inc r9
_start:
    repne scasw
    je _eq
    sub r8, r9
    mov rax, r8
    ret
asm06_04_04_02 ENDP

asm06_04_04_03 PROC
    movsxd rcx, ecx
    mov r8, rcx
    mov rdi, rdx    ;przenoszenie
    cld
    xor r9, r9      ;zerowanie
    xor rax, rax    ;zerowanie
    jmp _start      ;skok do while (T[rdi] == 0) do ++r9
_eq:
    inc r9
_start:
    repne scasd
    je _eq
    sub r8, r9
    mov rax, r8
    ret
asm06_04_04_03 ENDP

asm06_04_04_04 PROC
    movsxd rcx, ecx
    mov r8, rcx
    mov rdi, rdx    ;przenoszenie
    cld
    xor r9, r9      ;zerowanie
    xor rax, rax    ;zerowanie
    jmp _start      ;skok do while (T[rdi] == 0) do ++r9
_eq:
    inc r9
_start:
    repne scasq
    je _eq
    sub r8, r9
    mov rax, r8
    ret
asm06_04_04_04 ENDP

asm_ltrim PROC
    movsxd rcx, ecx
    mov rdi, rdx
_start:
    cmp byte ptr [rdx+1*rcx-1], ' '
    jne _not_space
    dec rcx
    stosq
    jmp _start
        
    _not_space:
        mov rcx, 1
        stosq
    ret
asm_ltrim ENDP

asm_rtrim PROC
    ret
asm_rtrim ENDP

asm_trim PROC
    ret
asm_trim ENDP

asm_replace_all PROC
    ret
asm_replace_all ENDP

asm06_05_01_01 PROC
    xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while1:
    lodsb
    shr al,1
    jc _skip
    inc r8
    _skip:
    dec rcx
    jne _while1
    mov rax, r8
    
    ret
asm06_05_01_01 ENDP

asm06_05_01_02 PROC uses rsi
    xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while1:
    lodsw
    shr ax,1
    jc _skip
    inc r8
    _skip:
    dec rcx
    jne _while1
    mov rax, r8
    ret
asm06_05_01_02 ENDP

asm06_05_01_03 PROC
    xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while1:
    lodsd
    shr eax,1
    jc _skip
    inc r8
    _skip:
    dec rcx
    jne _while1
    mov rax, r8
    ret
asm06_05_01_03 ENDP

asm06_05_01_04 PROC
xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while1:
    lodsq
    shr rax,1
    jc _skip
    inc r8
    _skip:
    dec rcx
    jne _while1
    mov rax, r8
    ret
asm06_05_01_04 ENDP

asm06_05_02_01 PROC
xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while1:
    lodsb
    shr al,1
    jnc _skip
    inc r8
    _skip:
    dec rcx
    jne _while1
    mov rax, r8
    
    ret
asm06_05_02_01 ENDP

asm06_05_02_02 PROC
xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while1:
    lodsw
    shr ax,1
    jnc _skip
    inc r8
    _skip:
    dec rcx
    jne _while1
    mov rax, r8
    
    ret
asm06_05_02_02 ENDP

asm06_05_02_03 PROC
xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while1:
    lodsd
    shr eax,1
    jnc _skip
    inc r8
    _skip:
    dec rcx
    jne _while1
    mov rax, r8
    
    ret
asm06_05_02_03 ENDP

asm06_05_02_04 PROC
xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while1:
    lodsq
    shr rax,1
    jnc _skip
    inc r8
    _skip:
    dec rcx
    jne _while1
    mov rax, r8
    
    ret
asm06_05_02_04 ENDP

asm06_05_03_01 PROC
    xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while:
    lodsb
    cmp al, 0
    jg _skip
    inc r8
    _skip:
    dec rcx
    jne _while
    mov rax, r8
    ret
asm06_05_03_01 ENDP

asm06_05_03_02 PROC
    xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while:
    lodsw
    cmp ax, 0
    jg _skip
    inc r8
    _skip:
    dec rcx
    jne _while
    mov rax, r8
    ret
asm06_05_03_02 ENDP

asm06_05_03_03 PROC
    xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while:
    lodsd
    cmp eax, 0
    jg _skip
    inc r8
    _skip:
    dec rcx
    jne _while
    mov rax, r8
    ret
asm06_05_03_03 ENDP

asm06_05_03_04 PROC
    xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while:
    lodsq
    cmp rax, 0
    jg _skip
    inc r8
    _skip:
    dec rcx
    jne _while
    mov rax, r8
    ret
asm06_05_03_04 ENDP

asm06_05_04_01 PROC
    xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while:
    lodsb
    cmp al, 0
    jl _skip
    inc r8
    _skip:
    dec rcx
    jne _while
    mov rax, r8
    ret
asm06_05_04_01 ENDP

asm06_05_04_02 PROC
    xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while:
    lodsw
    cmp ax, 0
    jl _skip
    inc r8
    _skip:
    dec rcx
    jne _while
    mov rax, r8
    ret
asm06_05_04_02 ENDP

asm06_05_04_03 PROC
    xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while:
    lodsd
    cmp eax, 0
    jl _skip
    inc r8
    _skip:
    dec rcx
    jne _while
    mov rax, r8
    ret
asm06_05_04_03 ENDP

asm06_05_04_04 PROC
    xor r8, r8
    movsxd rcx, ecx
    mov rsi, rdx
    _while:
    lodsq
    cmp rax, 0
    jl _skip
    inc r8
    _skip:
    dec rcx
    jne _while
    mov rax, r8
    ret
asm06_05_04_04 ENDP

asm06_05_05_01 PROC
    mov r8b, 2
    movsxd rcx, ecx
    mov rsi, rdx
    _while:
    lodsb
    shl al, 2
    add al, 5
    cbw
    idiv r8b
    mov byte ptr [rsi+1*rcx-1], al
    dec rcx
    jne _while
    ret
asm06_05_05_01 ENDP

asm06_05_05_02 PROC
    ret
asm06_05_05_02 ENDP

asm06_05_05_03 PROC
    ret
asm06_05_05_03 ENDP

asm06_05_05_04 PROC uses rsi rbx
    mov r8, 2
    movsxd rcx, ecx
    mov rsi, rdx
    mov rbx, rdx
    _while:
    lodsq
    shl rax, 2
    add rax, 5
    cqo
    idiv r8
    mov qword ptr [rsi+8*rcx-8], rax
    dec rcx
    jne _while
    ret
asm06_05_05_04 ENDP

asm06_05_06_01 PROC
    ret
asm06_05_06_01 ENDP

asm06_05_06_02 PROC
    ret
asm06_05_06_02 ENDP

asm06_05_06_03 PROC
    ret
asm06_05_06_03 ENDP

asm06_05_06_04 PROC
    ret
asm06_05_06_04 ENDP

asm06_05_07_01 PROC
    ret
asm06_05_07_01 ENDP

asm06_05_07_02 PROC
    ret
asm06_05_07_02 ENDP

asm06_05_07_03 PROC
    ret
asm06_05_07_03 ENDP

asm06_05_07_04 PROC
    ret
asm06_05_07_04 ENDP

asm06_05_08_01 PROC
    ret
asm06_05_08_01 ENDP

asm06_05_08_02 PROC
    ret
asm06_05_08_02 ENDP

asm06_05_08_03 PROC
    ret
asm06_05_08_03 ENDP

asm06_05_08_04 PROC
    ret
asm06_05_08_04 ENDP

END