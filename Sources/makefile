
CC = gcc

SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
H = $(wildcard *.h)

CFLAGS = -Wall -pedantic -std=c99 -D_GNU_SOURCE
LIB = -lm

PROG = Nebuleuse

all : .c.o 
	@$(CC) -o $(PROG) $(OBJS) $(LIB)
	
profil : .c.o
	@$(CC) -o $(PROG) $(OBJS) $(LIB) -pg

.c.o : 
	@$(CC) $(CFLAGS) $(LIB) $(H) -c $(SRC)

clean :
	@-rm *.o *.gch *~ $(PROG)

total : clean all
