# CLASSDIR = $(HOME)
CLASSDIR = ./
INCLUDE = -I$(CLASSDIR)/kutuphaneler
LIBS2 = $(CLASSDIR)/kutuphaneler/matrisgen.h
CC = gcc

EX = matrisgen
all: $(EX) 
clean: 
	rm -f *.o $(EX)


matrisgen: matrisgen.o $(LIBS2)
	$(CC) $(INCLUDE) -o matrisgen matrisgen.o $(LIBS2)


.SUFFIXES: .c .o

.c.o: 
	$(CC) $(INCLUDE) -g  -c  $*.c

