#
#'make' - make files
#'make clean' - remove all .o files
#

#compiler
CC= g++

#compile flags
FLAGS= -Wall -c -std=c++20
LFLAGS= 

#includes and header files
HEADER= baseClass.h

#sources
SOURCE= baseClass.cpp GearMaker.cpp

#Object files
OBJS= baseClass.o GearMaker.o

#executable
OUT= test.out

#
############################
#

.cpp.o:
	$(CC) $(FLAGS) -c $<

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

GearMaker.o: GearMaker.cpp
	$(CC) $(FLAGS) GearMaker.cpp -o GearMaker.o

baseClass.o: baseClass.cpp
	$(CC) $(FLAGS) baseClass.cpp -o baseClass.o

clean:
	rm -f $(OBJS) $(OUT)
