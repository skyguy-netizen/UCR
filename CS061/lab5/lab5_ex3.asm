;=================================================
; Name: Aarav Sane
; Email: asane003@ucr.edu
; 
; Lab: lab 5, ex 1
; Lab section: 21
; TA: Sarhtak Jain
; 
;=================================================
.orig x3000
; Initialize the stack. Don't worry about what that means for now.
ld r6, top_stack_addr ; DO NOT MODIFY, AND DON'T USE R6, OTHER THAN FOR BACKUP/RESTORE

; your code goes here
ld r1, data_ptr
ld r4, condition
LD r5, sub_routine_null_terminated_character_arr
JSRR r5

LEA R0, mainString
Puts
LD r0, data_ptr
Puts

LD r2, upper_to_lower
JSRR r2

LD r2, sub_routine_pal_checker
JSRR r2

add r0, r0, #0
brz pali

LEA R0, endStringNotPal
puts
halt

pali
LEA R0, endStringPal
Puts
halt

; your local data goes here

top_stack_addr .fill xFE00 ; DO NOT MODIFY THIS LINE OF CODE
sub_routine_null_terminated_character_arr .fill x3200
sub_routine_pal_checker .fill x3400
upper_to_lower .fill x3600
data_ptr .fill x4000
completed .stringz "Process complete"
condition .fill xA
palii .stringz "true"
notPalii .stringz "false"
mainString .stringz "The string "
endStringPal .stringz " is a palindrome"
endStringNotPal .stringz " is not a palindrome"
;bitmask .fill x61
.end

; your subroutines go below here

.orig x3200

add r6, r6, #-1
str r1, r6, #0

add r6, r6, #-1
str r7, r6, #0

AND R5, R5, #0
do_while
    GETC
    OUT
    STR R0, r1, #0
    add r1, r1, #1
    add r5, r5, #1
    not r0, r0
    add r0, r0, #1
    ADD r2, r0, r4
    brz sentinel_loop
    brnzp do_while
    
sentinel_loop
add r1, r1, #-1
and r0, r0, #0
str r0, r1, #0
add r5, r5, #-1

ldr r7, r6, #0
add r6, r6, #1

ldr r1, r6, #0
add r6, r6, #1

ret
.end


;palindrome checker
.orig x3400
add r6, r6, #-1
str r1, r6, #0

add r6, r6, #-1
str r7, r6, #0

add r3, r1, r5
add r3, r3, #-1


do_while_loop
    LDR r4, r1, #0
    LDR r5, r3, #0
    not r4, r4
    add r4, r4, #1
    add r0, r4, r5
    BRnp notPal
    add r1, r1, #1
    not r4, r1
    add r4, r4, #1
    add r4, r4, r3
    brz pal
    add r3, r3, #-1
    not r4, r1
    add r4, r4, #1
    add r4, r4, r3
    brz pal
    brnzp do_while_loop

    
pal

AND R0, R0, #0

ldr r7, r6, #0
add r6, r6, #1

ldr r1, r6, #0
add r6, r6, #1
ret

notPal
AND R0, R0, #0
add r0, r0, #1
ldr r7, r6, #0
add r6, r6, #1

ldr r1, r6, #0
add r6, r6, #1
ret


.end


;upper_to_lower
.orig x3600
add r6, r6, #-1
str r1, r6, #0

add r6, r6, #-1
str r7, r6, #0

add r6, r6, #-1
str r5, r6, #0

LD r4, bitmask
NOT R4, R4

upperLowerLoop
    LDR R0, R1, #0
    NOT R0, R0
    AND R0, R0, R4
    NOT R0, R0
    add r0, r0, #-1
    STR R0, R1, #0
    add r1, r1, #1
    add r5, r5, #-1
    brp upperLowerLoop


ldr r5, r6, #0
add r6, r6, #1

ldr r7, r6, #0
add r6, r6, #1

ldr r1, r6, #0
add r6, r6, #1

ret
bitmask .fill x61

.end

