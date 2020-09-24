#include<GL/glut.h>
void display()
{
glClearColor(1.0,1.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);//line will appear colored
glLineWidth(60);//line will appear broad
//glPointSize(50); point size inc or dec
glBegin(GL_LINES);//GL_POINTS can also be used
glVertex3f(0.1,0.1,0.1);// f is used for float
glVertex3f(15.0,0.0,0.0);
glEnd();
glutSwapBuffers();
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(712,512);
glutCreateWindow(argv[0]);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

