#ESSE ARQUIVO MAKEFILE TEM A FUNÇÃO DE EXECUTAR EM PARALELO O "index.cpp" E AS FUNÇÕES (E REGISTRO) QUE
#SERÃO USADAS NELE (index), AS QUAIS ESTÃO EM "functions.cpp".
#COM ISSO SERÁ CRIADO UM EXECUTÁVEL CHAMADO "main", O QUAL AO SER EXECUTADO FARÁ A FUNÇÃO DE RODAR "index.cpp" E "functions.cpp" EM PARALELO, TORNANDO A MODULARIZAÇÃO EXTERNA POSSÍVEL.

# Nome base do executável
EXEC_BASE = main

# Define extensão dependendo do sistema operacional
ifeq ($(OS),Windows_NT)
	EXEC = $(EXEC_BASE).exe
else
	EXEC = $(EXEC_BASE)
endif

# Compilador
CC = g++

# Flags de compilação
CFLAGS = -Wall -Wextra

# Arquivos de código-fonte
SRC = index.cpp functions.cpp

# Arquivos objeto
OBJ = $(SRC:.cpp=.o)

# Regra padrão
all: $(EXEC)

# Como gerar o executável
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Como gerar os objetos
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos temporários
clean:
	rm -f $(OBJ) $(EXEC_BASE) $(EXEC_BASE).exe

# Recompilar tudo
rebuild: clean all

# Executar o programa, independente do SO
run: all
	./$(EXEC)