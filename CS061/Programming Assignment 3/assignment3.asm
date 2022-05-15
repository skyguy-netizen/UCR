;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Aarav Sane
; Email: asane003@ucr.edu
; 
; Assignment name: Assignment 3
; Lab section: 21
; TA: Sarthak Jain
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=========================================================================

.ORIG x3000			; Program begins here
;-------------
;Instructions
;-------------
LD R6, Value_ptr		; R6 <-- pointer to value to be displayed as binary
LDR R1, R6, #0			; R1 <-- value to be displayed as binary 
;-------------------------------
;INSERT CODE STARTING FROM HERE
;--------------------------------

LD R7, counter
LD R4, spaceCounter

LDR R0, R6, #0

do_while_loop
    add R1, R1, #0
    brn output_1
    LD R0, value0
    OUT
    continue
    add R1, R1, R1
    add R7, R7, #-1
    brn exit
    add R4, R4, #-1
    brnz outputSpace
    continue2
    brnzp do_while_loop
    
output_1
    LD R0, value1
    OUT
    brnzp continue

outputSpace
    LD R4, spaceCounter
    LD R0, space
    OUT
    brnzp continue2
    
exit
LD R0, newline
OUT

HALT
;---------------	
;Data
;---------------
Value_ptr	.FILL xCA01	; The address where value to be displayed is stored
counter .FILL xF
value1 .fill x31
value0 .fill x30
spaceCounter .fill #4
newline .fill xA
space .fill x20

.END

.ORIG xCA01					; Remote data
Value .FILL xABCD			; <----!!!NUMBER TO BE DISPLAYED AS BINARY!!! Note: label is redundant.
;---------------	
;END of PROGRAM
;---------------	
.END
