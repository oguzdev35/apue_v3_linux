#
# Makefile for misc library.
#
ROOT=..
include $(ROOT)/Make.defines.linux

LIBMISC	= libapue.a
OBJS   = error.o 

all:	$(LIBMISC) sleep.o

$(LIBMISC):	$(OBJS)
	$(AR) rv $(LIBMISC) $?
	$(RANLIB) $(LIBMISC)


clean:
	rm -f *.o a.out core temp.* $(LIBMISC)

include $(ROOT)/Make.libapue.inc