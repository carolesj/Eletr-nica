CFLAGS = -O0 -Wall -g
OBJECTS = main.o LeArquivo.o Neuronios.o
all : $(OBJECTS) LeArquivo.h Neuronios.h
	gcc $(CFLAGS) $(OBJECTS) -o RAM -lm

test: testeRAM.o Neuronios.o LeArquivo.o
	gcc $(CFLAGS) $^ -o testa -lm
	
%.o: %.c LeArquivo.h Neuronios.h
	gcc $(CFLAGS) $< -c

run : 
	@./RAM
