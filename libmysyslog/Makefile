CC = gcc
CFLAGS = -Wall -g -fPIC
LDFLAGS = -shared

all: libmysyslog.so

libmysyslog.so: libmysyslog.o
	$(CC) $(LDFLAGS) -o $@ $<
libmysyslog.o: libmysyslog.c libmysyslog.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.so
