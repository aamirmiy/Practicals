section .data
	m1: db ' GDTR ' ,0x0A
	l1: equ $-m1

	m2: db ' LDTR ',0x0A
	l2: equ $-m2
	
	m3: db ' IDTR ',0x0A
	l3: equ $-m3

	m4: db ' MSW ',0x0A
	l4: equ $-m4

	m5: db ' YOU ARE IN PROTECTED MODE ',0x0A
	l5: equ $-m5
	
	m6: db ' YOU ARE IN REAL MODE ',0x0A
	l6: equ $-m6 

	m7: db ' COPROCESSOR IS PRESENT  ',0x0A
	l7: equ $-m7

	m8: db ' COPROCESSOR IS NOT PRESENT  ',0x0A
	l8: equ $-m8

	m9: db ' COPROCESSOR IS 80287  ',0x0A
	l9: equ $-m9

	m10: db ' COPROCESSOR IS 80387  ',0x0A
	l10: equ $-m10

	new_line:db 10

section .bss 
	data: resb 100
	data1:resb 100	
	result: resb 16
	cnt2: resb 16


	%macro write 2
		mov rax,1
		mov rdi,1
		mov rsi,%1
		mov rdx,%2
		syscall
	%endmacro

section .text
global main
main:
	write new_line,1
	write m1,l1             ;GDTR
	mov rax,00
	
	sgdt [data]
	mov rdx,00
	
	mov dx,word[data+4]
	call htoa
	mov rdx,00
	
	mov dx,word[data+2]
	call htoa
	mov rdx,00
	
	mov dx,word[data]
	call htoa

	



	write new_line,1
	write m3,l3            ;IDTR
	mov rax,00
	
	sidt [data]            ;change
	mov rdx,00
	
	mov dx,word[data+4]
	call htoa
	mov rdx,00
	
	mov dx,word[data+2]
	call htoa
	mov rdx,00
	
	mov dx,word[data]
	call htoa



	write new_line,1
	write m2,l2               ;LDTR
	mov rax,00	
	sldt [data1]             ;change in both
	mov rdx,00
	
	mov dx,word[data1]
	call htoa	




	write new_line,1
	write m4,l4              ;MSW
	mov rax,00	
	smsw [data1]             ;change in both
	mov rdx,00
	
	mov dx,word[data1]
	call htoa

	smsw [data1]                ; PRotected MODE     
	mov rdx,00
	mov dx,word[data1]
       
tag1:	bt dx,0                           ; checking 0 th bit
	jc pro
	write m6,l6
	jmp tag2
pro: 	write m5,l5	


tag2:	bt dx,1                         ; checking 0 th bit
	jc pro1                          
	write m7,l7
	jmp tag3
pro1: 	write m8,l8



tag3:	bt dx,4                         ; checking 4 th bit
	jc pro2
	write m9,l9
	jmp exit
pro2: 	write m10,l10

exit:	mov rax,60
	mov rdi,0
	syscall



htoa:	mov byte[result],00                           
	mov rsi,result
	mov byte[cnt2],4

	upp:	rol dx,04
		mov cl,dl
		and cl,0FH
		cmp cl,09H
		jbe next2
		add cl,07              ; {ADD} is important
		
		next2:	add cl,30H
			mov byte[rsi],cl
			inc rsi
			dec byte[cnt2]
		jnz upp
	
		write result,4
	ret
