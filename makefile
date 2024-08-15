obj = main.o Conway.o

app : $(obj)  #arquivos necessários para gerar o executável app
	cc -o app $(obj) # como será gerado
main.o:	main.c Conway.c #arquivo necessário para gerar main.o
	cc -c main.c
Conway.o: Conway.c
	cc -c Conway.c
clean:
	rm main.o Conway.o
