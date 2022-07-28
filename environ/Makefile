ROOT=..
include $(ROOT)/Make.defines.linux

PROGS =	doatexit echoarg hello1 cmd1 cmd2 \
	testjmp getrlimit

all:	$(PROGS)

$(PROGS):	$(LIBAPUE)
		$(CC) $(CFLAGS) $@.c -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS) $(TEMPFILES) *.o

include $(ROOT)/Make.libapue.inc