.ORIG x3000
LD R0, N1 ; Load base
LD R1, N2 ; Load exponent
JSR POW
HALT 


N1 .FILL x003
N2 .FILL x004
MulSaveR0 .BLKW 1
MulSaveR1 .BLKW 1
PowSaveR0 .BLKW 1
PowSaveR1 .BLKW 1
PowSaveR2 .BLKW 1
PowSaveR7 .BLKW 1
.END

