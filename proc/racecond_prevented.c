#include "apue.h"

static void charatatime(char *);

int main(int argc, char const *argv[])
{
  pid_t pid;

  TELL_WAIT();

  if ((pid = fork()) < 0)
  {
    err_sys("fork error");
  }
  else if (pid == 0)
  {
    charatatime("output from child\n");
    TELL_PARENT(getppid()); /* parent goes first */
  }
  else
  {
    WAIT_CHILD();
    charatatime("output from parent\n");
  }
  exit(0);
}

static void charatatime(char *str)
{

  char *ptr;
  int c;

  setbuf(stdout, NULL); /* set unbuffered */
  for (ptr = str; (c = *ptr++);)
  {
    putc(c, stdout);
  }
}