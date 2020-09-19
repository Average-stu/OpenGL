#include<GL/glut.h>
#include<stdio.h>

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

void bresLine(GLint x1,GLint y1,GLint x2,GLint y2)
{
 //drawing axes
 glColor3f(0.0,1.0,0.0);
 glBegin(GL_LINES);
  glVertex2i(-200,0);
  glVertex2i(200,0);
  glVertex2i(0,-200);
  glVertex2i(0,200);
 glEnd();

 //plot origin
 glColor3f(0.0,0.0,0.0);
 glPointSize(4);
 glBegin(GL_POINTS);
  glVertex2i(0,0);
 glEnd();
 glColor3f(0.0,0.0,1.0);

 //drawing intended line using DDA
 /*GLint dx = x2-x1 , dy = y2-y1;
 GLfloat m = dy/dx;
 if(m<1)	//gentle positive
 {
 GLint x = x1 , y = y1;
 GLint dT = (2*dy) - (2*dx);
 GLint dS = 2*dy;
 
 GLint d = (2*dy) - dx;
 
 while(x<=x2)
 {
	plotPoint(x,y);
	x++;
	if(d<0)
	{
		d = d + dS;
	}
	else
	{
		y++;
		d = d + dT;
	}
 }
 glFlush();
 }

 else if(m>1)		//steep positive	
 {
 GLint x = y1 , y = x1;
 GLint dT = (2*dy) - (2*dx);
 GLint dS = 2*dy;
 
 GLint d = (2*dy) - dx;
 
 while(x<=x2){
	plotPoint(x,y);
	x++;
	if(d<0)
	{
		d = d + dS;
	}
	else
	{
		y++;
		d = d + dT;
	}
 }
 glFlush();
 }
else if(m>-1)		//steep positive	
 {
 GLint x = x1 , y = -y1;
 GLint dT = (2*dy) - (2*dx);
 GLint dS = 2*dy;
 
 GLint d = (2*dy) - dx;
 
 while(x<=x2){
	plotPoint(x,y);
	x++;
	if(d<0)
	{
		d = d + dS;
	}
	else
	{
		y++;
		d = d + dT;
	}
 }
 glFlush();
 }
else 
{
 GLint x = -x1 , y = y1;
 GLint dT = (2*dy) - (2*dx);
 GLint dS = 2*dy;
 
 GLint d = (2*dy) - dx;
 
 while(x<=x2){
	plotPoint(x,y);
	x++;
	if(d<0)
	{
		d = d + dS;
	}
	else
	{
		y++;
		d = d + dT;
	}
 }
 glFlush();
 }
*/
int dx, dy, i, e;
int incx, incy, inc1, inc2;
int x,y;

dx = x2-x1;
dy = y2-y1;

if (dx < 0) dx = -dx;
if (dy < 0) dy = -dy;
incx = 1;
if (x2 < x1) incx = -1;
incy = 1;
if (y2 < y1) incy = -1;
x = x1; y = y1;
if (dx > dy) {
plotPoint(x, y);
e = 2 * dy-dx;
inc1 = 2*(dy-dx);
inc2 = 2*dy;
for (i=0; i<dx; i++) {
if (e >= 0) {
y += incy;
e += inc1;
}
else
e += inc2;
x += incx;
plotPoint(x, y);
}

} else {
plotPoint(x, y);
e = 2*dx-dy;
inc1 = 2*(dx-dy);
inc2 = 2*dx;
for (i=0; i<dy; i++) {
if (e >= 0) {
x += incx;
e += inc1;
}
else
e += inc2;
y += incy;
plotPoint(x, y);
}
}

glFlush();

}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 bresLine(-70,-10,-50,90); //m > 1 steep,positive
 bresLine(-10,-70,90,-50); //m < 1 gentle positive
 bresLine(-10,70,90,50);   //m > -1 gentle negative
 bresLine(70,-10,50,90);   //m < -1 steep negative
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
 glutCreateWindow("Line Drawing: Bresenham");
 
 init();
 glutDisplayFunc(display);
 //glutReshapeFunc(winReshape);

 glutMainLoop();
 return 0;
}
