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

LD R5, condition
LD r4, DATA_PTR
do_while
    LD R5, condition
    GETC
    OUT
    STR R0, r4, #0
    add r4, r4, #1
    ADD r1, r0, r5
    brnp do_while

LD R5, condition
LD r4, data_ptr
LD R0, newline
OUT

print_while
    LD R5, condition
    LDR R0, r4, #0
    ADD R1, R0, R5
    BRZ SKIP_LOOP
    OUT
    add r4, r4, #1
    brnzp print_while
    
SKIP_LOOP
halt
DATA_PTR .fill x4000
newline .STRINGZ "\n"
condition .fill #-35
; comparechar .fill x40
; i .fill #0
.end
