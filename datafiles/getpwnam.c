#include "apue.h"
#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd *getpwnam(const char *name)
{
  struct passwd *ptr;
  setpwent();

  while ((ptr = getpwent()) != NULL)
  {
    if (strcmp(name, ptr->pw_name) == 0)
    {
      break; /* found */
    }
  }

  endpwent();

  return ptr;
}

int main(int argc, char const *argv[])
{

  struct passwd *ptr;
  ptr = getpwnam(argv[1]);

  if (ptr != NULL)
  {
    printf("%d\n", ptr->pw_uid);
  }

  return 0;
}
