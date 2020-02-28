global _start

section .data
liczba db 0,0
ujemna db "Ujemna",10
dlujemna equ $-ujemna
dodatnia db "Dodatnia",10
dldodatnia equ $-dodatnia
zero db "Zero",10
dlzero equ $-zero

section .text

_start:

mov rax,3
mov rbx,0
mov rcx,liczba
mov rdx,2
int 80h

mov al,[liczba]
cmp al,'-'
jnz _else

mov rax,4
mov rbx,1
mov rcx,ujemna
mov rdx,dlujemna
int 80h
jmp _koniec

_else:

cmp al,'0'
jnz _dalej

mov rax,4
mov rbx,1
mov rcx,zero
mov rdx,dlzero
int 80h
jmp _koniec

_dalej:
mov rax,4
mov rbx,1
mov rcx,dodatnia
mov rdx,dldodatnia
int 80h
jmp _koniec

_koniec:
mov rax,1
xor rbx,rbx
int 80h

