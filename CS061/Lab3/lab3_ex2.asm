;=================================================
; Name: Aarav Sane
; Email:  asane003@ucr.edu
;
; Lab: lab 2, ex 3
; Lab section: 21
; TA: Sarthak Jain
;
;=================================================
.orig x3000

LEA r4, DATA_PTR
LD r6, counter

do_while
    GETC
    OUT
    STR R0, R4, #0
    add r4, r4, #1
    add r6, r6, #-1
    brp do_while
    

halt
DATA_PTR .blkw #10
counter .fill #10
; i .fill #0
.end
