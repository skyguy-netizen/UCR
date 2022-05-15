;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Aarav Sane
; Email: asane003@ucr.edu
; 
; Assignment name: Assignment 2
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

;----------------------------------------------
;output prompt
;----------------------------------------------	
LEA R0, intro			; get starting address of prompt string
PUTS			    	; Invokes BIOS routine to output string

;-------------------------------
;INSERT YOUR CODE here
;--------------------------------
;First input
GETC
OUT
ADD R1, R0, #0

;New Line
LD R0, newline
OUT

;Second Input
GETC
OUT
ADD R2, R0, #0

;New Line
LD R0, newline
OUT

;Final expression to console
LD R0, x0
ADD R0, R1, #0
OUT
LEA R0, hyphen_with_space
PUTS
LD R0, x0
ADD R0, R2, #0
OUT
LEA R0, equal_to_with_space
PUTS
LD R0, #0

;Converting ASCII character to numeric value and outputing difference
LD R4, HEX_30
NOT R4, R4
ADD R4,R4, #1
LD R0, #0
ADD R1, R1, R4
ADD R2, R2, R4

;This is needed to convert R6 back into required character so TRAP function OUT can print to console
NOT R4, R4
ADD R4,R4, #1

;To get the negative of value stored in R2
NOT R2, R2
ADD R2, R2, #1

;STORE in another register
ADD R6, R1, R2

;SPECIAL_CASE
BRzp SKIP_SPECIAL_CASE_CODE
    ;Convert R6 value into positive
    NOT R6, R6
    ADD R6, R6, #1
    
    ;Convert according to ASCII Table
    ADD R6, R6, R4
    
    ;Print negative number
    LD R0, hyphen ;x2D refers to '-'
    OUT
    LD R0, #0
    ADD R0, R6, #0
    OUT
    LD R0, newline
    OUT
    HALT

SKIP_SPECIAL_CASE_CODE
ADD R6, R6, R4
ADD R0, R6, #0
OUT
LD R0, newline
OUT



HALT				; Stop execution of program
;------	
;Data
;------
; String to prompt user. Note: already includes terminating newline!
intro 	.STRINGZ	"ENTER two numbers (i.e '0'....'9')\n" 		; prompt string - use with LEA, followed by PUTS.
newline .FILL x0A	; newline character - use with LD followed by OUT
HEX_30 .FILL x30
hyphen_with_space .STRINGZ " - "
equal_to_with_space .STRINGZ " = "
hyphen .FILL x2D

;---------------	
;END of PROGRAM
;---------------	
.END

