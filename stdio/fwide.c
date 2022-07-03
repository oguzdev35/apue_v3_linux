#include "apue.h"
#include <wchar.h>

int main(int argc, char const *argv[])
{
  FILE *fpw;
  char fname_wide[] = "widetest.txt";
  int widemodeflag = 1;
  int result;

  wchar_t widestring[] = L"How many umlauts are there in Fahrvergnügen?\n";

  if ((fpw = fopen(fname_wide, "a")) == NULL)
  {
    err_sys("Opening output file");
  }

  /*Set file to wide-character orientation:*/
  widemodeflag = fwide(fpw, widemodeflag);
  if (widemodeflag <= 0)
  {
    err_sys("Unable to set output file %s to wide characters");
  }

  /* Write wide-character string to the file */
  result = fputws(widestring, fpw);

  printf("result: %d\n", result);

  exit(0);
}
