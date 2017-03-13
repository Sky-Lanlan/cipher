assume  cs:code,ds:a

a segment
   db 'Cloud'
a ends
code segment
    
start:  mov  ax,a
        mov  ds,ax
        mov  cx,5
        mov  bx,0h
        mov  al,01000000b
  s:    or  [bx],al
        inc bx
        loop s
        mov ax,4c00h
        int 21h
code ends
end start