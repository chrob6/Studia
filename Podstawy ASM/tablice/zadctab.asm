global main
default rel
extern scanf, printf

section .data
tab TIMES 10 dd 0
format db "%d",0


section .text
main:

push rbp
mov rbp, rsp

mov r12, tab
mov r13, 10

_petla:
mov rdi, format
mov rsi, r12
xor rax,rax
call scanf wrt ..plt

dec r13
add r12,4
cmp r13,0
jne _petla 


mov r12, tab

_pushe:

cmp r13d, 10
je _popy

mov eax, [r12 + 4*r13]
push rax
inc r13d
jmp _pushe

_popy:
cmp r13d,0
je _popy_end

pop rsi
mov rdi, format
xor eax,eax
call printf wrt ..plt

dec r13d
jmp _popy

_popy_end:
mov rsp, rbp
pop rbp
ret
