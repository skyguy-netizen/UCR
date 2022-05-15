;========================
; Main Program
;========================
.ORIG x3000

      AND R0, R0, #0
      ADD R0, R0, #5
      
      LD R5, FACT_ADDR
      JSRR R5
      
      HALT
      
;========================
; Local Data
;========================
FACT_ADDR .FILL x3100
.END

;========================
; FACT Subroutine
;========================
.ORIG x3100
FACT ST R1, Save1_3100
     ST R7, Save7_3100

     ADD R1, R0, #-1
     BRz DONE
     ADD R1, R0, #0
     ADD R0, R1, #-1
     JSR FACT
     LD R5, MUL_ADDR
     JSRR R5

DONE LD R1, Save1_3100
     LD R7, Save7_3100
     RET
      
MUL_ADDR .FILL x3200

Save1_3100 .BLKW 1
Save7_3100 .BLKW 1
.END

;========================
; MUL Subroutine
;========================
.ORIG x3200
MUL   ST R2, Save2_3200
      ST R7, Save7_3200

      ADD R2, R0, #0
      AND R0, R0, #0
      
LOOP  ADD R0, R0, R1
      ADD R2, R2, #-1
      BRp LOOP
      
      LD R2, Save2_3200
      LD R7, Save7_3200
      RET
      
Save2_3200 .BLKW 1
Save7_3200 .BLKW 1
.END

; Ex 2. Q 1. What happens this time when you run the code?
;A2. Program stuck in infinite loop

; Ex 2. Q2. What are the values in registers R0 and R1?
; A2. R0 = x0005, R1 = x0000

; Ex 2. Q3. What are the values in registers R0 and R1 after pressing play, but before pressing any other buttons?
; A3. R0 = x0004, R1 = x0005

; EX 2. Q4. What is the value of R7 before you execute the RET instruction?
; A4. x3107

; EX 2. Q5. Will this program ever finish, or does it just keep going?
; A5. The program will just keep going (overwriting R7 with the value where the recursive subroutine was
; called in the subroutine itself)