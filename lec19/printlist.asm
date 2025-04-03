;; Originally developed by Prof. Y. Chen 

.ORIG x3000

MAIN
  LD R5, RSTACK
  LD R6, RSTACK
  LD R0, HEAD
  STR R0, R6, #0 ; push argument onto stack
  ADD R6, R6, #-1
  JSR PRINT_LIST
  ADD R6, R6, #2 ; caller teardown (pop retval & args)
  HALT

PRINT_LIST
;;Part 1 - callee build up 
  ADD R6, R6, #-1    ;make space for return value
  STR R7, R6, #0	  ;push return addr to stack
  ADD R6, R6, #-1
  STR R5, R6, #0	 ;push caller frame pointer 
  ADD R5, R6, #-1	 ;set new frame pointer
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
  ADD R6, R6, #-1
  JSR PRINT_LIST
  ADD R6, R6, #2	; caller stack tear down

;skip here if head is null
;;Part 3 - callee tear down (preparing to return)
TEAR_DOWN
  LDR R5, R6, #0	;Restore old frame pointer
  ADD R6, R6, #1
  LDR R7, R6, #0	;Restore return address
  ADD R6, R6, #1
RET


HEAD .FILL x4000
RSTACK .FILL x7000

.END

.ORIG x4000
.FILL 69
.FILL x4002
.FILL 67
.FILL x4004
.FILL 69
.FILL x4006
.FILL 50
.FILL x4008
.FILL 50
.FILL x400A
.FILL 48
.FILL 0
.END 


