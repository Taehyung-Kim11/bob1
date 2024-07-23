CC=gcc
CFLAGS=-Wall -Wextra -O2
TARGET=main

all: $(TARGET)

$(TARGET): main.o
    $(CC) $(CFLAGS) -o $@ $^

main.o: main.c
    $(CC) $(CFLAGS) -c $<

clean:
    rm -f $(TARGET) *.o

.PHONY: all clean

