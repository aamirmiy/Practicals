%macro scall 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro
section .data
msg: db "1.successive addition",0x0A
     db "2.add and shift",0x0A
     db "3.Exit",0x0A
len: equ $-msg
msg1: db "enter first two digit number",0x0A
len1: equ $-msg1
msg2:	db "enter second two digit number",0x0A
len2: equ $-msg2
msg3: db "the result is",0x0A
len3: equ $-msg3
msg4: db "",0x0A
len4: equ $-msg4
cnt: db 0
section .bss
choice: resb 2
n: resb 3
n1: resb 1
n2: resb 1
result: resb 4

section .text
global main
main:
	scall 1,1,msg,len
	scall 0,0,choice,2

	cmp byte[choice],31H
	je first

	cmp byte[choice],32H
	je second

	cmp byte[choice],33H
	je exit
first:
	scall 1,1,msg1,len1
	scall 0,0,n,3
	call atoh1
	mov byte[n1],bl
	mov byte[n],00
	scall 1,1,msg2,len2
	scall 0,0,n,3
	call atoh1
	mov byte[n2],bl
	call sa
	scall 1,1,msg4,len4
	call main
second:
	scall 1,1,msg1,len1
	scall 0,0,n,3
	call atoh1
	mov byte[n1],bl
	mov byte[n],00
	scall 1,1,msg2,len2
	scall 0,0,n,3
	call atoh1
	mov byte[n2],bl
	call add_shift
	scall 1,1,msg4,len4
	call main
exit:	
mov rax,60
mov rdi,0
syscall
atoh1: 	
	mov rdi,n
	mov byte[cnt],2
	mov ebx,00
up:	rol ebx,4
	mov dl,byte[rdi]
	cmp dl,39H
	jbe next
	sub dl,07H
next:	sub dl,30H
	add bl,dl
	inc rdi
	dec byte[cnt]
	jnz up
	ret	
sa:	mov ax,00
	mov al,byte[n1]
	mov cl,byte[n2]
	mov bx,00
	up3:
	add bx,ax
	dec cl
	jnz up3
	;mov byte[result],bl
	call htoa
	ret
add_shift:
	mov cx,00
	mov byte[cnt],8
	mov ax,00
	mov al,byte[n1]
	mov bx,00
	mov bl,byte[n2]
u:
	shr bx,01
	jnc down
	add cx,ax
	
down: 
	shl ax,01
	dec byte[cnt]
	jnz u
	call htoa1
	ret
	
htoa:	mov rsi,result
	mov byte[cnt],4
	mov dx,bx
upp:	
	rol dx,04
	mov cl,dl
	and cl,0FH
	cmp cl,09H
	jbe next2
	add cl,07
next2:	
	add cl,30H
	mov byte[rsi],cl
	inc rsi
	dec byte[cnt]
	jnz upp
	scall 1,1,result,4
	ret
htoa1:	mov rsi,result
	mov byte[cnt],4
	mov dx,cx
u1:	
	mov cx,00
	rol dx,04
	mov cl,dl
	and cl,0FH
	cmp cl,09H
	jbe nex
	add cl,07
nex:	
	add cl,30H
	mov byte[rsi],cl
	inc rsi
	dec byte[cnt]
	jnz u1
	scall 1,1,result,4
	ret

