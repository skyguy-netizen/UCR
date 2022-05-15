;=================================================
; Name: Aarav Sane
; Email: asane003@ucr.edu
;
; Lab: lab 6, ex 1 & 2
; Lab section: 21
; TA: Sarthak Jain
;
;=================================================

; test harness
.orig x3000

LD R5, MAX
LD R6, TOS
LD R4, BASE

;putting 5 values to test overflow error
LD R0, testval1
LD R1, SUB_STACK_PUSH_X3200
JSRR R1

LD R0, testval2
JSRR R1

LD R0, testval3
JSRR R1

LD R0, testval4
JSRR R1

LD R0, testval5
JSRR R1

;getting user input, but stack is full so should output overflow error
GETC
OUT

;newline output
ADD R3, R0, #0
LD R0, newline
OUT
ADD R0, R3, #0

JSRR R1

;popping element off of stack so that user can enter their input
LD R3, SUB_STACK_POP_X3400
JSRR R3

LD R0, newline
OUT

GETC
OUT

ADD R3, R0, #0
LD R0, newline
OUT
ADD R0, R3, #0

JSRR R1

LD R0, newline
OUT
;now testing underflow
LD R3, SUB_STACK_POP_X3400
JSRR R3
JSRR R3
JSRR R3
JSRR R3
JSRR R3
;called 5 times since 5 elements in stack currently
LEA R0, temp
PUTS

JSRR R3



halt
;-----------------------------------------------------------------------------------------------
; test harness local data:

BASE .FILL xA000
MAX .FILL xA005
TOS .FILL xA000
SUB_STACK_PUSH_X3200 .FILL x3200
SUB_STACK_POP_X3400 .FILL x3400
testval1 .fill #1
testval2 .fill #2
testval3 .fill #3
testval4 .fill #4
testval5 .fill #5
newline .fill xA
temp .stringz "POP already called 5 times.....calling pop one more time should result in underflow"


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
    ST R7, backupR7push

    NOT R2, R6
    ADD R2, R2, #1
    ADD R2, R2, R5
    BRZ EXIT_PUSH
    ADD R6, R6, #1
    STR R0, R6, #0
    ret

	EXIT_PUSH
	LEA R0, OVERFLOW_ERROR
	PUTS

	LD R7, backupR7push

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
	ST R7, backupR7pop

    NOT R2, R6
    ADD R2, R2, #1
    ADD R2, R2, R4
    BRZ EXIT_POP
    ADD R6, R6, #-1
    ret

	EXIT_POP
	LEA R0, UNDERFLOW_ERROR
	PUTS

	LD R7, backupR7pop

    ret




ret
;-----------------------------------------------------------------------------------------------
; SUB_STACK_POP local data
UNDERFLOW_ERROR .STRINGZ "UNDERFLOW ERROR OCCURED"
backupR7pop .fill x0

;===============================================================================================
.end
