CC = gcc
CFLAGS = -g -I./src
TARGET = p1
SRC = $(wildcard src/*.c)
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
