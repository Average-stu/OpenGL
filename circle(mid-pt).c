//1. Draw the circle with the help of mid-point method.
//CODE:
#include<GL/glut.h>
#include<stdio.h>
int xc,yc,r,sizes=100;
void myInit(void)
{   glClearColor(1.0,1.0,0.0,0.0);
    glColor3f(0.0f,0.0f,1.0f);
    glPointSize(6.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(100,-100,100,-100);
    glOrtho(-sizes/2,sizes/2,-sizes/2,sizes/2,-1,1);    }
void readInput()
{   printf("Enter x, y and radius: ");
    scanf("%i %i %i",&xc,&yc,&r);     }
void setPixel(int x, int y)
{    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();     }
void draw_axis()
{    int i=(-sizes)/2;
    for(;i<(sizes/2);i++)
    {   setPixel(i,0);
        setPixel(0,i);
    }     }
void draw_oct(int xk,int yk,int xc,int yc)
{   setPixel(xc+xk,yc+yk);
    setPixel(xc+yk,yc+xk);
    setPixel(xc-yk,yc+xk);
    setPixel(xc-xk,yc+yk);
    setPixel(xc-xk,yc-yk);
    setPixel(xc-yk,yc-xk);
    setPixel(xc+yk,yc-xk);
    setPixel(xc+xk,yc-yk);     }
void midPtCircle(int xc,int yc,int r)
{   int pk,xk,yk;
    pk=1-r;
    xk=0;
    yk=r;
    draw_oct(xk,yk,xc,yc);
    while(xk<=yk)
    {   if(pk<0)
        {    xk=xk+1;
            pk=pk+(2*xk)+1;      }
        else
        {    xk=xk+1;
            yk=yk-1;
            pk=pk+(2*xk)+1-(2*yk);    }
        draw_oct(xk,yk,xc,yc);    }     }
void Display(void)
{    glClear(GL_COLOR_BUFFER_BIT);
    draw_axis();
    midPtCircle(xc,yc,r);      }
int main(int argc,char *argv[])
{   glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Mid Point Circle");
    readInput();
    glutDisplayFunc(Display);
    myInit();
    glutMainLoop();
    return 0;
}
