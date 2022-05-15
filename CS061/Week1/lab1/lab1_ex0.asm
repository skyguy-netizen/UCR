;=================================================
; Name: Aarav Sane
; Email: asane003@ucr.edu
; 
; Lab: lab 1, ex 0
; Lab section: 21
; TA: Sarthak Jain
; 
;=================================================
.orig x3000

LEA R0, message ;LEA loads the address of LABEL message to R0 (which is a register)

PUTS ;Puts value of message to print

HALT ;terminate program

message .STRINGZ "hello world!" ;puts value into label

.end