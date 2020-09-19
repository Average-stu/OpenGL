#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<math.h>
void init()
{
glClearColor(0.364, 0.913, 0.976, 0.976);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,600,0,400);
}

void display()
{
int x, y, temp_int;
float temp;
glClear(GL_COLOR_BUFFER_BIT);

//grass
glColor3f(0,0.5,0); 
glBegin(GL_QUADS);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(600,150);
glVertex2f(600,0);
glEnd(); 

//sun
x = 40;
y = 340;
glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2d(x,y);
while(x < 120)
{
x = x + 1;
temp = sqrt(pow(40,2)-pow(x-80,2));
temp_int = temp+0.5;
glVertex2d(x,y+temp_int); 
glVertex2d(x,y-temp_int);
}
glEnd();
//mt1
glColor3f(0.647059,0.164706,0.164706); 
glBegin(GL_TRIANGLES); 
glVertex2f(0,150);
glVertex2f(120,300);
glVertex2f(200,150);
glEnd();
//mt2
glColor3f(0.647059,0.164706,0.164706); 
glBegin(GL_TRIANGLES); 
glVertex2f(200,150);
glVertex2f(300,300);
glVertex2f(400,150);
glEnd();
//mt3
glColor3f(0.647059,0.164706,0.164706); 
glBegin(GL_TRIANGLES); 
glVertex2f(400,150);
glVertex2f(520,330);
glVertex2f(600,150);
glEnd();
//hut
//s1
glColor3f(0.976, 0.913, 0.364); 
glBegin(GL_QUADS);
glVertex2f(200,50);
glVertex2f(200,90);
glVertex2f(220,80);
glVertex2f(220,40);
glEnd();
//s2
glColor3f(0.623, 0.901, 0.976); 
glBegin(GL_QUADS);
glVertex2f(220,40);
glVertex2f(220,80);
glVertex2f(330,80);
glVertex2f(330,40);
glEnd();
//s3
glColor3f(0.729, 0.152, 0.050); 
glBegin(GL_QUADS);
glVertex2f(220,80);
glVertex2f(210,130);
glVertex2f(320,130);
glVertex2f(330,80);
glEnd();
//s4
glColor3f(0.831, 0.184, 0.066); 
glBegin(GL_TRIANGLES);
glVertex2f(200,90);
glVertex2f(210,130);
glVertex2f(220,80);
glEnd();
//window
glColor3f(0.286, 0.670, 0.643); 
glBegin(GL_QUADS);
glVertex2f(250,50);
glVertex2f(250,70);
glVertex2f(280,70);
glVertex2f(280,50);
glEnd();
glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2f(250,60);
glVertex2f(280,60);
glEnd();
glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2f(265,50);
glVertex2f(265,70);
glEnd();
//door
glColor3f(0.552, 0.121, 0.086); 
glBegin(GL_QUADS);
glVertex2f(205,48);
glVertex2f(205,70);
glVertex2f(215,65);
glVertex2f(215,43);
glEnd();
//road
glColor3f(0.278, 0.278, 0.278); 
glBegin(GL_QUADS);
glVertex2f(205,48);
glVertex2f(215,43);
glVertex2f(0,43);
glVertex2f(0,48);
glEnd();

glFlush();
}
void Keyboard(unsigned char key, int x, int y )
{
int temp_int;
float temp;
if(key)
{
//dark bg
glColor3f(0.180, 0.180, 0.180); 
glBegin(GL_POLYGON);
glVertex2f(0,400);
glVertex2f(600,400);
glVertex2f(600,150);
glVertex2f(520,330);
glVertex2f(400,150);
glVertex2f(300,300);
glVertex2f(200,150);
glVertex2f(120,300);
glVertex2f(0,150);
glEnd();
//sun
x = 40;
y = 340;
glColor3f(0.945, 0.749, 0.215);
glBegin(GL_POLYGON);
glVertex2d(x,y);
while(x < 120)
{
x = x + 1;
temp = sqrt(pow(40,2)-pow(x-80,2));
temp_int = temp+0.5;
glVertex2d(x,y+temp_int); 
glVertex2d(x,y-temp_int);
}
glEnd();
//rain
glColor3f(0.803, 0.792, 0.988);
glBegin(GL_LINES);
glVertex2f(310,350);
glVertex2f(305,345);
glEnd();
glColor3f(0.803, 0.792, 0.988);
glBegin(GL_LINES);
glVertex2f(360,250);
glVertex2f(355,245);
glEnd();
glColor3f(0.803, 0.792, 0.988);
glBegin(GL_LINES);
glVertex2f(300,250);
glVertex2f(295,245);
glEnd();
glColor3f(0.803, 0.792, 0.988);
glBegin(GL_LINES);
glVertex2f(400,200);
glVertex2f(395,195);
glEnd();
glColor3f(0.803, 0.792, 0.988);
glBegin(GL_LINES);
glVertex2f(415,240);
glVertex2f(410,235);
glEnd();
glColor3f(0.803, 0.792, 0.988);
glBegin(GL_LINES);
glVertex2f(330,160);
glVertex2f(325,155);
glEnd();
glColor3f(0.803, 0.792, 0.988);
glBegin(GL_LINES);
glVertex2f(500,200);
glVertex2f(495,195);
glEnd();
glColor3f(0.803, 0.792, 0.988);
glBegin(GL_LINES);
glVertex2f(525,250);
glVertex2f(520,245);
glEnd();
glFlush();

}
}
void Mouse(int button, int state, int x, int y)
{
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
//grass
glBegin(GL_LINES);
glVertex2f(350,50);
glVertex2f(350,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(352,50);
glVertex2f(352,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(354,50);
glVertex2f(354,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(356,50);
glVertex2f(356,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(358,50);
glVertex2f(358,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(364,50);
glVertex2f(364,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(370,50);
glVertex2f(370,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(374,50);
glVertex2f(374,54);
glEnd();
glVertex2f(350,50);
glVertex2f(350,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(352,50);
glVertex2f(352,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(354,50);
glVertex2f(354,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(356,50);
glVertex2f(356,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(358,50);
glVertex2f(358,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(364,50);
glVertex2f(364,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(370,50);
glVertex2f(370,54);
glEnd();
glColor3f(0.929, 0.968, 0.113);
glBegin(GL_LINES);
glVertex2f(374,50);
glVertex2f(374,54);
glEnd();
glFlush();

}
}
int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1200,750);
glutInitWindowPosition(500,300);
glutCreateWindow("SCENERY");
init();
glutDisplayFunc(display);
glutKeyboardFunc(Keyboard);
glutMouseFunc(Mouse);
glutMainLoop();
return 0;
}

