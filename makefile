

RUN:main.o display.o display.h road.h road.o player.c player.h car.h car.o 
	gcc $^ -o $@ -lm

clean:
	rm *.o -f

distclean: clean
	rm  RUN -f
