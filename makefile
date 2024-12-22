SUBDIRS = libmysyslog libmysyslog-json libmysyslog-text mysyslog-client mysyslog-daemon

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

run-client:
	$(MAKE) -C mysyslog-client run

run-daemon:
	$(MAKE) -C mysyslog-daemon run

.PHONY: all clean $(SUBDIRS)