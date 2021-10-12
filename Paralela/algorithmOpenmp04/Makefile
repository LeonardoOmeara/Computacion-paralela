GCC = gcc
FLAGS = -ansi -pedantic -Wall -std=c99
C_FLAGS = -fopenmp
PROGRAMAS = MM1c

MM1c:
	$(GCC) $(FLAGS) funcionesmatrices.c -c $(C_FLAGS)
	$(GCC) $(FLAGS) ctime.c -c $(C_FLAGS)
	$(GCC) $(FLAGS) $@.c -c $(C_FLAGS)
	$(GCC) $(FLAGS) -o $@ $@.o funcionesmatrices.o ctime.o $(C_FLAGS)

clean:
	$(RM) $(PROGRAMAS) *.o

