;=================================================
; Name: Aarav Sane
; Email:  asane003@ucr.edu
; 
; Lab: lab 2, ex 2
; Lab section: 21
; TA: Sarthak Jain
; 
;=================================================


; .ORIG x3000

; LD R3, DEC_65
; LD R4, HEX_41
; STORE 
; HALT
; DEC_65_ptr .FILL x4000
; HEX_41_ptr .FILL x4001
; x4000 .FILL #65
; x4001 .FILL x41
; ; HALT
; ; .ORIG x4000
; ; NEW_DEC_65 .FILL #65
; ; NEW_HEX_41 .FILL x41
; ; .END
; .END

.orig x3000

LDI R3, DEC_ptr
LDI R4, HEX_ptr

add r3, r3, #1
add r4, r4, x1

STI r3, DEC_ptr
STI r4, HEX_ptr

halt
DEC_ptr .fill x4000
HEX_ptr .fill x4001
.end
.orig x4000
new_dec .fill #65
new_hex .fill x41

.end





