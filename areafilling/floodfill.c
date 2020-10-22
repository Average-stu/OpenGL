//Take vertices of a polygon through the arbitrary mouse clicks. Now fill the polygon so constructed using Flood Fill algorithm.

//Implementation in C with OpenGL




#include<GL/glut.h>
#include<iostream>
 
int numberOfPoints;
float ox = 200,oy = 200;//Origin Coordinates
int count = 0;
 
void init(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-200,200,-200,200.0);
}
void drawLine(float x1, float y1, float x2, float y2, float R, float G, float B){
  glColor3f(R,G,B);
glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
glEnd();
}
void getPixelColor(int x, int y, float *pixel){
glReadPixels(x+oy, y+ox, 1.0, 1.0, GL_RGB, GL_FLOAT, pixel);
}
bool arrCmp(float *arr1, float *arr2, int size){
  for(int i=0;i<size;i++){
    if(arr1[i] != arr2[i])
      return false;
  }
  return true;
}
void plotPoint(int x,int y, float R, float G, float B)
{
 glColor3f(R,G,B);
glBegin(GL_POINTS);
  glVertex2i(x,y);
glEnd();
glFlush();
}
void drawPolygon(int (*arr)[2], int n, float R, float G, float B){
  glColor3f(R,G,B);
glBegin(GL_POLYGON);
    for(int i = 0; i< n; i++)
      glVertex2i(arr[i][0],arr[i][1]);
glEnd();
}
void floodFill4(int x, int y, float *fill, float *old){
  float current[3];
getPixelColor(x,y,current);
  if(arrCmp(old,current,3)){
plotPoint(x,y,fill[0],fill[1],fill[2]);
    floodFill4(x+1,y,fill,old);
    floodFill4(x-1,y,fill,old);
    floodFill4(x,y+1,fill,old);
    floodFill4(x,y-1,fill,old);
  }
}
void mousePlotPoint(GLint button, GLint action, GLintxMouse, GLintyMouse)
{
GLintwh=400;
  float x=xMouse-ox;
  float y=wh-yMouse-oy;
  static int arr[3][2];
 

 if(button == GLUT_LEFT_BUTTON && action == GLUT_UP)
  {
    if(count == -1){
      float fill[] = {0,1,0};
      float old[3];
getPixelColor(x,y,old);
      floodFill4(x,y,fill,old);
    }
    else if(count == 2){
printf("\nPoint: (%f, %f)",x, y);
arr[2][0] = x;
arr[2][1] = y;
      count++;
drawPolygon(arr,count,1,0,0);
      printf("\n\n=========================================================================\n");
      count = -1;
    }
    else{
printf("\nPoint: (%f, %f)",x, y);
arr[count][0] = x;
arr[count][1] = y;
      count++;
    }
 
  }
glFlush();
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
 
  //drawing axes
drawLine(-200,0,200,0,0,0,1);
drawLine(0,-200,0,200,0,0,1);
glFlush();
}
 
 
 
 
int main(int argc, char** argv)
{
 glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(0,0);
 glutInitWindowSize(400,400);
 glutCreateWindow("Flood Fill");
 
 init();
 glutDisplayFunc(display);
 glutMouseFunc(mousePlotPoint);
 
 glutMainLoop();
  return 0;
}

