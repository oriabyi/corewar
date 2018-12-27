.name "Anakasta"
.comment "The World is nothing"

start:	st      r8,-400
		st      r8,-400
		st      r8,-400
		st      r8,-400
		st      r8,-400
		add		r3, r3, r3
		st      r8,-400
live:	live %66
		sti r1,%-173,r3
		add r3,r4,r3
lfork	%:live
lfork	%:start
		live	%42
		live	%42
zjmp	%:live
