.ORIG x3000
; R0 - output, init to 0
; R1 - multiplicand 1, init to 5
; R2 - loop counter, init to multiplicand 2

AND R0, R0, #0
AND R1, R1, #0
AND R2, R2, #0

ADD R1, R1, #5
ADD R2, R2, #4

LOOP BRz DONE
    ADD R0, R0, R1
    ADD R2, R2, #-1
    BR LOOP

DONE HALT
.END

