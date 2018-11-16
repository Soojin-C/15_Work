all: driver.o
	gcc driver.o

driver.o: driver.c
	gcc -c driver.c

run:
	./a.out
	make clean

clean:
	rm a.out
