CC=gcc
FLAGS=-Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
OBJS=encriptado.o

all: main

main: tarea_1.c tarea_1.h $(OBJS)
	$(CC) $(FLAGS) -o tarea_1 tarea_1.c $(OBJS)

encriptado: encriptado.c encriptado.h
	$(CC) $(FLAGS) -o encriptado.c

clean:
	rm *.o tarea_1