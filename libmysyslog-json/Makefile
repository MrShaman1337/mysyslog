CC = gcc
CFLAGS = -Wall -g -fPIC -I../libmysyslog
LDFLAGS = -shared

all: libmysyslog-json.so

libmysyslog-json.so: libmysyslog-json.o
	$(CC) $(LDFLAGS) -o $@ $^

libmysyslog-json.o: libmysyslog-json.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.so *.o
