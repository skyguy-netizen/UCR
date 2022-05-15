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

LD r5, DEC_ptr
LD r6, HEX_ptr

LDR r3, r5, #0 
LDR r4, r6, x0

add r3, r3, #1
add r4, r4, x1

STR r3, r5, #0
STR r4, r6, x0

halt
DEC_ptr .fill x4000
HEX_ptr .fill x4001
.end
.orig x4000
new_dec .fill #65
new_hex .fill x41

.end