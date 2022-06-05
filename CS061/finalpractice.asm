.orig x3000
LDI R1, label1
halt
label1 .fill xC000
.end

.orig xC000
halt
.fill xD000
.end

; .orig xD000
; halt
; .fill xFFFF
; .end