#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/freeglut.h>
#include<math.h>

void display()
{ 
glClear(GL_COLOR_BUFFER_BIT);

//Points
glPointSize(5.0);
glColor3f(0,0,0);
glBegin(GL_POINTS);
glVertex2f(0.9,0.2);
glVertex2f(0.9,0.3);
glVertex2f(0.9,0.4);
glVertex2f(0.9,0.5);
glEnd();
glRasterPos2f(0.6,0.1);

//Line strips
glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2f(0.1,0.2);
glVertex2f(0.1,0.6);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2f(0.2,0.2);
glVertex2f(0.2,0.6);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2f(0.3,0.2);
glVertex2f(0.3,0.6);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2f(0.4,0.2);
glVertex2f(0.4,0.6);
glEnd();

glRasterPos2f(0.1,0.1);

//TRIANGLE

glColor3f(0,0,0); 
glBegin(GL_TRIANGLES);
glVertex2f(-0.1,0.2);
glVertex2f(-0.3,0.4);
glVertex2f(-0.5,0.2);
glEnd();

glRasterPos2f(-0.5,0.1);
//Square

glColor3f(1,1,1); 
glBegin(GL_QUADS);
glVertex2f(-0.6,0.2);
glVertex2f(-0.6,0.5);
glVertex2f(-0.9,0.5);
glVertex2f(-0.9,0.2);
glEnd();

glRasterPos2f(-0.9,0.1);

//PENTAGON
glColor3f(1,1,1); 
glBegin(GL_POLYGON);
glVertex2f(-0.1,-0.3);
glVertex2f(-0.1,-0.5);
glVertex2f(-0.3,-0.6);
glVertex2f(-0.5,-0.5);
glVertex2f(-0.5,-0.3);
glEnd();

glRasterPos2f(-0.5,-0.7);

//HEXAGON

glColor3f(0,0,0); 
glBegin(GL_POLYGON);
glVertex2f(-0.8,-0.2);
glVertex2f(-0.6,-0.3);
glVertex2f(-0.6,-0.5);
glVertex2f(-0.8,-0.6);
glVertex2f(-0.99,-0.5);
glVertex2f(-0.99,-0.3);
glEnd();
glRasterPos2f(-0.99,-0.7);


glColor3f(0,0,0);
glRasterPos2f(0.40,-0.70);

glFlush();
}



int main(int argc,char **argv)
{

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

glutInitWindowSize(700,600);
glutInitWindowPosition(200,200);

glutCreateWindow("PRIMITIVES");
glClearColor(0,2,2,1);
glutDisplayFunc(display);
glutMainLoop();
}


