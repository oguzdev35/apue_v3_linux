#include "apue.h"
#include "fcntl.h"
#include <errno.h>

/*
3.2 Write your own dup2 function that behaves the same way as the dup2
function described in Section 3.12, without calling the fcntl function.
Be sure to handle errors correctly.

int dup2(int fd, int fd2);
*/

int my_dup2(int fd, int fd2);

int main(int argc, char const *argv[])
{
  int newFd;

  if ((newFd = my_dup2(1, 50)) < 0)
  {
    err_sys("my_dup error");
  }

  printf("new fd is %d\n", newFd);

  return 0;
}

int my_dup2(int fd, int fd2)
{
  extern int errno;
  int k, i;
  char fdPathStr[20];
  int temp_fd;
  int closedFds[fd2];

  sprintf(fdPathStr, "/dev/fd/%d", fd2);

  if (open(fdPathStr, O_RDONLY) > 0)
  {
    errno = EINVAL;
    return -1;
  }

  k = 0;

  while (((temp_fd = dup(fd)) != fd2))
  {
    if (temp_fd < 0)
    {
      return -1;
    }
    closedFds[k] = temp_fd;
    k++;
  }

  i = 0;

  while (i < k)
  {
    /*printf("closed fd: %d\n", closedFds[i]); */
    close(closedFds[i]);
    i++;
  }

  return temp_fd;
}