CC 	= g++
CFLAGS	= -Wall -g -fopenmp
RM	= rm -f

default:  all

all: link compile

link: main.cpp
	$(CC) $(CFLAGS) -c main.cpp openmp.cpp ../common/util.c

compile: main.o
	$(CC) $(CFLAGS) -o  main main.o openmp.o util.o

clean:
	$(RM) *.o
	$(RM) *.exec
	
