.ORIG x3000
LD R0, N1 ; Load base
LD R1, N2 ; Load exponent
JSR POW
HALT 

; LC3 subroutine to multiply two numbers
; Inputs: R0 (multiplicand), R1 (multiplier)
; Output:  R2 (result)

MULTIPLY:
    ST R0, MulSaveR0        ; Callee save registers
    ST R1, MulSaveR1       
    AND R2, R2, #0          ; Clear R2 to be used as result
    ADD R2, R0, #0          ; Load multiplicand into R2
    ADD R1, R1, #-1         ; Use R1 as counter
   
MUL_LOOP:
    BRz MUL_DONE            ; If R1 == 0, multiplication done
    ADD R2, R0, R2
    ADD R1, R1, #-1         ; Decrement the counter in R1
    BR MUL_LOOP             ; Jump back to MUL_LOOP

MUL_DONE:
    LD R0, MulSaveR0        ; Restore registers
    LD R1, MulSaveR1
    RET                     ; Return from the subroutine

; LC3 subroutine to that performs exponentiation
; Inputs: R0 (base), R1 (exponent)
; Loop counter: R2
; Output: R2 (result)
; POW knows it should call MULTIPLY and it knows
; MULTIPLY overwrites the value in R2

POW: 
    ST R0, PowSaveR0    ; Callee save registers
    ST R1, PowSaveR1
    ADD R2, R1, #-1     ; Initialize counter
                        ; Why can't we use R1 as counter?
    ADD R1, R0, #0      ; Set up to call MULTIPLY
    
POW_LOOP:
    BRz POW_DONE        ; If R2==0, loop complete
    ST R2, PowSaveR2    ; Caller save
    ST R7, PowSaveR7
    JSR MULTIPLY        ; Result in R2
    LD R7, PowSaveR7
    ADD R1, R2, #0      ; Copy result for JSR to multiply
    LD R2, PowSaveR2    ; Caller restore
    ADD R2, R2, #-1     ; Decrement counter 
    BR POW_LOOP
    
POW_DONE:
    ADD R2, R1, #0      ; Move result to R2
    LD R0, PowSaveR0    ; Callee restore
    LD R1, PowSaveR1
    RET

N1 .FILL x003
N2 .FILL x004
MulSaveR0 .BLKW 1
MulSaveR1 .BLKW 1
PowSaveR0 .BLKW 1
PowSaveR1 .BLKW 1
PowSaveR2 .BLKW 1
PowSaveR7 .BLKW 1
.END

