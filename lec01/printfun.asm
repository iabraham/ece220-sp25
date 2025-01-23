.ORIG x3000
; Load start address of string

; Set up loop to load char into R0
CHRLOOP LDR R0, R2, #0

;Break if all done

;Loop to poll display until ready

;Store value in R0 to DDR 

;Move onto next char

BRnzp CHRLOOP

DSR .FILL xFE04
DDR .FILL xFE06

MY_STRING .STRINGZ "ECE 220 IS FUN"
.END

