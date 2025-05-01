.ORIG   x3000
        LEA     R0, ISR_KB
        STI     R0, KBINTV  ; load ISR address to INTV
        LD      R3, EN_IE
        STI     R3, KBSR    ; set IE bit of KBSR
AGAIN   LD      R0, NUM2
        OUT
        BRnzp   AGAIN
ISR_KB  ST      R0, SaveR0  ; callee-save R0
        LDI     R0, KBDR    ; read a char from KB and clear ready bit
        OUT
        LD      R0, SaveR0  ; callee-restore R0
        HALT
;
EN_IE   .FILL   x4000 ; To enable the IE bit
NUM2    .FILL   x0032 ; ASCII Code for ‘2’
KBSR    .FILL   xFE00
KBDR    .FILL   xFE02
KBINTV  .FILL   x0180 ; INT vector table address for keyboard
SaveR0  .BLKW   #1
.END