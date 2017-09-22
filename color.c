#include "color.h"


struct _color {
  byte r, g, b;
};

int writeStruct(int fd, int x, int y, int width, int height, byte r, byte g, byte b) {
  color c;
  c.r = r;
  c.g = g;
  c.b = b;

  if (lseek(fd, (y * width + x) * sizeof(color), SEEK_SET) < 0) {
    return -1;
  }

  int err = write(fd, &c, sizeof(color));
  return err;
}

Color readStruct(int fd, int x, int y, int width, int height) {

  return NULL;
}


void printColor(Color c) {
  printf("<div style='display:inline; min-height:20px;min-width:20px;background:#%02x%02x%02x;color:#%02x%02x%02x'>20</div>\n", c->r, c->g, c->b, c->r, c->g, c->b);
}


void destroyColor(Color c) {
  free(c);
}
