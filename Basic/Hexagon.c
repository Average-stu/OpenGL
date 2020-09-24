#include <GL/glut.h>
void hexagon (void) {
    glBegin(GL_QUADS); 
 glColor3f(1,1,1);
 glVertex3f(0.0, 0.4, 0);
 glVertex3f(-0.3, 0.2, 0);
 glVertex3f(-0.3,-0.2, 0);
 glVertex3f(0.3, 0.2, 0);
 glEnd();//end the shape we are currently working on
 glBegin(GL_QUADS); 
 glColor3f(1,1,1);
 glVertex3f(-0.3, -0.2, 0);
 glVertex3f(0.0, -0.4, 0);
 glVertex3f(0.3,-0.2, 0);
 glVertex3f(0.3, 0.2, 0);
 glEnd();//end the shape we are currently working on
}
void display (void) {
glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();
hexagon();
glFlush();}
int main (int argc, char **argv) {
glutInit (&argc, argv);
glutInitDisplayMode (GLUT_SINGLE);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("A basic OpenGL Window");
glutDisplayFunc (display);
glutMainLoop ();
return 0;
}

