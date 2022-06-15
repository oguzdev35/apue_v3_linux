ROOT=..
include $(ROOT)/Make.defines.linux

PROGS =	seektest seektest2 hole \
	ioefficiency fileflag ioctl

all:	$(PROGS)

$(PROGS):	$(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc