CC 	= gcc
CFLAGS	= -Wall -g
RM	= rm -f

default:  all

all: compile run

compile: main.cpp
	$(CC) $(CFLAGS) -c main.cpp transpose.cpp ../common/util.c ../common/basic.c ../common/naivelinalg.c

run: main.o
	$(CC) $(CFLAGS) -o  main main.o transpose.o util.o basic.o naivelinalg.o

clean:
	$(RM) *.o
	$(RM) *.exec
	
