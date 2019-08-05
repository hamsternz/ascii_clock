ascii_clock : ascii_clock.c
	gcc -o ascii_clock ascii_clock.c -Wall -pedantic -O4 -Wall

clean :
	rm ascii_clock
