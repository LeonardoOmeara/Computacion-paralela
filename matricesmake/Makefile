GCC = gcc
FLAGS = -ansi -pedantic -Wall -std=c99
C_FLAGS = -lm
PROGRAMAS = operacionesApp 

operacionesApp:
	$(GCC) $(FLAGS) funcionoperaciones.c -c
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) -o $@ $@.o funcionoperaciones.o

clean: 
	$(RM) $(PROGRAMAS) *.o


