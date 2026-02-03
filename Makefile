
# INSTRUÇÕES DE USO:
# 
# 1. Para compilar o programa:
#    make
#    ou
#    make all
# 
# 2. Para executar o programa:
#    make run
# 
# 3. Para limpar os arquivos compilados:
#    make clean
# 
# 4. Para compilar e executar em um único comando:
#    make all run

# Compilador a ser usado
CC = gcc

# Flags de compilação
# -Wall: habilita todos os warnings
# -Wextra: habilita warnings extras
# -O2: otimização de nível 2
CFLAGS = -Wall

# Nome do executável final
TARGET = p1

# Arquivos fonte
SOURCES = main.c

# ==============================================================================

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

run: $(TARGET)
	@./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET) $(TARGET).exe

.PHONY: all run clean
