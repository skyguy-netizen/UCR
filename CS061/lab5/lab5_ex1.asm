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

LD R0, data_ptr
PUTS

halt

; your local data goes here

top_stack_addr .fill xFE00 ; DO NOT MODIFY THIS LINE OF CODE
sub_routine_null_terminated_character_arr .fill x3200
data_ptr .fill x4000
completed .stringz "Process complete"
condition .fill xA
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
