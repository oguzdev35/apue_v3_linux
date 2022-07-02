/*
Write a utility like cp(1) that copies a file containing holes,
without writing the bytes of 0 to the output file.
*/
/*
  //create file with holes
  //echo -n "X" | dd of=hole.txt bs=4096 seek=10
  //od -c hole.txt

   filedir git:(main) ✗ ls -ls hole.txt*
  4 -rw-rw-r-- 1 vagrant vagrant 40961 Jul  1 13:07 hole.txt
  4 -rw-rw---- 1 vagrant vagrant     1 Jul  1 13:49 hole.txt.copy

  4 -rw-rw-r-- 1 vagrant vagrant 40961 Jul  1 13:07 hole.txt
  4 -rw-rw-r-- 1 vagrant vagrant 40961 Jul  1 13:50 hole.txt.copy
*/
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include "apue.h"
#include <fcntl.h>

#define BUFSIZE 1500
#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IRGRP)

int main(int argc, char const *argv[])
{
  int fd_s, fd_d; /* source fd , destination fd */
  int buf[BUFSIZE];
  int n;
  int ln;

  if (argc != 3)
  {
    err_sys("usage: <program-name> <source> <destination>");
  }

  if ((fd_s = open(argv[1], O_RDONLY)) < 0)
  {
    err_sys("open error for source file");
  }

  if ((fd_d = open(argv[2], O_WRONLY | O_CREAT, RWRWRW)) < 0)
  {
    err_sys("open error for destination file");
  }

  if ((ln = lseek(fd_s, 0, SEEK_DATA)) < 0)
  {
    err_sys("lseek error");
  }

  printf("%d\n", ln);

  while ((n = read(fd_s, buf, BUFSIZE)) > 0)
  {
    printf("n: %d\n", n);
    if (write(fd_d, buf, n) < 0)
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
