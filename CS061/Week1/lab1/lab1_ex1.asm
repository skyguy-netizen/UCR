;=================================================
; Name: Aarav Sane
; Email:  asane003@ucr.edu
; 
; Lab: lab 1, ex 1
; Lab section: 21
; TA: Sarthak Jain
; 
;=================================================

.orig x3000

AND R1, R1, x0 
LD R2, DEC_6
LD R3, DEC_12

DO_WHILE_LOOP
    ADD R1,R1,R3 ;R1 = R1 + R3
    ADD R2,R2,#-1 ;R2 = R2 + (-1)
    BRp DO_WHILE_LOOP ;BRp checks if the last used integer is positive, jump to a line(WHILE_LOOP)
END_DO_WHILE_LOOP

HALT

DEC_0 .FILL #0
DEC_6 .FILL #6
DEC_12 .FILL #12

.END