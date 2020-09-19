#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
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
void BresenhamCircle(int xc,int yc,int r)  
   {  
    int x=0,y=r,d=3-(2*r);  
    draw_oct(xc,yc,x,y);  
  
    while(x<=y)  
     {  
      if(d<=0)  
    {  
        d=d+(4*x)+6;  
    }  
     else  
      {  
        d=d+(4*x)-(4*y)+10;  
        y=y-1;  
      }  
       x=x+1;  
       draw_oct(xc,yc,x,y);  
      }  
    }  
void Display(void)
{    glClear(GL_COLOR_BUFFER_BIT);
    //draw_axis();
    BresenhamCircle(xc,yc,r);      }
int main(int argc,char *argv[])
{   glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Bresenham-circle ");
    readInput();
    glutDisplayFunc(Display);
    myInit();
    glutMainLoop();
    return 0;
}
