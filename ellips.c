#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
double dx, dy, d1, d2, x, y;
double rx, ry, xc=50, yc=50;
float round_value(float v)
{
 return floor(v + 0.5);
}
void midptellipse() 
{  
    x = 0; 
    y = ry;   
    // Initial decision parameter of region 1 
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx); 
    dx = 2 * ry * ry * x; 
    dy = 2 * rx * rx * y; 
   glClear(GL_COLOR_BUFFER_BIT);   
   glBegin(GL_POINTS);
    while (dx < dy)
     {        
       glVertex2d(x + xc, y + yc); 
       glVertex2d(-x + xc, y + yc); 
       glVertex2d(x + xc, -y + yc); 
       glVertex2d(-x + xc, -y + yc); 
        if (d1 < 0) { 
            x++; 
            dx = dx + (2 * ry * ry); 
            d1 = d1 + dx + (ry * ry); 
        } 
        else { 
            x++; 
            y--; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d1 = d1 + dx - dy + (ry * ry); 
        }     }   
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5)))    // Decision parameter of region 2
         + ((rx * rx) * ((y - 1) * (y - 1))) 
         - (rx * rx * ry * ry); 
    while (y >= 0) 
    { 
        glVertex2d(x + xc, y + yc); 
        glVertex2d(-x + xc, y + yc); 
        glVertex2d(x + xc, -y + yc); 
        glVertex2d(-x + xc, -y + yc);               
        if (d2 > 0) { 
            y--; 
            dy = dy - (2 * rx * rx); 
        d2 = d2 + (rx * rx) - dy;   } 
        else { 
            y--; 
            x++; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d2 = d2 + dx - dy + (rx * rx); 
        }     }
   glEnd(); 
   glFlush();
}
void Init()      { 
glClearColor(1.0,1.0,1.0,0);/* Set clear color to white */
glColor3f(0.0,0.0,0.0); /* Set fill color to black */
gluOrtho2D(-640 , 640 , -640 , 640);     
    }
void main(int argc, char **argv)     
     {
 printf("\nEnter minor radius( X1 , Y1):\n");
 scanf("%lf",&rx);
 printf("\nEnter minor radius( X1 , Y1):\n");
 scanf("%lf",&ry);
  glutInit(&argc,argv);/* Initialise GLUT library */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);/* Set the initial display mode */
  glutInitWindowPosition(0,0);/* Set the initial window position and size */
  glutInitWindowSize(640,480);
  glutCreateWindow("Ellipse");/* Create the window with title "DDA_Line" */
Init();/* Initialize drawing colors */
glutDisplayFunc(midptellipse);/* Call the displaying function */
glutMainLoop();  /* Keep displaying untill the program is closed */
}
