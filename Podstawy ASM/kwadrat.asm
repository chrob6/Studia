default rel
global main
extern scanf,printf

section .data

fsc db "%d",0
bok dd 0
star db "* ",0
spacja db " ",10,0

section .text

main:

push rbp
mov rbp,rsp

mov rdi,fsc
mov rsi,bok
xor rax,rax
call scanf wrt ..plt

mov r12d,[bok]
mov r13d,[bok]

petla:
cmp r12d,0
je petla2

mov rdi,star
xor rax,rax
call printf wrt ..plt

dec r12d

jmp petla

petla2:
mov r12d,[bok]

mov rdi,spacja
xor rax,rax
call printf wrt ..plt

dec r13d
jnz petla


mov rsp,rbp
pop rbp

ret
