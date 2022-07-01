/*
Modify the program in Figure 4.3 to use stat instead of lstat.
What changes if one of the command-line arguments is a symbolic link?

lstat() is identical to stat(), except that if pathname is a symbolic link,
then it returns information about the link itself, not the file that it refers to.
*/
#include "apue.h"

int main(int argc, char const *argv[])
{
  int i;
  struct stat buf;
  char *ptr;

  for (i = 1; i < argc; i++)
  {
    printf("%s", argv[i]);
    if (stat(argv[i], &buf) < 0)
    {
      err_ret("lstat error");
      continue;
    }
    if (S_ISREG(buf.st_mode))
    {
      ptr = "regular";
    }
    else if (S_ISREG(buf.st_mode))
    {
      ptr = "regular";
    }
    else if (S_ISDIR(buf.st_mode))
    {
      ptr = "directory";
    }
    else if (S_ISCHR(buf.st_mode))
    {
      ptr = "character special";
    }
    else if (S_ISBLK(buf.st_mode))
    {
      ptr = "block special";
    }
    else if (S_ISFIFO(buf.st_mode))
    {
      ptr = "fifo";
    }
    else if (S_ISLNK(buf.st_mode))
    {
      ptr = "symbolic link";
    }
    else if (S_ISSOCK(buf.st_mode))
    {
      ptr = "socket";
    }
    else
    {
      ptr = "unknown mode";
    }
    printf("\t%s\n", ptr);
  }

  exit(0);
}
