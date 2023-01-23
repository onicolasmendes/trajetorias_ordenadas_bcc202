all: tp.o ordenacao.o
	@gcc tp.o ordenacao.o -o exe
	rm -r *.o
tp.o: tp.c
	@gcc tp.c -c -Wall
ordenacao.o: ordenacao.c
	@gcc ordenacao.c -c -Wall
run:
	@./exe