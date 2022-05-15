;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Aarav Sane
; Email: asane003@ucr.edu
;
; Assignment name: Assignment 1
; Lab section: 21
; TA: Sarthak Jain
;
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=========================================================================

;------------------------------------------
;           BUILD TABLE HERE
;------------------------------------------
;REG VALUES         R0     R1       R2     R3     R4     R5     R6     R7

;PRE LOOP           0      12       6      0      0      0      0      0
;ITERATION 1        0      12       5      12     0      0      0      0
;ITERATION 2        0      12       4      24     0      0      0      0
;ITERATION 3        0      12       3      36     0      0      0      0
;ITERATION 4        0      12       2      48     0      0      0      0
;ITERATION 5        0      12       1      60     0      0      0      0
;END OF PROGRAM     0      32767    0      72     0      0      12286  0
;
;
;
;



.ORIG x3000			; Program begins here
;-------------
;Instructions: CODE GOES HERE
;-------------
AND R3,R3, x0
LD R2, DEC_6
LD R1, DEC_12

DO_WHILE
    ADD R3, R3, R1
    ADD R2, R2, #-1
    BRp DO_WHILE
END_DO_WHILE


HALT
;---------------
;Data (.FILL, .STRINGZ, .BLKW)
;---------------
DEC_6 .FILL #6
DEC_12 .FILL #12



;---------------
;END of PROGRAM
;---------------
.END
