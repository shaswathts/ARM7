	AREA ADDITION ,CODE,READONLY
	ENTRY
START 
	LDR R0,=value1
	LDR R1,[R0]
	LDR R2,[R0,#4]
	LDR R3,=value2
	LDR R4,[R3]
	LDR R5,[R3,#4]

	SUB R6,R1,R4
	SBC R7,R2,R5
	SWI &11
value1	DCD &33333333,&11111111
value2	DCD &44444444,&22222222

	END