# Definir o compilador
CC=gcc

# Definir as flags de compilação
CFLAGS=-Wall -g

# Nome do arquivo executável
EXEC=quicksort

# Objetos necessários para a compilação
OBJS=main.o stack.o

# Regra padrão
all: $(EXEC)

# Regra para criar o executável
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Regra para compilar main.c
main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c

# Regra para compilar stack.c
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

# Regra para limpar arquivos compilados
clean:
	rm -f $(OBJS) $(EXEC)

# Regra para executar o programa
run: $(EXEC)
	./$(EXEC)
