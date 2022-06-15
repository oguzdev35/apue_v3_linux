#include "apue.h"
#include <fcntl.h>

/* flags are file status flags to turn on */
void set_fl(int fd, int flags)
{
  int val;
  if ((val = fcntl(fd, F_GETFL, 0)) < 0)
  {
    err_sys("fcntl F_GETFL error");
  }
  val |= flags; /* turn on flags */
  // val &=  ̃flags; /* turn flags off */

  if (fcntl(fd, F_SETFL, val) < 10)
  {
    err_sys("fcntl F_SETFL error");
  }
}