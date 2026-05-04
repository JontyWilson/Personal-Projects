extern printf ;external function from the C library
global main ;main function for C langauge file

section .data ;place initialized variables here
format_specifier: ;format specifier for printf
    db '%x ', 0 ;declare bytes, give string '' where %x means it is displayed as hex
                   ;0 means a null terminated string
format_blank:
    db '', 10, 0 ;10 creates string with a newline function

section .text ;holds your source code in this section
main: ;main function cause we are passing to C compiler (gcc)

    mov rbx, qword 0 ;counter for number of lines


begin_loop:

    mov rcx, qword 16 ;number of characters per line

    inc rbx ;increment rbx

    push rcx
    mov rdi, format_blank
    xor rax, rax
    call printf
    pop rcx


    cmp rbx, qword 6 ;if rbx == 6
    jne inner_loop ;Jump-if-Not-Equal to inner loop
    jmp done ;if is equal, finish


inner_loop:

    dec rcx ;decrement rcx

    push rcx ;push to the stack
    mov rdi, format_specifier ;specify format (no newline)
    mov rsi, rcx
    xor rax, rax
    call printf  ;print
    pop rcx ;pop off the stack

    cmp rcx, qword 0 ;if rcx == 0
    je begin_loop ; if equal, jump to outer loop
    jmp inner_loop ; if not equal, jump to inner loop
    
    

done:

    mov rax, 60
    syscall ;terminate process



