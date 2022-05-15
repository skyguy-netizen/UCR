; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Aarav Sane
; Email: asane003@ucr.edu
; 
; Assignment name: Assignment 5
; Lab section: 21
; TA: Sarthak Jain
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=================================================================================
; PUT ALL YOUR CODE AFTER THE main LABEL
;=================================================================================

;---------------------------------------------------------------------------------
;  Initialize program by setting stack pointer and calling main subroutine
;---------------------------------------------------------------------------------
.ORIG x3000

; initialize the stack
ld r6, stack_addr

; call main subroutine
lea r5, main
jsrr r5

;---------------------------------------------------------------------------------
; Main Subroutine
;---------------------------------------------------------------------------------
main
; get a string from the user
lea R1, user_prompt
lea r2, user_string
ld r4, get_user_string_addr
jsrr r4


; find size of input string
and r2, r2, x0
and r3, r3, x0
and r0, r0, x0
LD r4, strlen_addr
lea r1, user_string
jsrr r4

add r3, r0, #0
lea r0, result_string
puts
add r0, r3, #0
; call palindrome method
lea r1, user_string
add r2, r1, r0
add r0, r0, #0
brz palindrome_one_or_no_char
add r0, r0, #-1
brz palindrome_one_or_no_char
add r2, r2, #-1
ld r4, palindrome_addr
jsrr r4

; determine of stirng is a palindrome
and r2, r2, x0
and r3, r3, x0
and r4, r4, x0
add r0, r0, #0
brz notPalindrome
palindrome_one_or_no_char
lea r0, final_string
puts
br final_done


; print the result to the screen


; decide whether or not to print "not"
notPalindrome
lea r0, not_string
puts
lea r0, final_string
puts

final_done
HALT

;---------------------------------------------------------------------------------
; Required labels/addresses
;---------------------------------------------------------------------------------

; Stack address ** DO NOT CHANGE **
stack_addr           .FILL    xFE00

; Addresses of subroutines, other than main
get_user_string_addr .FILL    x3200
strlen_addr          .FILL    x3300
palindrome_addr      .FILL	  x3400


; Reserve memory for strings in the progrtam
user_prompt          .STRINGZ "Enter a string: "
result_string        .STRINGZ "The string is "
not_string           .STRINGZ "not "
final_string         .STRINGZ	"a palindrome\n"

; Reserve memory for user input string
user_string          .BLKW	  100
.END

;---------------------------------------------------------------------------------
; get_user_string - get a null terminated string from the user
;
;parameter: R1 - address of the user prompt string
;parameter: R2 - address where the user string should be stored
;
;returns: nothing
;---------------------------------------------------------------------------------
.ORIG x3200
get_user_string
; Backup all used registers, R7 first, using proper stack discipline
add r6, r6, #-1
STR r7, r6, #0
add r6, r6, #-1
STR r2, r6, #0

ld r3, newline
not r3, r3
add r3, r3, #1
add R0, R1, #0
puts
do_while
    ld r3, newline
    not r3, r3
    add r3, r3, #1
    GETC
    OUT
    add r3, r0, r3
    brz done
    STR R0, R2, #0
    add R2, R2, #1
    br do_while

; Resture all used registers, R7 last, using proper stack discipline
done
ld r0, zero
str r0, r2, #0

ldr r2, r6, #0
add r6, r6, #1
LDR R7, r6, #0
add r6, r6, #1
ret
newline .fill xA
zero .fill x0
.END

;---------------------------------------------------------------------------------
; strlen - compute the length of a zero terminated string
;
;parameter: R1 - the address of a zero terminated string
;
;returns: R0 - The length of the string
;---------------------------------------------------------------------------------
.ORIG x3300
strlen
; Backup all used registers, R7 first, using proper stack discipline
add r6, r6, #-1
STR r7, r6, #0
add r6, r6, #-1
str r2, r6, #0

ld r2, zero2

do_while_loop
    ldr r3, r1, #0
    add r3, r3, r2
    brz done_2
    add r0, r0, #1
    add r1, r1, #1
    br do_while_loop

; Resture all used registers, R7 last, using proper stack discipline
done_2
ldr r2, r6, #0
add r6, r6, #1
LDR R7, r6, #0
add r6, r6, #1
ret
zero2 .fill x0
.END

;---------------------------------------------------------------------------------
; palindrome - determines whether user input string is a palindrome or not
;
;parameter: R1 - address of first character of user string
;parameter: R2 - address of last character of user string
;
;returns: R0 - 1 if palindrome, 0 if not palindrome
;---------------------------------------------------------------------------------
.ORIG x3400
palindrome ; Hint, do not change this label and use for recursive alls
; Backup all used registers, R7 first, using proper stack discipline
add r6, r6, #-1
STR r7, r6, #0
add r6, r6, #-1
str r1, r6, #0
add r6, r6, #-1
str r2, r6, #0
add r6, r6, #-1
str r5, r6, #0

not r3, r1
add r3, r3, #1
add r3, r2, r3
brnz done_pali
ldr r3, r1, #0
not r3, r3
add r3, r3, #1
ldr r5, r2, #0
add r3, r3, r5
brnp done_notpali
add r1, r1, #1
add r2, r2, #-1
jsr palindrome

add r0, r0, #0
brz done_notpali
done_pali
; Resture all used registers, R7 last, using proper stack discipline
and r0, r0, x0
add r0, r0, #1
ldr r5, r6, #0
add r6, r6, #1
ldr r2, r6, #0
add r6, r6, #1
ldr r1, r6, #0
add r6, r6, #1
LDR R7, r6, #0
add r6, r6, #1
ret

done_notpali
and r0, r0, x0
; Resture all used registers, R7 last, using proper stack discipline
ldr r5, r6, #0
add r6, r6, #1
ldr r2, r6, #0
add r6, r6, #1
ldr r1, r6, #0
add r6, r6, #1
LDR R7, r6, #0
add r6, r6, #1
ret

.end