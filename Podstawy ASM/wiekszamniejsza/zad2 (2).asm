global main
default rel
extern scanf, printf

section .data
liczba dd 0
podaj dq "Podaj swoja ulubiona liczbe: ",0
twoja dq "Twoja ulubiona liczba jest wieksza niz: ",0
fpr db "%s",0
fsc db "%d",0

section .text
main:

push rsp
mov rbp,rsp

mov rdi, fpr
mov rsi, podaj
xor rax, rax
call printf wrt ..plt

mov rdi, fsc
mov rsi, liczba
xor rax, rax
call scanf wrt ..plt

mov al, [liczba]
sub al , 1
add al , '0'
mov [liczba], al

mov rdi, fpr
mov rsi, twoja
xor rax, rax
call printf wrt ..plt



mov rdi, fpr
mov rsi, liczba
xor rax, rax
call printf wrt ..plt

mov rsp,rbp
pop rsp
ret
