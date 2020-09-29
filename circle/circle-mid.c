// Draw the circle with the help of mid-point method.

#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/freeglut.h>

void init();
void display();
void drawCircle(int, int, int, int);
float x, y, cx, cy, r, h;

int main(int argc, char** argv)
{
  printf("Window size - 500x500 i.e. range of x and y is 0 -> 500\n");
  printf("Enter the co-ordinates of center:-\n");

  printf("x: ");
  scanf("%f", &cx);

  printf("y: ");
  scanf("%f", &cy);

  printf("Enter the radius of the circle: ");
  scanf("%f", &r);

  glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Circle using Mid-Point algorithm");

  init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}

void init()
{
  glClearColor(0.8, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0, 1, 0);
	glPointSize(5);
	glBegin(GL_POINTS);

  //Mid-point algorithm
  x = 0;
  y = r;
  drawCircle(cx, cy, x, y);

  h = 1 - r;
  while(x < y)
  {
    if(h < 0)
       h += 2*x + 3;
    else
    {
      h += 2*(x - y) + 5;
      y--;
    }
    x++;
    drawCircle(cx, cy, x, y);
  }

	glEnd();
	glFlush();
}

void drawCircle(int h, int k, int x, int y)
{
  glVertex2f(h+x, k+y);
  glVertex2f(h-x, k+y);
  glVertex2f(h+x, k-y);
  glVertex2f(h-x, k-y);
  glVertex2f(h+y, k+x);
  glVertex2f(h-y, k+x);
  glVertex2f(h+y, k-x);
  glVertex2f(h-y, k-x);
}
