#include<GL/glut.h>
#include<iostream>

GLint x1=0,y1=0,x2=0,y2=0;
GLint count = 0;

void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-200,200,-200,200.0);
}

void plotPoint(GLfloat x,GLfloat y)
{
 glPointSize(2);
 glBegin(GL_POINTS);
  glVertex2f(x,y);
 glEnd();
}

void ddaLine(GLint x1,GLint y1,GLint x2,GLint y2)
{
 //drawing axes
 glColor3f(0.0,0.0,1.0);
 glBegin(GL_LINES);
  glVertex2i(-200,0);
  glVertex2i(200,0);
  glVertex2i(0,-200);
  glVertex2i(0,200);
 glEnd();

 //plot origin
 glColor3f(0.1,1.0,0.1);
 glPointSize(6);
 glBegin(GL_POINTS);
  glVertex2i(0,0);
 glEnd();
 glColor3f(1.0,0.0,0.0);

 //drawing intended line using DDA
 GLint dx = x2-x1, dy = y2-y1, length;
 float xinc,yinc, x=x1, y=y1;

 if (abs(dx) > abs(dy))
  length = abs(dx);
 else
  length = abs(dy); 
  
 xinc = GLfloat(dx)/length; 
 yinc = GLfloat(dy)/length; 

 plotPoint(x,y);
 
 for(int i=0;i<length;i++)
 {
  x = x+xinc;
  y = y+yinc;
  plotPoint(x,y);
  printf("%f %f\n",x,y);
  glFlush();
 }
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 ddaLine(-70,-10,-50,90); //m > 1 steep,positive
 ddaLine(-10,-70,90,-50); //m < 1 gentle positive
 ddaLine(-10,70,90,50);   //m > -1 gentle negative
 ddaLine(70,-10,50,90);   //m < -1 steep negative
}

//dont use winReshape
/*void winReshape(GLint nw, GLint nh)
{
 glViewport(0,0,nw,nh);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0,GLdouble(nw),0.0,GLdouble(nh));
 ww = nw;
 wh = nh;
}*/

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,100);
 glutInitWindowSize(400,400);
 glutCreateWindow("Line Drawing: DDA");
 
 init();
 glutDisplayFunc(display);
 //glutReshapeFunc(winReshape);

 glutMainLoop();
 return 0;
}
