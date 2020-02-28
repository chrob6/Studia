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

mov rax, [tab]
mov r13, 1

_petla_min:

cmp eax, [tab+r13*4]
jl _mniejsze

mov eax, [tab + r13*4]

_mniejsze:
inc r13
cmp r13,10
jne _petla_min

mov rdi, format
mov esi, eax
xor rax,rax
call printf wrt ..plt

mov rsp, rbp
pop rbp
ret

