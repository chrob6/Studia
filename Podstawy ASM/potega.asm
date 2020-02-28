default rel
global main
extern scanf
extern printf

section .data
format db "%d",0
liczba dd 0
pot dd 0

section .text

main:

push rbp
mov rbp,rsp

mov rdi, format
mov rsi, liczba
xor rax,rax
call scanf wrt ..plt

mov rdi, format
mov rsi, pot
xor rax, rax
call scanf wrt ..plt


mov eax, 1
mov ebx, [liczba]
mov ecx,[pot]

_petla:
cmp ecx, 0
je _koniec

mul ebx
dec ecx
jmp _petla

_koniec:
mov rdi, format
mov esi, eax
xor rax, rax
call printf wrt ..plt

mov rsp,rbp
pop rbp
ret
