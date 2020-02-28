global _start

section .data
liczba db 0,0 ;liczba dw 0
dod db "Dodatnia",10
dl_dod equ $-dod
uje db "Ujemna",10
dl_uje equ $-uje
zero db "Zero",10
dl_zero equ $-zero

section .text
_start:

mov rax,3
mov rbx,0
mov rcx,liczba
mov rdx,2
int 80h

mov al,[liczba]
cmp al, '-'
jne _dalej

mov rax,4
mov rbx,1
mov rcx, uje
mov rdx, dl_uje
int 80h
jmp _koniec

_dalej:

cmp al,'0'
jnz _dodatnia

mov rax,4
mov rbx,1
mov rcx, zero
mov rdx, dl_zero
int 80h
jmp _koniec

_dodatnia:
mov rax,4
mov rbx,1
mov rcx, dod
mov rdx, dl_dod
int 80h

_koniec:
mov rax,1
xor rbx,rbx
int 80h
