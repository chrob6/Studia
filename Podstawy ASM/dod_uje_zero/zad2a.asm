default rel
global main
extern scanf
extern printf

section .data
format db "%d",0
liczba dd 0  		
dod db "Dodatnia",10,0
uje db "Ujemna",10,0
zero db "Zero",10,0


section .text
main:

push rbp
mov rbp,rsp

mov rdi, format
mov rsi, liczba
xor rax, rax ;rax-il uzytych rejstrow, zerowanie rax
call scanf wrt ..plt

mov eax,[liczba]
cmp eax, 0
jg _dod
jl _uje

mov rdi, zero
xor rax, rax
call printf wrt ..plt
jmp _koniec

_dod:
mov rdi, dod
xor rax, rax
call printf wrt ..plt
jmp _koniec

_uje:
mov rdi, uje
xor rax, rax
call printf wrt ..plt


_koniec:
mov rsp,rbp
pop rbp
mov rax,1
xor rbx, rbx
int 80h
