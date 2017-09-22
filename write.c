#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
#include "color.h"


#define WIDTH 40
#define HEIGHT 40
#define IMAGE_FILE "image.out"

int main(int argc, char const *argv[]) {

  int fd = open(IMAGE_FILE, O_RDWR);
  if (fd < 0) {
    perror("color library...");
    return fd;
  }
  for (int i = 0; i < WIDTH; ++i) {
    for (int j = 0; j < HEIGHT; ++j) {
      if (writeStruct(fd, i, j, WIDTH, HEIGHT, 0xFF - 6 * i, 6 * i, 6 * j) < 0) {
        close(fd);
        return EXIT_FAILURE;
      }
    }
  }


  for (int i = 0; i < WIDTH; ++i) {
    printf("<div>\n");
    for (int j = 0; j < HEIGHT; ++j) {
      Color c = readStruct(fd, i, j, WIDTH, HEIGHT);
      if (!c) {
        close(fd);
        return EXIT_FAILURE;
      }

      printColor(c);
      destroyColor(c);
    }
    printf("</div>\n");
  }

  close(fd);
  return 0;
}
