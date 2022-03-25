CC 	= gcc
CFLAGS	= -Wall -g
RM	= rm -f

default:  all

all: link compile

link: main.cpp
	$(CC) $(CFLAGS) -c main.cpp multiply.cpp ../common/util.c ../common/basic.c ../common/naivelinalg.c

compile: main.o
	$(CC) $(CFLAGS) -o  main main.o multiply.o util.o basic.o naivelinalg.o

clean:
	$(RM) *.o
	$(RM) *.exe
	