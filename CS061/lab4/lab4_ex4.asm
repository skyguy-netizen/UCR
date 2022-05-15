;=================================================
; Name: Aarav Sane
; Email: asane003@ucr.edu
; 
; Lab: lab 4, ex 1
; Lab section: 21
; TA: Sarthak Jain
; 
;=================================================
.orig x3000
LD R0, othpower
LD R3, arr_ptr
LD R1, counter
LD R7, converter
; STR R0, R3, #0
; ADD R0, R0, #1
; STR R0, R3, #0
do_while_loop
    STR R0, R3, #0
    add R0, R0, R0
    add R3, R3, #1
    add R1, R1, #-1
    brp do_while_loop
    
LD R3, arr_ptr
add r3, r3, #6
LDR R2, R3, #0

LD R3, arr_ptr
LD R1, counter
LD R7, converter
output_loop
    LDR R0, R3, #0
    ADD R0, R0, R7
    OUT
    ADD R3, R3, #1
    ADD R1, R1, #-1
    brp output_loop
    
    


HALT
arr_ptr .fill x4000
counter .fill #10
converter .fill x30
othpower .fill x1
.end

.orig x4000
new_arr .blkw #10
halt
.end