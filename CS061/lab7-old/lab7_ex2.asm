;=================================================
; Name: Aarav San
; Email: asane003@ucr.edu
; 
; Lab: lab 7, ex 1
; Lab section: 21
; TA: Sarthak Jain
; 
;=================================================

; test harness
.orig x3000
	AND R0, R0, #0
	ADD R0, R0, #5
	
	LD R5, FACT_ADDR
	JSRR R5
				 
				 
halt
;-----------------------------------------------------------------------------------------------
; test harness local data:
FACT_ADDR .FILL X3100




;===============================================================================================
.end

; subroutines:
.ORIG X3100

FACT ST R1, SAVE1_3100
     ST R7, SAVE7_3100
     
    ADD R1, R0, #-1
    Brz DONE
    ADD R1, R0, #0
    ADD R0, R1, #-1
    JSR FACT
    LD R5, MUL_ADDR
    JSRR R5

DONE LD R1, SAVE1_3100
     LD R7, SAVE7_3100
    RET
    
MUL_ADDR .FILL x3200

SAVE1_3100 .BLKW 1
SAVE7_3100 .BLKW 1
.END

.ORIG x3200
MUL ST R2, SAVE2_3200
    ST R7, SAVE7_3200
    ADD R2, R0, #0
    AND R0, R0, #0

LOOP ADD R0, R0, R1
     ADD R2, R2, #-1
     BRp LOOP
     
     LD R2, SAVE2_3200
     LD R7, SAVE7_3200
     RET

SAVE2_3200 .BLKW 1
SAVE7_3200 .BLKW 1
.END


