trout: main.o trout.o util.o test_util
	gcc -g -o trout main.o trout.o util.o -Wall

test_util: test_util.o util.o
	gcc -g -o test_util test_util.o util.o


test_util.o: test_util.c
	gcc -c test_util.c

main.o: main.c
	gcc -c main.c

trout.o: trout.c util.h
	gcc -c trout.c

util.o: util.c
	gcc -c util.c

clean:
	rm main.o util.o trout.o test_util.o test_util trout 