all:txtfind isort

main:isort.o txtfind.o
	gcc -Wall isort txtfind

txtfind:txtfind.c
	gcc -Wall  txtfind.c -o txtfind.o
	
isort:isort.c
	gcc -Wall  isort.c -o isort.o
	
.PHONY:clean

clean:
	rm -f *.o *.out