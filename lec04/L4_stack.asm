.ORIG x3000

; Author: ywchen?

; Program will add OP_1 with (OP_1 + 3) while doing range check. 

LD R6, STACK_TOP	;STACK_TOP points to x4000 at the beginning

LD R0, OP_1		    ;load operand 1
JSR PUSH		      ;push operand 1 to stack
LD R6, STACK_TOP	;check STACK_TOP pointer
ADD R5, R5, #0
BRp DONE_MAIN		  ;done if overflow

ADD R0, R0, #3		;increment operand 1 by 3
JSR PUSH		      ;push new value to stack
LD R6, STACK_TOP	;check STACK_TOP pointer 
ADD R5, R5, #0
BRp DONE_MAIN		  ;done if overflow

JSR ADD_OP		    ;call ADD_OP subroutine
ADD R5, R5, #0
BRp DONE_MAIN		   ;done if overflow

JSR POP			      ;pop result to store in R0
LD R6, STACK_TOP	;check STACK_TOP pointer

DONE_MAIN
HALT


; PUSH subroutine
; IN: R0 (value)
; OUT: R5 (0 – success, 1 – fail)
; R3: STACK_END
; R6: STACK_TOP 
;
PUSH
;
; save registers that will be modified in PUSH subroutine
;
	ST R3, PUSH_SaveR3 ; save R3
	ST R6, PUSH_SaveR6 ; save R6
	AND R5, R5, #0 ; clear R5, indicates success
	LD R3, STACK_END
	LD R6, STACK_TOP
;
; check for overflow (when stack is full)
; STACK_TOP < STACK_END (STACK_TOP = STACK_END - 1)
	ADD R3, R3, #-1
	NOT R3, R3
	ADD R3, R3, #1
	ADD R3, R3, R6
	BRz OVERFLOW ; stack is full
;
; store value in the stack
;
	STR R0, R6, #0 ; push onto the stack
	ADD R6, R6, #-1 ; move top of the stack
	ST R6, STACK_TOP ; store top of stack pointer
	BRnzp DONE_PUSH
;
; indicate the overflow condition on return
;
OVERFLOW ADD R5, R5, #1
;
; restore modified registers and return
;
DONE_PUSH
	LD R3, PUSH_SaveR3
	LD R6, PUSH_SaveR6
	RET


; POP Subroutine
; OUT: R0 (value)
; OUT: R5 (0 – success, 1 – fail)
; R3: STACK_START
; R6: STACK_TOP
;
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
DONE_POP
	LD R3, POP_SaveR3
	LD R6, POP_SaveR6
	RET


; ADD subroutine – pop two numbers from stack, 
; perform ‘+’ operation and then push result back to the stack

; <<========== FILL IN CODE FROM OTHER FILE HERE





; CHECK_RANGE - check whether value is greater than x0064 or smaller than xFF9C
; Input: R0 (value to be checked) 
; Output: R5 (0 – success, 1 – fail)
CHECK_RANGE	ST R1, CHECK_SAVER1
		AND R5, R5, #0
		LD R1, RANGE_POSITIVE
		ADD R1, R0, R1
		BRn OUT_OF_RANGE
		LD R1, RANGE_NEGATIVE
		ADD R1, R0, R1
		BRp OUT_OF_RANGE
		RET
OUT_OF_RANGE	ADD R5, R5, #1
		RET


PUSH_SaveR3 .BLKW #1
PUSH_SaveR6 .BLKW #1

POP_SaveR3 .BLKW #1
POP_SaveR6 .BLKW #1

ADD_SAVER7 .BLKW #1
ADD_SAVER0 .BLKW #1
ADD_SAVER1 .BLKW #1
ADD_SAVER6 .BLKW #1
ADD_SAVER5 .BLKW #1


CHECK_SAVER1
RANGE_POSITIVE	.FILL x0064 ;decimal 100
RANGE_NEGATIVE	.FILL xFF9C ;decimal -100

STACK_START .FILL x4000
STACK_END   .FILL x3FF0
STACK_TOP   .FILL x4000

OP_1	.FILL x0020	;set operand to 32
.END
