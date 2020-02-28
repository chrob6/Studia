global main
default rel
extern printf
extern scanf

section .data
format db "%d",0
a dd 0
tab dq _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10
dwa db "2",0
trzy db "3",0
cztery db "4",0
piec db "5",0
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
cmp esi,1
jl _blad 
cmp esi,4
jg _blad

jmp qword [tab+8*rsi-8]

_0:
mov rdi,dwa
jmp _koniec

_1:
mov rdi,dwa
jmp _koniec

_2:
mov rdi,dwa
jmp _koniec

_3:
mov rdi,dwa
jmp _koniec

_4:
mov rdi,dwa
jmp _koniec

_5:
mov rdi,trzy
jmp _koniec

_6:
mov rdi,trzy
jmp _koniec

_7:
mov rdi,cztery
jmp _koniec

_8:
mov rdi,cztery
jmp _koniec

_9:
mov rdi,piec
jmp _koniec

_10:
mov rdi,piec
jmp _koniec

_blad:
mov rdi,blad
jmp _koniec

_koniec:

xor rax,rax
call printf wrt ..plt
mov rsp,rbp
pop rbp
ret 


