ROOT=..
include $(ROOT)/Make.defines.linux

PROGS =	fwide vprintf buf tempfiles mkstemp \
	memstr

all:	$(PROGS)

$(PROGS):	$(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)


clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc