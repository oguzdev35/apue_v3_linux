#include "apue.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
  create 512 mb file
    cat /dev/urandom | head -c 536870912 > file.512mb
    128 mb -> 134217728
  test:
    time ./fileio/ioefficiency 4096 <file.512mb &>/dev/null
*/

int main(int argc, char const *argv[])
{
  char *p;
  int n;
  long bufsize;
  if (argc != 2)
  {
    err_exit(1, "bufsize argument needed");
  }
  bufsize = strtol(argv[1], &p, 10);

  char buf[bufsize];

  int devNull = open("/dev/null", O_RDWR);

  while ((n = read(STDIN_FILENO, buf, bufsize)) > 0)
  {
    if (write(devNull, buf, n) != n)
    {
      err_sys("write error");
    }
  }

  if (n < 0)
  {
    err_sys("read error");
  }

  exit(0);
}
