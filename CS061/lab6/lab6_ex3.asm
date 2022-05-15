;=================================================
; Name: Aarav Sane
; Email: asane003@ucr.edu
;
; Lab: lab 6, ex 3
; Lab section: 21
; TA: Sarthak Jain
;
;=================================================

; test harness
.orig x3000

LD R5, MAX
LD R6, TOS
LD R4, BASE
LD R1, SUB_STACK_PUSH_X3200
LD R3, stacktobackup

LEA R0, prompt1
PUTS
GETC
OUT

;newline
ADD R1, R0, #0
LD R0, newline
OUT
ADD R0, R1, #0

;push value onto stack
LD R1, SUB_STACK_PUSH_X3200
JSRR R1

LEA R0, prompt2
PUTS
GETC
OUT

;push second value onto stack
LD R1, SUB_STACK_PUSH_X3200
JSRR R1

LD R0, newline
OUT

LEA R0, operation
PUTS
GETC
OUT
JSRR R1
LD R1, SUB_STACK_POP_X3400
JSRR R1

;multiply values and return in R0
LD R1, SUB_RPN_MULTIPLY_X4600
JSRR R1

ADD R1, R0, #0

LD R0, newline
OUT
LEA R0, muldone
PUTS

ADD R0, R1, #0
Add R0, R0, #8
Add R0, R0, #8
Add R0, R0, #8
Add R0, R0, #8
Add R0, R0, #8
Add R0, R0, #8
OUT




halt
;-----------------------------------------------------------------------------------------------
; test harness local data:

BASE .FILL xA000
MAX .FILL xA005
TOS .FILL xA000
SUB_STACK_PUSH_X3200 .FILL x3200
SUB_STACK_POP_X3400 .FILL x3400
SUB_RPN_MULTIPLY_X4600 .FILL x3600
prompt1 .STRINGZ "Enter one digit number: "
prompt2 .stringz "Enter second digit:  "
muldone .stringz "After multiplying: "
operation .stringz "Enter operation to perform: "
newline .fill xA
stacktobackup .fill xFE00


;===============================================================================================
.end

; subroutines:

;------------------------------------------------------------------------------------------
; Subroutine: SUB_STACK_PUSH
; Parameter (R0): The value to push onto the stack
; Parameter (R4): BASE: A pointer to the base (one less than the lowest available
;                       address) of the stack
; Parameter (R5): MAX: The "highest" available address in the stack
; Parameter (R6): TOS (Top of Stack): A pointer to the current top of the stack
; Postcondition: The subroutine has pushed (R0) onto the stack (i.e to address TOS+1).
;		    If the stack was already full (TOS = MAX), the subroutine has printed an
;		    overflow error message and terminated.
; Return Value: R6 ← updated TOS
;------------------------------------------------------------------------------------------
.orig x3200
    
    add r3, r3, #-1
    STr R7, r3, #0

    NOT R2, R6
    ADD R2, R2, #1
    ADD R2, R2, R5
    BRZ EXIT_PUSH
    ADD R6, R6, #1
    STR R0, R6, #0
    ldr r7, r3, #0
	add r3, r3, #1
    ret

	EXIT_PUSH
	LEA R0, OVERFLOW_ERROR
	PUTS

	
	ldr r7, r3, #0
	add r3, r3, #1
	

    ret
;-----------------------------------------------------------------------------------------------
; SUB_STACK_PUSH local data
OVERFLOW_ERROR .STRINGZ "OVERFLOW ERROR OCCURED"
backupR7push .fill x0

;===============================================================================================
.end

;------------------------------------------------------------------------------------------
; Subroutine: SUB_STACK_POP
; Parameter (R4): BASE: A pointer to the base (one less than the lowest available
;                       address) of the stack
; Parameter (R5): MAX: The "highest" available address in the stack
; Parameter (R6): TOS (Top of Stack): A pointer to the current top of the stack
; Postcondition: The subroutine has popped MEM[TOS] off of the stack.
;		    If the stack was already empty (TOS = BASE), the subroutine has printed
;                an underflow error message and terminated.
; Return Value: R0 ← value popped off the stack
;		   R6 ← updated TOS
;------------------------------------------------------------------------------------------
.orig x3400

    add r3, r3, #-1
    STr R7, r3, #0

    NOT R2, R6
    ADD R2, R2, #1
    ADD R2, R2, R4
    BRZ EXIT_POP
    LDR R0, R6, #0
    add R6, R6, #-1
    ldr r7, r3, #0
	add r3, r3, #1
    ret

	EXIT_POP
	LEA R0, UNDERFLOW_ERROR
	PUTS
    
	ldr r7, r3, #0
	add r3, r3, #1

    ret

;-----------------------------------------------------------------------------------------------
; SUB_STACK_POP local data
UNDERFLOW_ERROR .STRINGZ "UNDERFLOW ERROR OCCURED"
backupR7pop .fill x0
backupTop .fill x0

;===============================================================================================
.end

;------------------------------------------------------------------------------------------
; Subroutine: SUB_RPN_ADD
; Parameter (R4): BASE: A pointer to the base (one less than the lowest available
;                       address) of the stack
; Parameter (R5): MAX: The "highest" available address in the stack
; Parameter (R6): TOS (Top of Stack): A pointer to the current top of the stack
; Postcondition: The subroutine has popped off the top two values of the stack,
;		    added them together, and pushed the resulting value back
;		    onto the stack.
; Return Value: R6 ← updated TOS address
;------------------------------------------------------------------------------------------
.orig x3600
	 
    add r3, r3, #-1
    STr R7, r3, #0

LD R1, SUB_STACK_POP_SUB
JSRR R1

Add R0, R0, #-8
Add R0, R0, #-8
Add R0, R0, #-8
Add R0, R0, #-8
Add R0, R0, #-8
Add R0, R0, #-8

st R0, backupR0mul
JSRR R1

Add R0, R0, #-8
Add R0, R0, #-8
Add R0, R0, #-8
Add R0, R0, #-8
Add R0, R0, #-8
Add R0, R0, #-8

ADD R1, R0, #0

ld R2, backupR0mul
add R2, R2, #-1

multiply
    add R0, R0, R1
    add R2, R2, #-1
    brp multiply


    LD R1, SUB_STACK_PUSH_SUB
    JSRR R1

    ldr r7, r3, #0
	add r3, r3, #1
				 
				 
ret
;-----------------------------------------------------------------------------------------------
; SUB_RPN_MULTIPLY local data
backupR7mul .fill x0
SUB_STACK_POP_SUB .fill x3400
backupR0mul .fill x0
SUB_STACK_PUSH_SUB .fill x3200
converter .fill x30

;===============================================================================================
.end


; SUB_ADDED		

; SUB_GET_NUM		

; SUB_PRINT_DIGIT		Only needs to be able to print 1 digit numbers. 



