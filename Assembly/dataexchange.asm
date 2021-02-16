	AREA RESET, CODE, READONLY
	ENTRY
START
      MOV r0, #0x40000000
      MOV r1, #0x40000008
      MOV r4, #09

loop  ldr r2,[r0]
      mov r5,r2
      ldr r6,[r1]
      str r6,[r0],#04
      str r5,[r1],#04
      subs r4,#01
      cmp r4,#00
      bne loop
stop  b stop

      end