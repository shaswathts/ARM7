; Adding two 64 bit numbers
	AREA RESET, CODE, READONLY
	ENTRY
START

	MOV R0, #0x40000000	;Higher byte of first number
	MOV R1, #0x40000004	;Lower byte of first number
	MOV R2, #0x40000008	;Higher byte of second number
	MOV R3, #0x4000000c	;Lower byte of second number 
	
	MOV R4, #0X40000010	;Answer higher byte
	MOV R5, #0X40000014	;Answer lower byte

	MOV R6, R1
	MOV R7, R3
	ADDS R8, R6, R7
	STR R8, [R4]

	MOV R6, R0
	MOV R7, R2
	ADC R8, R6, R7
	STR R8, [R5]	

	END