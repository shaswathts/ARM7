; Adding two 64 bit numbers
	AREA RESET, CODE, READONLY
	ENTRY
START

	MOV R0, #0x40000000	;Higher byte of first number
	MOV R1, #0x40000004	;Lower byte of first number
	MOV R2, #0x40000008	;Higher byte of second number
	MOV R3, #0x4000000c	;Lower byte of second number 
	MOV R5, #0x40000010	;Higher byte of second number
	MOV R6, #0x40000014	;Lower byte of second number

	LDR R8, [R1]
	LDR R10, [R3]
	ADDS R4, R8, R10
	STR R4, [R6]

	LDR R8, [R0]
	LDR R10, [R2]
	ADC R4, R8, R10
	STR R4, [R5]

	END