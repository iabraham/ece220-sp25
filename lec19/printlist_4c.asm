; Original modified by itabrah2. 
; Compare this file to printlist.asm. Here callee 
; buildup and teardown are done in four instructions

.ORIG x3000

MAIN
  LD R5, RSTACK
  LD R6, RSTACK
  LD R0, HEAD
  STR R0, R6, #0 ; push argument onto stack
  JSR PRINT_LIST
  ADD R6, R6, #2 ; caller teardown (pop retval & args)
  HALT

PRINT_LIST
;;Part 1 - callee build up 
  STR R7, R6, #-2           ; Skip RV space, save RA
  STR R5, R6, #-3           ; Save CFP 
  ADD R6, R6, #-3           ; Make space for nLocals local vars
  ADD R5, R6, #-1           ; Set new frame pointer 
;
;;Part 2 - implement function logic
;
;if(cursor == NULL) skip to the end;
  LDR R1, R5, #4	;load head to R1
  BRz TEAR_DOWN     ;if head null, nothing to do
;
;else printf("%c", cursor->symbol);
  LDR R0, R1, #0	;load cursor->symbol to R0
  OUT
  
  ;print_list(head->next);
  LDR R1, R1, #1	;load head->next to R1
  ADD R6, R6, #-1
  STR R1, R6, #0	;push head->next to the stack
  JSR PRINT_LIST
  ADD R6, R6, #2	; caller stack tear down

;skip here if head is null
;;Part 3 - callee tear down (preparing to return)
TEAR_DOWN
  ADD R6, R5, #3   ; Pop locals & set R6 to RV 
  LDR R5, R6, #-2  ; Restore CFP 
  LDR R7, R6, #-1  ; Restore return address
  RET 


HEAD .FILL x4004
RSTACK .FILL x7000

.END

.ORIG x4004
.FILL 69
.FILL x4006
.FILL 67
.FILL x4008
.FILL 69
.FILL x400A
.FILL 50
.FILL x400C
.FILL 50
.FILL x400E
.FILL 48
.FILL 0
.END 


