.ORIG x3000
; Load start address of string
LEA R2, MY_STRING

; Set up loop to load char into R0
CHRLOOP LDR R0, R2, #0

;Break if all done
BRz ALLDONE

;Loop to poll display until ready
DPOLL 
	LDI R1, DSR
	BRzp DPOLL
;Store value in R0 to DDR 
STI R0, DDR

;Move onto next char
ADD R2, R2, #1

BRnzp CHRLOOP

ALLDONE HALT

DSR .FILL xFE04
DDR .FILL xFE06

MY_STRING .STRINGZ "ECE 220 IS FUN"
.END

