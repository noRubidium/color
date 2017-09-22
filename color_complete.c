#include "color.h"


struct _color {
  byte r, g, b;
};

int writeStruct(int fd, int x, int y, int width, int height, byte r, byte g, byte b) {
  color c;
  c.r = r;
  c.g = g;
  c.b = b;

  int err = lseek(fd, (width * x + y) * sizeof(color), SEEK_SET);
  if (err < 0) {
    return err;
  }

  err = write(fd, &c, sizeof(color));

  return err;
}

Color readStruct(int fd, int x, int y, int width, int height) {
  Color c = calloc(1, sizeof(color));
  int err = lseek(fd, (width * x + y) * sizeof(color), SEEK_SET);
  if (err < 0) {
    return NULL;
  }
  read(fd, c, sizeof(color));
  return c;
}


void printColor(Color c) {
  printf("<div style='display:inline; min-height:20px;min-width:20px;background:#%02x%02x%02x;color:#%02x%02x%02x'>20</div>\n", c->r, c->g, c->b, c->r, c->g, c->b);
}


void destroyColor(Color c) {
  free(c);
}
