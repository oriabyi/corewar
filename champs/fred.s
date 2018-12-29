.name           "Someone"
.comment        "Something allways wins"

live:	
	live	%4
	ld %573, r8

	st r5, 478
	st r2, 409
	st r9, 340
	st r11, 271

	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0
	zjmp	%0

	fork 	%50
	fork 	%5
	fork 	%15

	zjmp	%:live
	