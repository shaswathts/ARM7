; PROGRAM TO ADD AN ARRAY OF TWO 16 BIT NUMBERS.
; DATE: 28-10-2020

	AREA RESET, CODE, READONLY	;
ENTRY							;
START							;
	MOV R0, #0x40000000			; copy the address 0x40000000 to register R0
	LDR R2, [R0]				; load the value present in R0 (LDR(H) = Half word) into R2
	ADD R0, R0, #02				; Increament the address 
	LDRH R3, [R0]				; Load the value present in the R0 into R3
	ADD R4, R2, R3				; add the values present in the register's R2 and R3 and then store it into R4
	END							; END OF PROGRAM