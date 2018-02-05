SRC_DIRECTORY = src
INC_DIRECTORY = inc

TARGET = priorityQueue
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall -I$(INC_DIRECTORY)

.PHONY: all clean

all: $(TARGET)

OBJECTS = $(SRC_DIRECTORY)/main.o $(SRC_DIRECTORY)/priorityQueue.o

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

#.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f $(SRC_DIRECTORY)/*.o
	-rm -f $(TARGET)

