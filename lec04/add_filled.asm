; ADD subroutine – pop two numbers from stack, 
; perform ‘+’ operation and then push result back to the stack

ADD_OP
; save registers
ST R7, ADD_SAVER7
ST R0, ADD_SAVER0
ST R6, ADD_SAVER6
ST R1, ADD_SAVER1

; initialize R5
AND R5, R5, #0

; first pop
JSR POP

; check return value of first pop, go to EXIT if it failed (R5 = 1)
ADD R5, R5, #0
BRp EXIT 

;save value in R1 before second pop
ADD R1, R0, #0

; second pop
JSR POP

; check result of second pop, go to RESTORE_1 if it failed

ADD R5, R5, #0
BRp RESTORE_1

  ; add two numbers: R0 <- R0 + R1
ADD R0, R0, R1

; check range of sum, go to RESTORE_2 if it failed
JSR CHECK_RANGE
ADD R5, R5, #0
BRp RESTORE_2


; everything is good, push sum (already in R0) to stack
JSR PUSH
BRnzp EXIT 


RESTORE_1     ; put back first number
    ; Load STACK_TOP
LD R6, STACK_TOP
    ; Put back item 
ADD R6, R6, #-1
    ; Update STACK_TOP
ST R6, STACK_TOP
    ; Go to exit
BRnzp EXIT 


RESTORE_2     ; put back both numbers

    ; Load STACK_TOP
LD R6, STACK_TOP
    ; Put back item(s)
ADD R6, R6, #-2
    ; Update STACK_TOP
ST R6, STACK_TOP
;
EXIT
; restore registers
	
LD R7, ADD_SAVER7
LD R0, ADD_SAVER0
LD R6, ADD_SAVER6
LD R1, ADD_SAVER1

  RET
