CC = gcc
CFLAGS = -Wall -Wextra -g

OBJ = main.o busca.o dados.o menus.o morador.o ordenacao.o

buscamorador: $(OBJ)
	$(CC) $(CFLAGS) -o buscamorador $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o buscamorador
