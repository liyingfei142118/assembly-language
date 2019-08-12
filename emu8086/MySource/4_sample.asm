name "flags"

org 100h
 mov cx,9
Next: 
       mov dx, offset 26word
       mov ah, 9
       int 21h 
       loop Next
; now a little game: 

       mov ah, 1 
       int 21h
       mov bl,al
        
       xor al,al
  mov cx, 8
print1: mov ah, 2   ; print function.

       test bl, 10000000b  ; test first bit.
       jz zero 
       mov dl,1
zero:  
       mov dl,0
       add al,dl
       mov dl,2 
       imul dl
       shl bl, 1
loop print1
  mov dl,2 
  div dl
  mov dl,al
  ;mov ah, 9
  int 21h  

       
game:  mov dx, offset msg1
       mov ah, 9
       int 21h

       ; read character in al:
       mov ah, 1 
       int 21h

       cmp al, '0'
       jb stop

       cmp al, '9'
       ja stop

       cmp al, '5'
       jb below
       ja above
       mov dx, offset equal_5
       jmp print
below: mov dx, offset below_5     
       jmp print
above: mov dx, offset above_5
print: mov ah, 9
       int 21h
       jmp game  ; loop.


stop: ret  ; stop

26word db "abcdefghijklmnopqrstuvwxyz", 0Dh,0Ah, "$"
msg1 db "enter a number or any other character to exit:  $"
equal_5 db " is five! (equal)", 0Dh,0Ah, "$"
below_5 db " is below five!" , 0Dh,0Ah, "$"
above_5 db " is above five!" , 0Dh,0Ah, "$"


