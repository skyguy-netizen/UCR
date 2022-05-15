;========================
; Main Program
;========================
.ORIG x3000
     
      LD R6, STACK_ADDR
      AND R0, R0, #0
      ADD R0, R0, #5
      
      LD R5, FACT_ADDR
      JSRR R5
      
      HALT
      
;========================
; Local Data
;========================
FACT_ADDR .FILL x3100
STACK_ADDR .FILL xFE00
.END

;========================
; FACT Subroutine
;========================
.ORIG x3100
FACT
ADD R6, R6, #-1
STR R1, R6, #0
ADD R6, R6, #-1
STR R7, R6, #0

     ADD R1, R0, #-1
     BRz DONE
     ADD R1, R0, #0
     ADD R0, R1, #-1
     JSR FACT
     LD R5, MUL_ADDR
     JSRR R5

DONE LDR R7, R6, #0
     ADD R6, R6, #1
     LDR R1, R6, #0
     ADD R6, R6, #1
     RET
      
MUL_ADDR .FILL x3200
.END

;========================
; MUL Subroutine
;========================
.ORIG x3200
MUL   
ADD R6, R6, #-1
STR R2, R6, #0
ADD R6, R6, #-1
STR R7, R6, #0

      ADD R2, R0, #0
      AND R0, R0, #0
      
LOOP  ADD R0, R0, R1
      ADD R2, R2, #-1
      BRp LOOP
      
      LDR R7, R6, #0
      ADD R6, R6, #1
      LDR R2, R6, #0
      ADD R6, R6, #1
      RET
      
.END

; Ex 3. Q1. Which register holds the result of calling the FACT subroutine?
; A1. R0

; Ex 3. Q2. What value is stored in this register?
; A2. 120

; Ex 3. Q3. Is this the correct value for 5!?
; A3. Yes