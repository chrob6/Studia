global main
default rel
extern printf
extern scanf

section .data
format db "%d",0
a dd 0
tab dq _brak, _prom, _prom, _prom, _prom, _prom6
prom db "prom",0
brak db "brak",0
prom6 db "prom6",0
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
cmp esi,6
jg _blad

jmp qword [tab+8*rsi-8]

_prom:
mov rdi,prom
jmp _koniec

_brak:
mov rdi,brak
jmp _koniec

_prom6:
mov rdi,prom6
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


