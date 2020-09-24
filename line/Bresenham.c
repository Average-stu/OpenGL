#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
double X1, Y1, X2, Y2;
void bresenham(void)
{    double dx=(X2-X1);
double dy=(Y2-Y1);
double pk = 2 * (dy) - (dx);
float x=X1,y=Y1;
double temp;
if(dy > dx)
{    temp = dx; 
dx = dy; 
dy = temp;   }
glClear(GL_COLOR_BUFFER_BIT);  
glBegin(GL_POINTS);   
glVertex2d(x,y);  
int k;
for(k=0;k<dx-1;++k)  
{    if(pk<0)
  {  pk=pk+2*dy;   }
  else
  {  pk=pk+2*dy-2*dx;
   ++y;  }
  ++x;
  glVertex2d(x,y);   }
glEnd();
glFlush();   }
void Init()
{   glClearColor(0.0,0.0,0.0,0);  
  glColor3f(0.0,0.0,1.0);  
  gluOrtho2D(0 , 640 , 0 , 480);   }
void main(int argc, char **argv)
{   printf("Enter two end points of the line to be drawn:\n");
  printf("\n************************************");
  printf("\nEnter Point1( X1 , Y1):\n");
  scanf("%lf%lf",&X1,&Y1);
  printf("\n************************************");
  printf("\nEnter Point1( X2 , Y2):\n");
  scanf("%lf%lf",&X2,&Y2);
glutInit(&argc,argv);   
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
glutInitWindowPosition(0,0);  
glutInitWindowSize(640,480);
glutCreateWindow("Bresenham");   
Init();  
glutDisplayFunc(bresenham);  
glutMainLoop();   }

