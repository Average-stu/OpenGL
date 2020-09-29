#include<stdio.h>
#include<GL/glut.h>
#include<GL/freeglut.h>
#include<math.h>


int xmin, ymin, xmax, ymax; // Windows boundaries
int x_0, y_0, x_1, y_1; // Line end-points

int ComputeTBRLCode(int x, int y)
{
  int code = 0; // Calculating TBLR code for a end-point
  if(y > ymax)  //above the window
    code = code | 8 ;      // TBRl - 1000 - Top
  if(y < ymin)  //below the window
    code = code | 4 ;      // TBRL  - 0100  - Bottom
  if(x > xmax)  //to the right of window
    code = code | 2 ;      // TBRL - 00100   - Right
  if(x < xmin)  //to the left of window
    code = code | 1 ;     // TBRL  - 0001     - left
  return code;
}

void CohenSutherland()
{
  int code_0, code_1, code_outside;
  int inside = 0, loop = 0;

  //Calculating TBLR code for end-points
  code_0 = ComputeTBRLCode(x_0, y_0);
  code_1 = ComputeTBRLCode(x_1, y_1);

  while(!loop)
  {
    if(!(code_0 | code_1)) // Check if logical OR is 0 or not
    {
      inside = 1; loop = 1;
    }
    else
      if(code_0 & code_1)  // Check if logical AND is 0
        loop = 1;
      else
      {
        int x, y;

        code_outside = code_0 ? code_0 : code_1;

        //Finding intersection point
        if(code_outside & 8 ) //point is above the window
        {
          x = x_0 + (x_1 - x_0) * (ymax - y_0) / (y_1 - y_0);
          y = ymax;
        }
        else if(code_outside & 4) //point is below the window
        {
          x = x_0 + (x_1 - x_0) * (ymin - y_0) / (y_1 - y_0);
          y = ymin;
        }
        else if(code_outside & 2) //point is to the right of window
        {
          y = y_0 + (y_1 - y_0) * (xmax - x_0) / (x_1 - x_0);
          x = xmax;
        }
        else //point is to the left of the window
        {
          y = y_0 + (y_1 - y_0) * (xmin - x_0) / (x_1 - x_0);
          x = xmin;
        }

        if(code_outside == code_0)
        {
          x_0 = x;
          y_0 = y;
          code_0 = ComputeTBRLCode(x_0, y_0);
        }
        else
        {
          x_1 = x;
          y_1 = y;
          code_1 = ComputeTBRLCode(x_1, y_1);
        }
      }
    }

    if(inside) //If line is completely inside or partially inside
    {
      //Drawing window
      glColor3f(0, 1, 0);
      glLineWidth(10);
      glBegin(GL_LINE_LOOP);
        glVertex2f(xmin, ymin);
        glVertex2f(xmax, ymin);
        glVertex2f(xmax, ymax);
        glVertex2f(xmin, ymax);
      glEnd();
      glFlush();

      //Drawing line
      glColor3f(0.211, 0.211, 0.211);
      glLineWidth(10);
      glBegin(GL_LINES);
        glVertex2d(x_0, y_0);
        glVertex2d(x_1, y_1);
      glEnd();
      glFlush();
    }
    else //line is completely outside
    {
      //Drawing window
      glColor3f(0, 1, 0);
      glLineWidth(10);
      glBegin(GL_LINE_LOOP);
        glVertex2f(xmin, ymin);
        glVertex2f(xmax, ymin);
        glVertex2f(xmax, ymax);
        glVertex2f(xmin, ymax);
      glEnd();
      glFlush();
    }
}

void Keyboard(unsigned char key, int x, int y)
{
	if(key == 'l')
  {
    //Drawing again with clipped part
    glClearColor(0.8, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
	  CohenSutherland();
  }
}

void display()
{
  //Drawing without clipping
  glClear(GL_COLOR_BUFFER_BIT);

  //Drawing window
  glColor3f(0, 1, 0);
  glLineWidth(10);
  glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
  glEnd();

  //Drawing line
  glColor3f(0.211, 0.211, 0.211);
  glLineWidth(10);
  glBegin(GL_LINES);
    glVertex2d(x_0, y_0);
    glVertex2d(x_1, y_1);
  glEnd();

  glFlush();
}

void init()
{
    glClearColor(0.8, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
  printf("Window size - 500x500 \n range of x and y is 0 -> 500\n\n");

  printf("\nEnter window boundaries:-\n");
  printf("Enter xmin: ");
  scanf("%d", &xmin);
  printf("Enter ymin: ");
  scanf("%d", &ymin);
  printf("Enter xmax: ");
  scanf("%d", &xmax);
  printf("Enter ymax: ");
  scanf("%d", &ymax);

  printf("\nEnter end-points of line:-\n");
  printf("Enter x0: ");
  scanf("%d", &x_0);
  printf("Enter y0: ");
  scanf("%d", &y_0);
  printf("Enter x1: ");
  scanf("%d", &x_1);
  printf("Enter y1: ");
  scanf("%d", &y_1);

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Cohen Sutherland Line-Clipping Algorithm");

  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(Keyboard);
  glutMainLoop();

  return 0;
}
