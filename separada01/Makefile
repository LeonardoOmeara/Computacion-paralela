GCC = gcc
FLAGS = -ansi -pedantic -Wall
C_FLAGS = -lm
PROGRAMAS = sumaApp

sumaApp:
    $(GCC) $(FLAGS) funcionsumaC.c -c
    $(GCC) $(FLAGS) %@.c -c
    $(GCC) $(FLAGS) -o $@ $@.o funcionsuma.o

clean:
    $(RM) $(PROGRAMAS) *.o