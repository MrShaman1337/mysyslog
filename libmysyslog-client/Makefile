CC = gcc
CFLAGS = -Wall -g -I../libmysyslog -I../libmysyslog-text -I../libmysyslog-json
LDFLAGS = -L../libmysyslog -L../libmysyslog-text -L../libmysyslog-json -lmysyslog -lmysyslog-text -lmysyslog-json

all: libmysyslog-client

libmysyslog-client: libmysyslog-client.o
	$(CC) -o $@ $^ $(LDFLAGS)

libmysyslog-client.o: libmysyslog-client.c
	$(CC) $(CFLAGS) -c $<

run: libmysyslog-client
	./libmysyslog-client

clean:
	rm -f libmysyslog-client *.o
a