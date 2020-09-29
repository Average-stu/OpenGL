// Draw the circle with the help of polar equations.

#include<stdio.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/freeglut.h>
#include<math.h>
#define PI 3.14

void init();
void display();
float x, y, h, k, r, degree, radian;

int main(int argc, char** argv)
{
  printf("Window size - 500x500 i.e. range of x and y is 0 -> 500\n");
  printf("Enter the co-ordinates of center:-\n");

  printf("x: ");
  scanf("%f", &h);

  printf("y: ");
  scanf("%f", &k);

  printf("Enter the radius of the circle: ");
  scanf("%f", &r);

  glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Circle using Polar Equations");

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

  glColor3f(0, 0, 1);
	glPointSize(5);
	glBegin(GL_POINTS);

  for(degree = 0; degree < 360; degree++)
  {
		radian = degree * PI / 180;
    x = h + r*cos(radian);
    y = k + r*sin(radian);
    glVertex2f(x, y);
  }
  
	glEnd();
	glFlush();
}





