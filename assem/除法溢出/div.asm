assume  cs:code ,ds:data ,ss:stack

stack segment stack

	dw 0,0,0,0,0,0,0,0,0

stack ends

data segment

	db 0,0,0,0,0,0

data ends

code segment

start:	mov ax , data;将被除数高位放入ax，低位bx
		mov ds , ax ;除数放入cx
		mov ax , stack
		mov ss , ax
		mov sp , 18
		mov ax ,0ffffh
		mov bx ,0ffffh
		mov cx ,2h
		mov si ,0
		call  divdw
		mov ax , 4c00h
		int 21h

divdw:	mov dx ,0
		div cx;商在ax里
		push dx;余数
		mov dx , ax
		mov ax , 0
		mov ds:[4] , dx
		mov ds:[6] , ax
		pop ax
		mov dx , ax
		mov ax , 0
		mov ds:[0] , dx
		mov ds:[2] , ax
		add ds:[2] , bx  
		adc ds:[0] , si
		mov dx , ds:[0]
		mov ax , ds:[2]
		div cx;商在ax里，余数在dx;前一次的积
		add ds:[6] , ax;商在内存里
		adc ds:[4] , si
		mov ds:[8] , dx
		ret
code ends
end start
