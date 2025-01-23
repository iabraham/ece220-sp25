.ORIG x3000


AND R0, R0, #0         ;init R0
ADD R0, R0, #3         ;set R0 to 3
ADD R7, R0, #4         ;set R7 to 7
ADD R0, R0, #1         ;increment R0
ADD R7, R7, #1         ;increment R7
   
IN                     ;same as ‘TRAP x23’

ADD R0, R0, #1         ;increment R0
ADD R7, R7, #0         ;increment R7

HALT
.END
