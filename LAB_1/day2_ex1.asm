	AREA RESET, CODE, READONLY
ENTRY
MAIN
	
		LDR R0, =VALUE1			;LOADING THE ADDRESS OF VALUE1 TO R0
		LDR R1, [R0]			;LOADING THE VALUE PRESENT IN RO TO R1
		
		ADD R0, R0, #04			;INCREAMENTING THE ADDRESS LOCATION PRESENT IN R0
		LDR R2, [R0]			;LOADING THE VALUE PRESENT IN THE ADDRESS OF R0 INTO R2 POST INCREAMENT

		ADD R1, R1, R2			;ADDING 'R1' AND 'R2' AND STORING/OVERWRITING IT INTO TO 'R1' 

		LDR R0, =0x40000000		;ASSIGNING AN IMMEDIATE ADDRESS LOCATION TO 'R0'
		STR R1, [R0]			;WRITTING THE VALUE OF R1 INTO THE MEMORY ADDRESS HELD BY 'R0'

		SWI &11

VALUE1 DCD &37E3C128		;ASSIGNING 37E3C128 TO VARIABLE VALUE1 WHICH IS POINTING TO SOME ADDRESS
VALUE2 DCD &367402AA		;ASSIGNING 367402AA TO VARIABLE VALUE2 WHICH IS POINTING TO SOME ADDRESS

		END

