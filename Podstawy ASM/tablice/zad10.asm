global main
extern printf, scanf
default rel

section .data
format db "%c",0
format1 db "%d",10,0
tab times 50 db 0

section .text
main:
push rbp
mov rbp,rsp

mov r13d,0
mov r14d,tab

_petla:
cmp r13d,50
je _koniec


add r14d,r13d

mov rdi,format
mov esi,r14d
xor rax,rax
call scanf wrt ..plt

cmp dword [r14d],10
je _koniec

inc r13d

jmp _petla


_koniec:
mov rdi,format1
mov esi, r13d
xor rax,rax
call printf wrt ..plt


mov rsp,rbp
pop rbp
ret
