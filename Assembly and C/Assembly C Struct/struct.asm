extern printf
global main

section .data

format_specifier_string:
    db '%s', 10, 0

format_specifier_float:
    db '%f', 10, 0

format_specifier_decimal:
    db '%d ', 0

format_specifier_blank:
    db '', 10, 0

struc Student
    s_float resb 10
    s_name resb 25
    s_email resb 30
    s_address resb 20
    s_grade_array resb 20
endstruc

jwilson istruc Student
    at s_float, dq 1.45
    at s_name, db 'Jonathan Wilson',
    at s_email, db 'jwilson@liberty.edu',
    at s_address, db 'Hong Kong',
    at s_grade_array, dd 100, 200, 300, 400, 500
iend

section .text
main:

    push rbp
    movsd xmm0, [jwilson + s_float]
    mov rdi, format_specifier_float
    mov rax, 1
    call printf
    pop rbp

    mov rdi, format_specifier_string
    mov rsi, jwilson + s_name
    xor rax, rax
    call printf

    mov rdi, format_specifier_string
    mov rsi, jwilson + s_email
    xor rax, rax
    call printf

    mov rdi, format_specifier_string
    mov rsi, jwilson + s_address
    xor rax, rax
    call printf
 
 mov rbx, 0
begin_loop:

    cmp rbx, 20
    je end_loop
    
    mov rdi, format_specifier_decimal
    mov rsi, [jwilson + s_grade_array + rbx]
    xor rax, rax
    call printf
   

    add rbx, 4
    
    cmp rbx, 12 ;edit grades array when reaching the 4th position in the array
    je start_function
    jmp begin_loop

start_function:
    call edit_grades
    jmp begin_loop

edit_grades:
;edit the last position of the array before the loop reaches it
    mov word [jwilson + s_grade_array + rbx + 4], 900 
    ret
    

end_loop:
    mov rdi, format_specifier_blank
    xor rax, rax
    call printf

    syscall










