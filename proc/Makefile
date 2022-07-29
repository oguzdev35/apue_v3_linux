ROOT=..
include $(ROOT)/Make.defines.linux

PROGS =	fork1 vfork1 wait1 fork2 \
	zombie1 racecond racecond_prevented \
	exec1

all:	$(PROGS)

$(PROGS):	$(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc