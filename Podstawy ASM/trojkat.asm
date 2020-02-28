default rel
global main
extern printf
extern scanf

section .data

str1 db "Podaj bok pierwszy: ",10,0

str2 db "Podaj bok drugi: ",10,0

str3 db "Podaj bok trzeci: ",10,0

tak db "Jest :D ",10,0

nie db "Nie jest :( ",10,0

A dd 0
B dd 0
C dd 0
wynik dq 0

fsc db "%d",0

section .text

main:

push rbp
mov rbp,rsp

mov rdi,str1
xor rax,rax
call printf wrt ..plt

mov rdi,fsc
mov rsi,A
xor rax,rax
call scanf wrt ..plt

mov rdi,str2
xor rax,rax
call printf wrt ..plt

mov rdi,fsc
mov rsi,B
xor rax,rax
call scanf wrt ..plt

mov rdi,str3
xor rax,rax
call printf wrt ..plt

mov rdi,fsc
mov rsi,C
xor rax,rax
call scanf wrt ..plt

mov eax,[A]
imul eax 
mov [A],eax

mov eax,[B]
imul eax 
mov [B],eax

mov eax,[C]
imul eax 
mov [C],eax

mov eax,[A]
mov ebx,[B]
add eax,ebx

cmp eax,[C]
je _tak

mov rdi, nie
xor rax,rax
call printf wrt ..plt
jmp _koniec

_tak:

mov rdi,tak
xor rax,rax
call printf wrt ..plt 

_koniec:

mov rsp,rbp
pop rbp


ret
