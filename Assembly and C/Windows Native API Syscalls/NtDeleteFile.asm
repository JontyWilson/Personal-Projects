; ml64 NTDeleteFile.asm /Zf /link /subsystem:console /entry:main

; c000000d - invalid parameter??

; ULONG = QWORD = 8 bytes

;stack parameters are pushed in opposite order
; RCX = ACCESS_MASK/DESIRED ACCESS
; RDX = POBJECT_ATTRIBUTES/OBJECT ATTRIBUTES
; R8 = PLARGE_INTEGER/ALLOCATION SIZE (Optional)
; R9 = ULONG/FILE ATTRIBUTES (Can be zero)

;these are pushed in this order (opposite of how they are in C++)
; PUSH ULONG/EALENGTH (size of bytes of EABUFFER)
; PUSH PVOID/EABUFFER (optional)
; PUSH ULONG/CREATEOPTIONS (required bit flag)

;COMMANDS
; lea = Load effective Address (creates a pointer? or delivers a pointer)


        .data

        path dw "\", "?", "?", "\", "c", ":", "\", 
                "U", "s", "e", "r", "s", "\", 
                "U", "s", "e", "r", "\",
                "D", "e", "s", "k", "t", "o", "p", "\",
                "t", "e", "s", "t", ".", "t", "x", "t" ; each character takes up two bytes

        align 8                              ; extremely critical or RAX will store the 80000002 - data alignment mismatch error
        objatr qword 0,0,0,0,0,0             ; Structure detailed in documentation, this is reserved 48 bytes of zero (as qword is 8 bytes, and you have 6 zeros = 8x6) - where the 6 zeroes represents the 6 arguments for this object
        unistring qword 0,0                  ; unistring reserved 16 bytes of zeroes

        align 8
        filehandle qword 0                   ; filehandle reserved 8 bytes

        align 8
        iostatusblock qword 0,0              ; iostatusblock reserved 16 bytes

        .code

main    proc
 
        mov qword ptr objatr[0], 48                     ;size of object attributes struct
        mov qword ptr objatr[8], 0                      ;root directory
        lea rax, [unistring]                            ;pointer to unicode string
        mov qword ptr objatr[16], rax                   ;add pointer of unicode string to object attributes struct
        mov qword ptr objatr[24], 64                    ;perms
        mov qword ptr objatr[32], 0        
        mov qword ptr objatr[40], 0

        mov word ptr unistring[0], 68                   ;specific 0x44 length (ushort), 0x46 max length (ushort) of unicode string - used for storing the path to the txt file - it is 68 bytes long minimum
        mov word ptr unistring[2], 70
        lea rax, [path]                                 ;pointer to unicode string buffer
        mov qword ptr unistring[8], rax                 ;add pointer to unicode string to unicode pointer
                                                        ; got to do lea rax, [path] in order to move it to the unistring as it is not a valid instruction otherwise


        lea rcx, [objatr]                           ; ptr to objatr struct
        

        ; return address plus shadow space for register argument - RCX
        ; need enough space to store register. 
        xor rax, rax
        push rax
        push rax
        

        mov r10, rcx                                    ; preserves rcx in the syscall
        mov eax, 0d9h                                   ;windows 11 NTDLL NTDELETEFILE address
        syscall ;runs the ntcreatefile^


        ; NtDelete file takes one instruction - a pointer to the Objatr object. 
        ; this pointer to the objatr struct must be placed in RCX prior to the syscall


main    endp
        end