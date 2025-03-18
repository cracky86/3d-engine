#ifndef __HEADER_PALETTE__
#define __HEADER_PALETTE__

#include "typedefs.h"

// Initialize default palette
void initPalette(color* pal) {
  for (int i=0; i<256; i++) {
    pal[i].r = (((i >> 5) & 0x07) * 36);
    pal[i].g = (((i >> 2) & 0x07) * 36);
    pal[i].b = ((i & 0x03) * 85);
  }
}

#endif
