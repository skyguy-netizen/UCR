;=================================================
; Name: Aarav Sane
; Email:  asane003@ucr.edu
; 
; Lab: lab 2, ex 4
; Lab section: 21
; TA: Sarthak Jain
; 
;=================================================


.orig x3000

LD R0, HEX_x61
LD R1, HEX_x1A

DO_WHILE
    OUT
    add R0, R0, x1
    add R1, R1, x-1
    BRp DO_WHILE
END_DO_WHILE

HALT

HEX_x61 .FILL x61
HEX_x1A .FILL x1A
 
.END