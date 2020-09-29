// Draw the Ellipse with the mid-point method.

#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/freeglut.h>
#include<math.h>

void init();
void display();
void plotPoint(int, int, int, int);
float x, y, a, b, d1, d2, cx, cy;

int main(int argc, char** argv)
{
  printf("Window size - 500x500 i.e. range of x and y is 0 -> 500\n");

  printf("Enter the co-ordinates of center:-\n");

  printf("x: ");
  scanf("%f", &cx);

  printf("y: ");
  scanf("%f", &cy);

  printf("Enter radius of major axis: ");
  scanf("%f", &a);

  printf("Enter radius of minor axis: ");
  scanf("%f", &b);

  glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Ellipse using Mid-Point algorithm");

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

  glColor3f(0.211, 0.211, 0.211);
	glPointSize(5);
	glBegin(GL_POINTS);

  //Mid-point algorithm
  x = 0;
  y = b;

  plotPoint(cx, cy, x, y);

  d1 = pow(b, 2) + (pow(a, 2))*((1/4) - b);
  while(x*pow(b, 2) <= y*pow(a, 2))
  {
    if(d1 < 0)
       d1 += pow(b,2)*(2*x + 3);
    else
    {
      d1 += pow(b,2)*(2*x + 3) - pow(a, 2)*(2*y - 2);
      y--;
    }
    x++;
    plotPoint(cx, cy, x, y);
  }

  d2 = pow(b,2)*pow((x + 1/2), 2) + pow(a, 2)*pow((y - 1), 2) - pow(a,2)*pow(b,2);
  while(y != 0)
  {
    if(d2 < 0)
    {
       d2 += 2*pow(b,2)*(x + 1) - pow(a, 2)*(2*y - 3);
       x++;
    }
    else
      d2 += pow(a, 2)*(3 - 2*y);

    y--;
    plotPoint(cx, cy, x, y);
  }

	glEnd();
	glFlush();
}

void plotPoint(int h, int k, int x, int y)
{
  glVertex2f(h+x, k+y);
  glVertex2f(h-x, k+y);
  glVertex2f(h+x, k-y);
  glVertex2f(h-x, k-y);
}
