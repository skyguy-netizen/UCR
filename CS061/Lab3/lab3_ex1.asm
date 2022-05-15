;=================================================
; Name: Aarav Sane
; Email: asane003@ucr.edu
; 
; Lab: lab 3, ex 1
; Lab section: 21
; TA: Sarthak Jain
; 
;=================================================

.orig x3000

LD r5, DATA_PTR

LDR r1, r5, #0
LDR r2, r5, #1

add r1, r1, #1
add r2, r2, #1

STR r1, r5, #0
STR r2, r5, #1


halt
DATA_PTR .fill x4000
.end
.orig x4000
new_dec .fill #65
new_hex .fill x41

.end
