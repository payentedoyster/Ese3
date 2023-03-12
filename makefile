test.app: utile.o vettore.o main.o
	gcc utile.o vettore.o main.o -o test.app

utile.o: utile.c
	gcc -c utile.c

vettore.o: vettore.c utile.h
	gcc -c vettore.c

main.o: vettore.h main.c
	gcc -c main.c