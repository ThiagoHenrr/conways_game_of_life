obj = main.o Conway.o

app : $(obj)
	cc -o app $(obj)
main.o:	main.c Conway.c
	cc -c main.c
Conway.o: Conway.c
	cc -c Conway.c
clean:
	rm main.o Conway.o
