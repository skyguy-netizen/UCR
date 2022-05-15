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
AND R0, R0, #0
LD R3, arr_ptr
LD R1, counter
; STR R0, R3, #0
; ADD R0, R0, #1
; STR R0, R3, #0
do_while_loop
    STR R0, R3, #0
    add R0, R0, #1
    add R3, R3, #1
    add R1, R1, #-1
    brp do_while_loop

LD R3, arr_ptr
add R3, R3, #6
LDR R2, R3, #0

HALT
arr_ptr .fill x4000
counter .fill #10
.end

.orig x4000
new_arr .blkw #10
halt
.end