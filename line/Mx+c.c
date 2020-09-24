#include<GL/glut.h>
#include<stdio.h>
float roundoff(float y)
{
y=(y+0.5);
return y;
}  
void display()
{
glClearColor(1.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(0.0,1.0,0.0);
glLineWidth(0.5);//to increse width
int a,b;
int c,d;
printf("enter the first coordinates");
scanf("%d",&a);
scanf("%d",&b);
printf("enter the Second coordinates");
scanf("%d",&c);
scanf("%d",&d);
float m = (b-d)/(c-a);
float e = b-(m*a);
for(int x=a;x<=c;x++)
{
float y=(m*x)+e;
y=roundoff(y);
glBegin(GL_LINES);
glVertex2f(x,y);
}
glutSwapBuffers();
glFlush();
}
int main(int argc, char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(1000,1000);
glutCreateWindow(DDA_Line);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

