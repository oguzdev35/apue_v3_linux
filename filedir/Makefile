ROOT=..
include $(ROOT)/Make.defines.linux

PROGS =	filetype access umask \
	changemod unlink futimens \
	devrdev
MOREPROGS = ftw

all:	$(PROGS) $(MOREPROGS)

$(PROGS):	$(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

ftw:	ftw.c $(LIBAPUE)
	$(CC) $(CFLAGS) $(NAMEMAX) ftw.c -o ftw $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(MOREPROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc