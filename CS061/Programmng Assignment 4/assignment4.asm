;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Aarav Sane
; Email: asane003@ucr.edu
; 
; Assignment name: Assignment 4
; Lab section: 21
; TA: Sarthak Jain
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=================================================================================
;THE BINARY REPRESENTATION OF THE USER-ENTERED DECIMAL NUMBER MUST BE STORED IN R4
;=================================================================================

.ORIG x3000		
;-------------
;Instructions
;-------------

; output intro prompt

start
Ld R5, conversion
LD R0, introPromptPtr
AND R4, R4, #0

PUTS
						
; Set up flags, counters, accumulators as needed

; Get first character, test for '\n', '+', '-', digit/non-digit 
GETC
OUT



					
; is very first character = '\n'? if so, just quit (no message)!
br checking

; is it = '+'? if so, ignore it, go get digits
isPositive
br get_numbers

; is it = '-'? if so, set neg flag, go get digits
isNegative
LD r7, negativeflag
br get_numbers

; is it < '0'? if so, it is not a digit	- o/p error message, start over
errorMessage1
LD R0, newline
OUT
LD R0, errorMessagePtr
PUTS
LD R0, newline
OUT
br start

; is it > '9'? if so, it is not a digit	- o/p error message, start over
errorMessage2
LD R0, newline
OUT
LD R0, errorMessagePtr
PUTS
LD R0, newline
OUT
br start

; if none of the above, first character is first numeric digit - convert it to number & store in target register!
nosignspecified
add r0, r0, r5
add r4, r4, r0
br get_numbers_2

; Now get remaining digits from user in a loop (max 5), testing each to see if it is a digit, and build up number in accumulator
get_numbers
    LD R1, count
    do_while
        Getc
        OUT
        not r6, r0
        add r6, r6, #1
        add r2, r6, xA
        brz newline_entered
        br checking2
        continueGettingNums
        br multiplyR4by10
        end_multiply
        add r0, r0, r5
        add r4, r4, r0
        add r1, r1, #-1
        brz done
        brp do_while
    
get_numbers_2
    LD R1, count
    add R1, R1, #-1
    do_while_2
        Getc
        OUT
        not r6, r0
        add r6, r6, #1
        add r2, r6, xA
        brz newline_entered
        br checking3
        continueGettingNums_2
        br multiplyR4by10
        end_multiply_2
        add r0, r0, r5
        add r4, r4, r0
        add r1, r1, #-1
        brz done
        brp do_while_2

; remember to end with a newline!
LD R0, newline
OUT

newline_entered
done
ADD R7, R7 #0
brn negativeNumber
negChecked
halt

negativeNumber
    not r4, r4
    add r4, r4, #1
    br negChecked

checking
    not r1, r0
    add r1, r1, #1
    add r2, r1, #15 ; check for negative
    add r2, r2, #15
    add r2, r2, #15
    brz isNegative
    add r2, r1, #15 ; check for positivw
    add r2, r2, #15
    add r2, r2, #15
    add r2, r2, #-2
    brz isPositive
    add r2, r1, xA ;check for newline
    brz done
    ld r2, upperlimit
    add r2, r2, r1
    brn errorMessage2
    ld r2, lowerlimit
    add r2, r2, r1
    brp errorMessage1
    br nosignspecified

multiplyR4by10
    LD R6, multiplier
    add r3, r4, #0
    do_multiply
        add r4, r4, r3
        add r6, r6, #-1
        brp do_multiply
        brz end_multiply

checking2
    not r6, r0
    add r6, r6, #1
    ld r2, upperlimit
    add r2, r2, r6
    brn errorMessage2
    ld r2, lowerlimit
    add r2, r2, r6
    brp errorMessage1
    br continueGettingNums
    
checking3
    not r6, r0
    add r6, r6, #1
    ld r2, upperlimit
    add r2, r2, r6
    brn errorMessage2
    ld r2, lowerlimit
    add r2, r2, r6
    brp errorMessage1
    br continueGettingNums_2
    

;---------------	
; Program Data
;---------------


introPromptPtr  .FILL xB000
errorMessagePtr .FILL xB200
newline .fill xA
upperlimit .fill #57
lowerlimit .fill #48
multiplier .fill #9
count .fill #5
conversion .fill #-48
negativeflag .fill #-1

.END

;------------
; Remote data
;------------
.ORIG xB000	 ; intro prompt
.STRINGZ	 "Input a positive or negative decimal number (max 5 digits), followed by ENTER\n"

.END					
					
.ORIG xB200	 ; error message
.STRINGZ	 "ERROR: invalid input\n"

;---------------
; END of PROGRAM
;---------------
.END

;-------------------
; PURPOSE of PROGRAM
;-------------------
; Convert a sequence of up to 5 user-entered ascii numeric digits into a 16-bit two's complement binary representation of the number.
; if the input sequence is less than 5 digits, it will be user-terminated with a newline (ENTER).
; Otherwise, the program will emit its own newline after 5 input digits.
; The program must end with a *single* newline, entered either by the user (< 5 digits), or by the program (5 digits)
; Input validation is performed on the individual characters as they are input, but not on the magnitude of the number.