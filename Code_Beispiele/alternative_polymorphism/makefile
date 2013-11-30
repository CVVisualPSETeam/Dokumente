# Makefile for a.out
# created with makefile-creator


####################
#Settings:


CC =  clang++
CFLAGS =  -Wextra -pedantic -std=c++11 
CLIBS = 
INCLUDES = 
TARGET = a.out
OBJECTS = main.o


####################
#Rules:


$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(CLIBS)

%.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm *.o

all: $(TARGET)


####################
#Dependencies:


main.o: main.cpp 

