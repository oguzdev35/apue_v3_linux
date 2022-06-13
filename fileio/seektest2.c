#include "apue.h"

/*
  usage:
    ./seektest < /etc/passwd
*/

int main(int argc, char const *argv[])
{
  if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
  {
    err_sys("cannot seek");
  }
  else
  {
    printf("seek OK!\n");
  }
  exit(0);
}
