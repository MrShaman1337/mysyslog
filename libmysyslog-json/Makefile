CC = gcc
CFLAGS = -Wall -Wextra -fPIC
TARGET = libmysyslog-json.so

all: $(TARGET)

$(TARGET): libmysyslog-json.o
        $(CC) -shared -o $(TARGET) libmysyslog-json.o

libmysyslog-json.o: libmysyslog-json.c
        $(cc) $(CFLAGS) -c libmysyslog-json.c

clean:
        rm -f $(TARGET) *.o

.PHONY: all clean




