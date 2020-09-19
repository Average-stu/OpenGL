#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>
#include<stdio.h>
void display()
{
float y,c,m;
int x;
printf("Enter the slope -");
scanf("%f",&m);
printf("Enter the y-intercept -");
scanf("%f",&c);
int X[10],Y[10];
for(x=0;x<10;x++)
{
y=round(m*x+c);
X[x]=x;
Y[x]=y;
}
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,0,1);
glBegin(GL_LINES);
for(x=0;x<10;x++)
glVertex2f(X[x],Y[x]);
glEnd();
glColor3f(1,1,1);
glRasterPos2f(-0.8,-0.5);
glPointSize(4);
glRasterPos2f(-0.9,-0.8);
glPointSize(4);
glFlush();
}


int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1200,750);
glutInitWindowPosition(500,300);
glutCreateWindow("Line");
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
