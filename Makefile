GCC = gcc
FLAGS = -ansi -pedantic -Wall
C_FLAGS = -lm
PROGRAMAS = operacionesApp

operacionesApp:
	$(GCC) $(FLAGS) funcionsumamatrices.c -c
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) -0 $@ $@.o funcionsumamatrices.o

clean: $(RM) $(PROGRAMAS) *.o


