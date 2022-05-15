;========================
; Main Program
;========================
.ORIG x3000
    ; Set R1 to 5
    AND R0, R0, #0
    ADD R0, R0, #5
    
    ; Call the factorial subroutine
    LD R5, FACT_SUB_ADDR
    JSRR R5
    
    HALT
;========================
; Local Data
;========================
FACT_SUB_ADDR   .FILL x3100

.END

;========================
; FACT Subroutine
;========================
.ORIG x3100
FACT ST R1, Save1_3100

     ADD R1, R0, #-1
     BRz DONE
     ADD R1, R0, #0
     ADD R0, R1, #-1
     JSR FACT
     LD R5, MUL_ADDR
     JSRR R5

DONE LD R1, Save1_3100
     RET
      
MUL_ADDR .FILL x3200

Save1_3100 .BLKW 1
.END

;========================
; MUL Subroutine
;========================
.ORIG x3200
MUL   ST R2, Save2_3200

      ADD R2, R0, #0
      AND R0, R0, #0
      
LOOP  ADD R0, R0, R1
      ADD R2, R2, #-1
      BRp LOOP
      
      LD R2, Save2_3200
      RET
      
Save2_3200 .BLKW 1
.END


;Ex 1. Q1. What happens when you run this code?
;A1. The program gets stuck in an infinite loop

;Ex 1. Q2. What are the values in registers R0 and R1?
;A2. R0 = x0005; R1 = x0000

;Ex 1. Q3. What are the values in registers R0 and R1 after pressing play, but before pressing any other buttons?
;A3. R0 = x0004; R1 = x0005

;Ex 1. Q4 Write the values of registers R0 and R1 for each iteration of the recursion until the recursion stops. You’ll know the recursion stops when the program is on the instruction in 
;address x3108, which corresponds to the DONE label.
;A4.    R0       R1
;       5        0
;       4        5
;       3        4
;       2        3
;       1        2

;EX 1. Q5. What is the value of R7 before you execute the RET instruction?
;A5. x3106

;EX 1. Q6. What is the value of R7 every time you get to return after the first time? (Don’t worry if you miss it the first time, it will be the same forever)
;A6. x3108