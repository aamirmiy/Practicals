section .data
msg: db 0x0A,"1.HEX TO BCD",0x0A
     db "2.BCD TO HEX",0x0A
     db "3.EXIT",0x0A
len: equ $-msg
msg1: db 0x0A,"Enter the number",0x0A
len1: equ $-msg1

section .bss

%macro scall 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

num: resb 2
number:resb 9
result:resb 17
cnt: resb 1

section .text
global main
main:

	scall 1,1,msg,len
	scall 0,1,num,2

	mov byte[cnt],0

	cmp byte[num],31H
	je first

	cmp byte[num],32H
	je second

	cmp byte[num],33H
	je exit
	
first:	scall 1,1,msg1,len1
	scall 0,1,number,5
	call atoh	
	call HEXTOBCD
	call main

second: scall 1,1,msg1,len1
	scall 0,1,number,9
	mov qword[result],00
	mov rax,00
	mov rbx,00
	mov rcx,00
	mov rdx,00	
	call atoh2
	call BCDTOHEX
	mov edx,dword[result]             ; 
	call htoa		
	call main
	
exit:	mov rax,60
	mov rdi,0
	syscall


	
HEXTOBCD:	mov eax,0       
		add ax,bx       
		mov bx,0x0A      

up2:		mov dx,0         
		div bx
		push dx          
		inc byte[cnt] 
		cmp eax,0       
		jne up2

up3:		pop dx
		add dx,30H
		mov word[result],dx
		scall 1,1,result,2
		dec byte[cnt]
		jnz up3

		ret

atoh: 	mov rsi,number
	mov byte[cnt],4
	mov bx,00

up:	rol bx,4
	mov dl,byte[rsi]
	cmp dl,39H
	jbe next
	sub dl,07H
next:	sub dl,30H
	add bl,dl
	inc rsi
	dec byte[cnt]
	jnz up
	
	ret

atoh2: 	mov rsi,number
	mov byte[cnt],8
	mov ebx,00

up1:	rol ebx,4
	mov dl,byte[rsi]
	cmp dl,39H
	jbe next1
	sub dl,07H
next1:	sub dl,30H
	add bl,dl
	inc rsi
	dec byte[cnt]
	jnz up1
	
	ret

BCDTOHEX:	mov ecx,ebx
		mov bx,00H
		mov bl,cl
		and bl,0FH
		
		mov eax,00H
		mov ax,01H       ; 1
		mul bx
		add dword[result],eax
		
		ror ecx,04
		mov bl,cl
		and bl,0FH
		mov eax,00H
		mov ax,0x0A     ; 10
		mul bx
		add dword[result],eax

		ror ecx,04
		mov bl,cl
		and bl,0FH
		mov eax,00H
		mov ax,0x64     ; 100
		mul bx
		add dword[result],eax

		ror ecx,04
		mov bl,cl
		and bl,0FH
		mov eax,00H
		mov ax,0x3E8     ; 1000
		mul bx
		add dword[result],eax
		
		ror ecx,04
		mov bl,cl
		and bl,0FH
		mov eax,00H
		mov ax,0x2710     ; 1000
		mul bx
		add dword[result],eax
		ret

htoa:	mov rsi,result
	mov byte[cnt],8

upp:	rol edx,04
	mov cl,dl
	and cl,0FH
	cmp cl,09H
	jbe next2
	add cl,07
next2:	add cl,30H
	mov byte[rsi],cl
	inc rsi
	dec byte[cnt]
	jnz upp
	
	scall 1,1,result,8
	
	ret
