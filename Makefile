TARGET=./build/main.exe
CC=gcc
DEBUG=-g
OPT=-O0
WARN=-Wall -Wextra
CCFLAGS=$(DEBUG) $(OPT) $(WARN) 
LD=gcc
OBJS=./build/main.o

all: ./build/main.o
	$(LD) -o $(TARGET) $(OBJS) 

./build/main.o: ./src/main.c
	mkdir build
	$(CC) -c ./src/main.c -o ./build/main.o $(CCFLAGS)

clean:
	-del "./build/"
	@echo "clean completed"

run:
	./build/main.exe