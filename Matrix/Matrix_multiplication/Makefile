CC=gcc
CFLAGS= -Wall -std=gnu99
TUNE= -O 
EXEC = parallel Strassen

all: parallel Strassen

parallel:
		$(CC) $(TUNE) $(CFLAGS) -o matrix_mul matrix_mul.c -lpthread

Strassen:
		$(CC) $(TUNE) $(CFLAGS) -o matrix_Strassen matrix_Strassen.c

clean:
		$(RM) matrix_mul matrix_Strassen
