#include "apue.h"
#include <sys/wait.h>

char *env_init[] = {"User=unknown", "PATH=/tmp", NULL};

int main(int argc, char const *argv[])
{
  pid_t pid;

  if ((pid = fork()) < 0)
  {
    err_sys("fork error");
  }
  else if (pid == 0)
  {
    /* specify pathname, specify environment */
    if (execle("/usr/bin/echo", "echo", "myarg1", "MY_ARG2", (char *)0, env_init) < 0)
    {
      err_sys("execle error");
    }
  }

  if (waitpid(pid, NULL, 0) < 0)
  {
    err_sys("wait error");
  }

  if ((pid = fork()) < 0)
  {
    err_sys("fork error");
  }
  else if (pid == 0)
  {
    /* specify filename, specify environment */
    if (execlp("echo", "echo", "only 1 arg", (char *)0, env_init) < 0)
    {
      err_sys("execlp error");
    }
  }
  exit(0);
}
