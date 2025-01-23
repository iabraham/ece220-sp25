.ORIG x3000
KPOLL  LDI     R1, KBSR
       BRzp    KPOLL
       LDI     R0, KBDR



DPOLL  LDI     R1, DSR
       BRzp    DPOLL
       STI     R0, DDR


       BRnzp   NEXT_TASK
       
NEXT_TASk HALT

KBSR   .FILL   xFE00
KBDR   .FILL   xFE02
DSR    .FILL   xFE04
DDR    .FILL   xFE06
.END

