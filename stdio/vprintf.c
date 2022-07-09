#include "apue.h"
#include <stdarg.h>

void writeFrmtd(char *format, ...)
{
  va_list args;

  va_start(args, format);
  vprintf(format, args);
  va_end(args);
}

int main(int argc, char const *argv[])
{
  writeFrmtd("Hello World %d\n", 12);
  writeFrmtd("My name is %s\n, I am %d years old!\n", "Oğuz", 19);
  exit(0);
}
