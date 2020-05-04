	.arch msp430g2553

	.p2align 1,0

	.text
	.global states
JT:
	.word case0
	.word case1
	.word case2
	.word case3
	.word case4

states:	
	mov &CURRENT_STATE, r12	;moves the current value of the state into register
	cmp #5, r12		;compars the value of the switch to the value of 5
	jhs case0		;it will jmp to case0 if it is not with bounds
	add r12, r12		;add r13 to r13 to multiplly space 
	mov JT(r12), r0		;calculates when to jump to based on r13 placed into counter

case0: 
	call #green_led_on	;calls the method green_led_on if input is out of bounds
	jmp end			;it will be place in case0 till another interupt occurs
	 

case1:
	mov #0, &dim_flag	;moves a 0 into dimflag meaning that the dim option is 
	call #count_to_3	;toggled off then call method count to 3
	jmp end

case2:
	mov #1, &dim_flag	;moves a 1 into dimflag trigering the dim option is 
	call #count_to_3	;toggled on affecting how count to 3 will blink
	jmp end
case3:
	call #count_to_3	;calls count to 3 method while increasing the speed
	sub #1, &speed		;the leds blinks by making the the interupt/ method
	cmp #0, &speed		;be called faster by deceasing the value of speed
	jeq case3		;variable
	jmp end

case4:
	call #little_lamb	;calls little lamb method that play a song when button 4 is
	jmp end			;pressed

end:
	pop r0
