CC = gcc
CFLAGS = -Wall -g -I../libmysyslog -I../libmysyslog-text -I../libmysyslog-json
LDFLAGS = -L../libmysyslog -L../libmysyslog-text -L../libmysyslog-json -lmysyslog -lmysyslog-text -lmysyslog-json

all: libmysyslog-daemon

libmysyslog-daemon: libmysyslog-daemon.o
	$(CC) -o $@ $^ $(LDFLAGS)

libmysyslog-daemon.o: libmysyslog-daemon.c
	$(CC) $(CFLAGS) -c $<

run: libmysyslog-daemon
	./libmysyslog-daemon

clean:
	rm -f libmysyslog-daemon *.o
