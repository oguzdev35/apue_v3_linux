ROOT=..
include $(ROOT)/Make.defines.linux

PROGS =	ls cat getcputc hello shell1 \
	testerror uidgid shell2

all:	$(PROGS)

$(PROGS):	$(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc