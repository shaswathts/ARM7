;
	AREA RESET,CODE,READONLY
	ENTRY
START
		MOV R5,#0x40000000
		MOV R1,#0X40000004
		MOV R2,#0X4000001C
		LDR R3,[R1]
LOOP	ADD R1,R1,#04
		LDR R4,[R1]
		CMP R3,R4
		BHI LOOP1
		MOV R3,R4
LOOP1	SUBS R5,R5,#01
		CMP R5,#00
		BNE LOOP
		STR R3,[R2]

		MOV R5,#0x40000000
		MOV R1,#0X40000004
		MOV R2,#0X4000001C
		LDR R3,[R1]
LOOP2	ADD R1,R1,#04
		LDR R4,[R1]
		CMP R3,R4
		BLS LOOP3
		MOV R3,R4
LOOP3	SUBS R5,R5,#01
		CMP R5,#00
		BNE LOOP2
		STR R3,[R2]
		SWI 0X11
		END