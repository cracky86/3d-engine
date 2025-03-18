#ifndef __HEADER_RENDER__
#define __HEADER_RENDER__

#include "typedefs.h"
#include "palette.h"

void render(char** framebuf) {
  for (int y=0; y<HEIGHT; y++) {
    for (int x=0; x<WIDTH; x++) {
      framebuf[y][x] = 0xff;
    }
  }
}

#endif
