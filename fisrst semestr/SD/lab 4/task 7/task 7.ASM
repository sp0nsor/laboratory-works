format PE console NX
  
entry start

include 'WIN32A.INC'

section '.bss' data readable writeable 

hInput dd ?
hOutput dd ? 

stub dd ?
numberOfChars1 dd ? 
numberOfChars2 dd ? 
numberOfChars3 dd ?

section '.data' data readable writeable 
newLine db 13,10

firstStr db 256 dup (" ")
secondStr db 256 dup (0x15)
thirdStr db 256 dup (0x15)

;дальше пиздец как кастыльно
frame1 db 7 dup (" "), 0xC9, 11 dup (0xCD), 0xBB, \
10, 13, 7 dup(" "), 0xBA, ' '
sizeof.frame1 = $ - frame1

frame2 db 0xBA,10,13, 7 dup (" "), 0xC8, 2 dup(0xCD), 0xD1, 5 dup (0xCD), 0xD1, 2 dup (0xCD), 0xBC,\
10,13, 10 dup(" "),0xB3, 5 dup(" "), 0xB3,\
10,13, 5 dup(" "), 0xDA, 4 dup (0xC4),0xD9, 5 dup(" "), 0xC0,4 dup (0xC4), 0xBF,\
10,13, 5 dup(" "), 0xB3,15 dup(" "), 0xB3,\
10,13,0xC9,4 dup (0xCD),0xCF,6 dup(0xCD),0xBB, 1 dup(" "), 0xC9, 6 dup (0xCD),0xCF,5 dup(0xCD), 0xBB,\
10,13,0xBA,' '

frame3 db  ''
sizeof.frame3 = $ - frame2

frame4 db 0xBA,  1 dup(" "), 0xBA
sizeof.frame4 = $ - frame3

frame5 db 10, 13, 0xC8, 11 dup(0xCD),0xBC, 1 dup(" "), 0xC8,12 dup(0xCD),0xBC
sizeof.frame5 = $ - frame4

section '.text' code readable executable 

start:

    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX

    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

    ; input first line
    push NULL
    push numberOfChars1       
    push 1000
    push firstStr       
    push [hInput]   
    call [ReadConsole] 

    ; input second line
    push NULL
    push numberOfChars2   
    push 1000   
    push secondStr       
    push [hInput]   
    call [ReadConsole] 

    ; input third line
    push NULL
    push numberOfChars3  
    push 1000   
    push thirdStr       
    push [hInput]   
    call [ReadConsole] 

    mov EBX, firstStr
    mov EAX, [numberOfChars1]
    mov byte [ EBX + EAX - 1 ], 0x15
    mov byte [ EBX + EAX - 2 ], 0x15

    mov EBX, secondStr
    mov EAX, [numberOfChars2]
    mov byte [ EBX + EAX - 1 ], 0x15
    mov byte [ EBX + EAX - 2 ], 0x15

    mov EBX, thirdStr
    mov EAX, [numberOfChars3]
    mov byte [ EBX + EAX - 1 ], 0x15
    mov byte [ EBX + EAX - 2 ], 0x15

    ; input new line
    push NULL              
    push stub    
    push 2
    push newLine       
    push [hOutput]      
    call [WriteConsole]

    ; -----------
    push NULL
    push stub       
    push sizeof.frame1
    push frame1      
    push [hOutput]      
    call [WriteConsole]
    ; -----------

    ; input first line
    push NULL              
    push stub    
    push 10
    push firstStr       
    push [hOutput]      
    call [WriteConsole]

    ; -----------
    push NULL
    push stub       
    push sizeof.frame3
    push frame2      
    push [hOutput]      
    call [WriteConsole]
    ; -----------

    ;input second line
    push NULL              
    push stub    
    push 10
    push secondStr       
    push [hOutput]      
    call [WriteConsole] 

    ; -----------
    push NULL
    push stub       
    push sizeof.frame4
    push frame3      
    push [hOutput]      
    call [WriteConsole]
    ; -----------

    ; input third line
    push NULL              
    push stub    
    push 10
    push thirdStr       
    push [hOutput]      
    call [WriteConsole] 

    ; -----------
    push NULL
    push stub       
    push sizeof.frame5
    push frame4
    push [hOutput]      
    call [WriteConsole]
    ; -----------
    
    push 0              
    call [ExitProcess]  

section '.idata' import data readable writeable

library kernel32, 'KERNEL32.DLL'

import kernel32,\
    ExitProcess, 'ExitProcess',\    
    GetStdHandle, 'GetStdHandle',\
    WriteConsole, 'WriteConsoleA',\
    ReadConsole, 'ReadConsoleA' 

section '.reloc' fixups data readable discardable