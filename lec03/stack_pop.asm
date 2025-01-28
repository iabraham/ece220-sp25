; POP Subroutine
; OUT: R0 (value)
; OUT: R5 (0 – success, 1 – fail)
; R3: STACK_START
; R6: STACK_TOP
; Author: ywchen

POP
;
; save registers that will be modified in POP subroutine
;
        ST R3, POP_SaveR3 ; save R3
        ST R6, POP_SaveR6 ; save R6
        AND R5, R5, #0 ; clear R5, indicates success
        LD R3, STACK_START
        LD R6, STACK_TOP
;
; check for underflow (when stack is empty)
; STACK_TOP = STACK_START
        NOT R3, R3
        ADD R3, R3, #1
        ADD R3, R3, R6
        BRz UNDERFLOW ; stack is empty, nothing to pop
;
; remove value from the stack
;
        ADD R6, R6, #1 ; move top of the stack
        LDR R0, R6, #0 ; read value from the stack
        ST R6, STACK_TOP ; store top of stack pointer
        BRnzp DONE_POP
;
; indicate the underflow condition on return
;
UNDERFLOW ADD R5, R5, #1
;
; restore modified registers and return
;
DONE_POP:
        LD R3, POP_SaveR3
        LD R6, POP_SaveR6
        RET


POP_SaveR3 .BLKW #1
POP_SaveR6 .BLKW #1

STACK_START .FILL x4000
STACK_END   .FILL x3FF0
STACK_TOP   .FILL x4000
