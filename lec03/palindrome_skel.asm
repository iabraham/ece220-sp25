.ORIG x3000

LD R6, STACK_TOP        ; STACK_TOP points to x4000 at the beginning

; User Program
LEA R1 STRSTART         ; Load starting address of string

; Loop to push string onto stack 
PUSHLOOP: 
    LDR R0, R1, #0 	; Load char into register R0
                	; Did we reach null?
            		; PUSH
                  	; increment pointer
    BR PUSHLOOP		; repeat

; Finished pushing elements, now set up popping loop
PUSHDONE:
    LEA R1, STRSTART    ; Reload address of string
                        ; Initialize counter R2 to first char

;Loop to pop items from stack     
POPLOOP:
    BRz PALINDROME	; Finished processing w/o branching -> palindrome
           		; POP from stack 
              		; Code to check if popped item matches
                  	; the R2 pointer to the current char
                  	; because if no match then 
    BRnp NOTPALIN       ; not palindrome
    ADD R1, R1, #1	; increment R1 memory location
    LDR R2, R1, #0	; load new char into R2
    BR POPLOOP

; If not palindrome display so and HALT
NOTPALIN: 
    LEA R0, NPALIN
    PUTS
    HALT
    
; If palindrome disply so and HALT 
PALINDROME:
    LEA R0, PALIN
    PUTS
    HALT
    

; PUSH subroutine
;
; <--- fill in code 


; POP Subroutine
;
; <--- fill in code 


; Variables & miscellany 
; 
; <---Make necessary definitions here 

STRSTART .STRINGZ "racecar"
PALIN .STRINGZ "Palindrome!"
NPALIN .STRINGZ "Not palindrome!" 
.END
