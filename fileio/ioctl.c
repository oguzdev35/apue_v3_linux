#include "apue.h"
#include <fcntl.h>

#define WR_VALUE _IOW('a', 'a', int32_t *)
#define RD_VALUE _IOR('a', 'a', int32_t *)

int main(int argc, char const *argv[])
{
  int fd;

  int32_t val, num;
  printf("\nOpening the Driver\n");

  fd = open("/dev/random", O_RDWR);

  if (fd < 0)
  {
    err_sys("Unable to open the device file \n");
  }

  printf("Enter the value that you want to send \n");
  scanf("%d", &num);
  printf("Writing the value to the driver \n");
  ioctl(fd, WR_VALUE, (int32_t *)&num);
  printf("Reading the value from the driver \n");
  ioctl(fd, RD_VALUE, (int32_t *)&val);

  printf("The value is %d\n", val);

  printf("Closing the driver\n");

  close(fd);

  exit(0);
}
