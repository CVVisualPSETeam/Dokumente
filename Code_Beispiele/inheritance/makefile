# Makefile for inheritance_example
# created with makefile-creator


####################
#Settings:


CC = g++
CFLAGS =  -Wextra -pedantic -std=c++11 
CLIBS = 
INCLUDES = 
TARGET = inheritance_example
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

