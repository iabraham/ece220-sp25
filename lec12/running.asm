.ORIG x3000

;;RTS Example: answer = Running(number);
;;Original author: ywchen
;;
;;main code
;;Main's activation record starting at x4000
;;Assume it only has local variables
;answer (x3FFF) <-R6
;number (x4000) <-R5
MAIN
        LD R5, RSTACK   ;set R5 to point to addr x4000
        LD R6, RSTACK   ;set R6 to point to addr x4000
        LD R0, NUMBER   ;set R0 to x0005 
        STR R0, R6, #0  ;push number to stack (at addr x4000)
        ADD R6, R6, #-1 ;push answer to stack (at addr x3FFF)
        ;Caller stack Built-up - push RUNNING's arg to the stack
        LDR R0, R5, #0
        ADD R6, R6, #-1
        STR R0, R6, #0
        ;Pass control to callee - invoke RUNNING subroutine
        JSR RUNNING
        ;Caller stack Tear-down for RUNNING
        LDR R0, R6, #0  ;copy return value to R0
        STR R0, R5, #-1 ;save return value to answer
        ADD R6, R6, #1  ;pop return value from stack
        ADD R6, R6, #1  ;pop argument from stack
        HALT
NUMBER  .FILL   x0005
RSTACK  .FILL   x4000


;;RUNNING Subroutine
RUNNING
;callee set-up of Running Sum’s activation record
; Make space for RV, RA, CFP
ADD R6, R6, #-3

;push return address & old frame pointer
STR R7, R6, #1
STR R5, R6, #0

;;push local variables & update frame pointer
ADD R5, R6, #-1
ADD R6, R6, #-1

;function logic
;;base case (n==1)
LDR R1, R5, #4
ADD R2, R1, #-1
BRz BASE_CASE

;;recursive case
;caller setup for Running(n-1)
;push argument n-1 onto RST
ADD R6, R6, #-1
STR R2, R6, #0
;call Running(n-1)
JSR RUNNING

;caller tear-down for Running(n-1)
;pop Running(n-1)’s return value to R0
LDR R0, R6, #0
ADD R6, R6, #1

;pop Running(n-1)’s argument
ADD R6, R6, #1

;calculate n + Running(n-1)
LDR R1, R5, #4
ADD R0, R1, R0
;store result in fn
STR R0, R5, #0

;ready to return
BRnzp RETURN

BASE_CASE
;set fn = 1
AND R2, R2, #0
ADD R2, R2, #1
STR R2, R5, #0

RETURN
;set return value
LDR R0, R5, #0
STR R0, R5, #3

;callee tear-down of Factorial(n)’s activation record
;pop local variables
ADD R6, R6, #1

;restore caller’s frame pointer and return address
LDR R5, R6, #0
ADD R6, R6, #1
LDR R7, R6, #0
ADD R6, R6, #1

;return to caller
RET

.END
