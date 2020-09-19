//1. Draw a line using equation of line Y=m*X+C.
//CODE:

#include<GL/glut.h>
#include<stdio.h>
float a,b;
float c,d;
float roundoff(float y)
{
y=(y+0.5);
return y;
}  
void display()
{
glClear(GL_COLOR_BUFFER_BIT);


//scanf("%d",&d);


float m = (d-b)/(c-a);   // formula incorrect
//float e = b-(m*a);
float e=2;
printf("%f%f",m,e);
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_STRIP);
for(int x=a;x<=c;x++)
{
float y=(m*x)+e;
y=roundoff(y);

printf("%d %f",x,y);
glVertex2f(x,y);

}
glEnd();

glFlush();
}
int main(int argc, char **argv){
printf("enter the first coordinates");
scanf("%f%f",&a,&b);
//scanf("%d",&b);
printf("enter the Second coordinates");
scanf("%f%f",&c,&d);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1000,1000);
glutCreateWindow("Line");
gluOrtho2D(-100,100,-100,100);
glClearColor(0.0,0.0,1.0,0.0);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
