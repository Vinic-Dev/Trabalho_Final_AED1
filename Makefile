CC = gcc
CFLAGS = -Wall # -O2: otimização de nível 2 -Wextra: habilita warnings extras -Wall: habilita todos os warnings
TARGET = p1
SOURCES = main.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

run: $(TARGET)
	@./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET) $(TARGET).exe

.PHONY: run clean
