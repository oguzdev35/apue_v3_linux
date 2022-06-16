#include "apue.h"
#include <fcntl.h>

#define BUFFSIZE 4096

/*
If you open a file for read–write with the append flag, can you still read
from anywhere in the file using lseek? Can you use lseek to replace
existing data in the file? Write a program to verify this.

note: O_APPEND -> If set, the file offset shall be set to the end of the file prior to each write.
*/

int main(int argc, char const *argv[])
{
  int fd1, fd2;
  char buf[BUFFSIZE];

  if ((fd1 = open("dummy.lx", O_RDWR | O_APPEND)) < 0)
  {
    err_sys("open1 error");
  }

  if ((fd2 = open("dummy.lx", O_RDONLY)) < 0)
  {
    err_sys("open2 error");
  }

  if ((write(fd1, "Hello World", 11)) < 0)
  {
    err_sys("read error");
  }

  if ((read(fd2, buf, 11)) < 0)
  {
    err_sys("read error");
  }

  printf("before readed: %s\n", buf);

  if ((lseek(fd2, 0, SEEK_END) < 0))
  {
    err_sys("lseek error");
  }

  if ((write(fd1, "Hello World", 11)) < 0)
  {
    err_sys("read error");
  }

  if ((read(fd2, buf, 11)) < 0)
  {
    err_sys("read error");
  }
  /* yes we can read */
  printf("after readed: %s\n", buf);

  if ((lseek(fd1, 0, SEEK_SET) < 0))
  {
    err_sys("lseek error");
  }

  if ((write(fd1, "Merhaba Dunya", 13)) < 0)
  {
    err_sys("read error");
  }

  if ((lseek(fd2, 0, SEEK_SET) < 0))
  {
    err_sys("lseek error");
  }
  if ((read(fd2, buf, 22)) < 0)
  {
    err_sys("read error");
  }
  /* yes we can read */
  printf("after lseek override readed: %s\n", buf);

  return 0;
}
