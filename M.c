#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#include <math.h>
void display()
{
float y,c,m;
int x;
printf("Enter slove and value of c");
scanf("%f%f",&m,&c);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
glBegin(GL_LINES);
for(x=0;x<10;x++)
{
y=round(m*x+c);
glVertex2f(x,y);
}
glEnd();
glFlush();
}
int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(650,600);
glutInitWindowPosition(100,100);
glutCreateWindow("line");
glClearColor(0,0,0,0);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}