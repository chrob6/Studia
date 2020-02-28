global main
default rel
extern printf
extern scanf

section .data
format db "%d",0
a dd 0
tab dq _dwa, _trzy, _cztery, _piec
dwa db "dwa",0
trzy db "trzy",0
cztery db "cztery",0
piec db "piec",0
blad db "blad",0

section .text
main:
push rbp
mov rbp,rsp

mov rdi,format
mov rsi, a
mov rax,rax
call scanf wrt ..plt

mov esi, [a]
cmp esi,2
jl _det 
cmp esi,5
jg _det

jmp qword [tab+8*rsi-16]

_dwa:
mov rdi,dwa
jmp _koniec

_trzy:
mov rdi,trzy
jmp _koniec

_cztery:
mov rdi,cztery
jmp _koniec

_piec:
mov rdi,piec
jmp _koniec

_det:
mov rdi,blad
jmp _koniec 


_koniec:

xor rax,rax
call printf wrt ..plt
mov rsp,rbp
pop rbp
ret 


