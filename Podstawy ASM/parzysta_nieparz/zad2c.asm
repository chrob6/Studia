default rel
global main
extern scanf
extern printf

section .data
format db "%d",0
liczba dd 0
parz db "Parzysta",10,0
nieparz db "Nieparzysta" ,10,0

section .text
main:

push rbp
mov rbp,rsp

mov rdi, format
mov rsi, liczba
xor rax, rax 
call scanf wrt ..plt



mov eax, [liczba]
test eax, 1
;mov ebx, 2
;xor edx,edx
;div ebx ;dzielenie div



;cmp edx, 0
jne _nparz


mov rdi, parz
xor rax, rax
call printf wrt ..plt
jmp _koniec

_nparz:
mov rdi, nieparz
xor rax, rax
call printf wrt ..plt




_koniec:
mov rsp,rbp
pop rbp
mov rax,1
xor rbx, rbx
int 80h
