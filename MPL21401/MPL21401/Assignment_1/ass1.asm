section .data
arr: dq 0x1111111111111111,0xA111111111111111,0x2111111111111111,0xC111111111111111,0x3111111111111111
pos: db 0,0x0A
l: equ $-pos
neg: db 0,0x0A
l1: equ $-neg
count: db 0
msg: db "the number of positive numbers are",0x0A
len: equ $-msg
msg1: db "the number of negative numbers are",0x0A
len1: equ $-msg1
msg2: db " ",0x0A
len2: equ $-msg2
section .text
global main
main:
mov rsi,arr
mov byte[count],5
up:
	mov rax,qword[rsi]
	BT rax,63	
	JC next
	inc byte[pos]
	JMP up2
next:
	inc byte[neg]
up2:	
	add rsi,8
	dec byte[count]
	JNZ up
cmp byte[pos],9H
jbe next3
ADD byte[pos],07H
next3:
	ADD byte[pos],30H
cmp byte[neg],9H
jbe next4
ADD byte[neg],07H
next4:
	ADD byte[neg],30H
mov rax,1
mov rdi,1
mov rsi,msg
mov rdx,len
syscall
mov rax,1
mov rdi,1
mov rsi,pos
mov rdx,l
syscall
mov rax,1
mov rdi,1
mov rsi,msg1
mov rdx,len1
syscall
mov rax,1
mov rdi,1
mov rsi,neg
mov rdx,l1
syscall
mov rax,1
mov rdi,1
mov rsi,msg2
mov rdx,len2
syscall
mov rax,60
mov rdi,0
syscall

	
