// Draw a line using DDA algorithm for slope m<1 and m>1.

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
double X1, Y1, X2, Y2;
float round_value(float v)
{
  return floor(v + 0.5);
}
void LineDDA(void)
{
  double dx=(X2-X1);
  double dy=(Y2-Y1);
  double steps;
  float xInc,yInc,x=X1,y=Y1;
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));// Find out whether to increment x or y
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;
  glClear(GL_COLOR_BUFFER_BIT);//Clears buffers to preset values 
  glBegin(GL_POINTS);  // Plot the points
  glVertex2d(x,y);  // Plot the first point
  int k;
  for(k=0;k<steps;k++)// For every step, find an intermediate vertex
  {
    x+=xInc;
    y+=yInc;
    glVertex2d(round_value(x), round_value(y));
  }
  glEnd();
  glFlush();
}
void Init()
{   glClearColor(0.0,0.0,0.0,0);  
  glColor3f(0.0,0.0,1.0);  
  gluOrtho2D(0 , 640 , 0 , 480);   }
int main(int argc, char **argv)
{
  printf("Enter two end points of the line to be drawn:\n");
  printf("\n************************************");
  printf("\nEnter Point1( X1 , Y1):\n");
  scanf("%lf%lf",&X1,&Y1);
  printf("\n************************************");
  printf("\nEnter Point1( X2 , Y2):\n");
  scanf("%lf%lf",&X2,&Y2);
  glutInit(&argc,argv);//Initialise GLUT library
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the initial display mode
  glutInitWindowPosition(0,0);//Set the initial window position and size
  glutInitWindowSize(640,480);//Create the window with title "DDA_Line"
  glutCreateWindow("DDA_Line");
  Init();//Initialize drawing colors
  glutDisplayFunc(LineDDA);//Call the displaying function
  glutMainLoop();//Keep displaying untill the program is closed
}
