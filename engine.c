#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h> 
#include <math.h>

#define pi 3.142857
#define WIDTH 640
#define HEIGHT 480

#include "typedefs.h"
#include "palette.h"
#include "render.h"

char** framebuf;

color palette[256];

// function to initialize 
void myInit(void) {

  glClearColor(0.0, 1.0, 0.0, 1.0);
  
  glPointSize(1.0); 
  glMatrixMode(GL_PROJECTION);  
  glLoadIdentity(); 
      
  // setting window dimension in X- and Y- direction 
  gluOrtho2D(0, WIDTH, 0, HEIGHT);
} 
  
void display(void) {
  glClear(GL_COLOR_BUFFER_BIT); 
  glBegin(GL_POINTS);   

  color* col;
  
  unsigned int r;
  unsigned int g;
  unsigned int b;

  render(framebuf);
  
  for (int y=0; y<HEIGHT; y++) {
    for (int x=0; x<WIDTH; x++) {

      col = &palette[framebuf[y][x]&0xff];
      
      glColor3ub(col->r, col->g, col->b);
      
      glVertex2i(x,y);
    }
  }
  
  glEnd(); 
  glFlush(); 
} 
  
int main(int argc, char** argv) {
  framebuf = (char**)malloc(HEIGHT * sizeof(char*));
  
  for (int y=0; y<HEIGHT; y++) {
    framebuf[y] = (char*)malloc(WIDTH * sizeof(char));
  }
  initPalette(palette);

  
  
  glutInit(&argc, argv); 
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
  // giving window size in X- and Y- direction 
  glutInitWindowSize(WIDTH, HEIGHT); 
  glutInitWindowPosition(0, 0); 
      
  // Giving name to window 
  glutCreateWindow(":3"); 
  myInit();
      
  glutDisplayFunc(display); 
  glutMainLoop(); 
} 
