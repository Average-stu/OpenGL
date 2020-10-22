//Take a polygon by accepting its vertices in order (Through Keyboard). Perform scaling and rotation operations over this polygon. Show the original and transformed polygons on the display.

//Implementation in C with OpenGL




#include<math.h>
#include<stdio.h>
#include<GL/glut.h>
int numberOfPoints;
int count = 0;
float arr[20][2];
float ox = 200, oy = 200; //Origin Coordinates
void func();
void drawLine(float x1, float ya1, float x2, float ya2, float R, float G, float B){
  glColor3f(R,G,B);
glBegin(GL_LINES);
    glVertex2f(x1,ya1);
    glVertex2f(x2,ya2);
glEnd();
glFlush();
}
void drawPolygon(float (*arr)[2], int n, float R, float G, float B){
  glColor3f(R,G,B);
glBegin(GL_LINE_LOOP);
  int i;
    for(i = 0; i< n; i++)
      glVertex2f(arr[i][0],arr[i][1]);
glEnd();
glFlush();
}
void init(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-200,200,-200,200.0);
}
void tranformation(float arr[][2], int n, float matrix[][3]){
int p,i,j,k;
for(p = 0; p<n; p++){
float tar[][1] = {{0},{0},{0}};
float ar[][1] = {{arr[p][0]},{arr[p][1]},{1}};
for(i=0;i<3;i++)
 {
        for(k=0;k<1;k++)
        {
            for(j=0;j<3;j++)
              tar[i][k] += matrix[i][j]*ar[j][k];
        }}
arr[p][0] = tar[0][0];
arr[p][1] = tar[1][0];
  }
drawPolygon(arr,numberOfPoints, 1, 0, 0);
}
void mousePlotPoint(GLint button, GLint action, GLintxMouse, GLintyMouse)
{
GLintwh=400;
  int x=xMouse-ox;
  int y=wh-yMouse-oy;
  if(button == GLUT_LEFT_BUTTON && action == GLUT_UP && count != -1)
  {
    if(count == 0)   printf("\n\n============================================================\n");
      count++;
printf("\nPoint %d: (%d, %d)",count,x,y);
arr[count-1][0] = x;

 
arr[count-1][1] = y;
      if(count == numberOfPoints)
      {
 
      }}
  else if(button == GLUT_RIGHT_BUTTON && action == GLUT_UP && count != -1){
    count++;
printf("\nPoint %d: (%d, %d)",count,x,y);
arr[count-1][0] = x;
arr[count-1][1] = y;
numberOfPoints = count;
drawPolygon(arr,numberOfPoints, 1, 0, 0);
count = -1; printf("\n\n===============================================================\n");
func();
  }}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
  //drawing axes
drawLine(-200,0,200,0,0,0,1);
drawLine(0,-200,0,200,0,0,1);
}
void func(){
printf("\nTransformations:\n");
  while(count==-1){
printf("\n1.\tTranslation");
printf("\n2.\tRotation");
printf("\n3.\tScaling");
printf("\n4.\tReflection");
printf("\n5.\tShear");
printf("\nEnter choice:");
    int choice;
scanf("%d",&choice);
    switch(choice){
      case 1:
        {
          float tx,ty;
printf("\nEnter value of tx and ty respectively:");
scanf("%f %f", &tx,&ty);
          
 
float matrix[][3] = {{1,0,tx},{0,1,ty},{0,0,1}};
tranformation(arr,numberOfPoints,matrix);
        }
        break;
      case 2:
        {
          double theta;
printf("\nEnter value of angle in degrees in anticlockwise:");
scanf("%lf", &theta);
          theta *= (3.1415926/180);//converting degree into radians
          float sine = sin(theta);
          float cosine = cos(theta);
printf("\n%f %f",sine,cosine);
          float matrix[][3] = {{cosine,-sine,0},{sine,cosine,0},{0,0,1}};
tranformation(arr,numberOfPoints,matrix);
        }
        break;
      case 3:
        {
          float sx,sy;
        printf("\nEnter value of sx and syrespectively:");
         scanf("%f %f", &sx,&sy);
          float matrix[][3] = {{sx,0,0},{0,sy,0},{0,0,1}};
          tranformation(arr,numberOfPoints,matrix);
        }
        break;
      case 4:
        {
          printf("\n1.Reflection about X-axis");
          printf("\n2.Reflection about Y-axis");
          printf("\nEnter choice:");
           int choice2;
          scanf("%d",&choice2);
          float x = 1, y = 1;
          if(choice2==1)
            y = -1;
          else if(choice2==2)
            x = -1;
          else{

 
printf("\nWrong Input");
            break;
          }
          float matrix[][3] = {{x,0,0},{0,y,0},{0,0,1}};
tranformation(arr,numberOfPoints,matrix);
        }
        break;
      case 5:
        {
          float a,b;
printf("\nEnter value of a(shear in X-axis) and b(shear in Y-axis) respectively:");
scanf("%f %f", &a,&b);
          float matrix[][3] = {{1,a,0},{b,1,0},{0,0,1}};
tranformation(arr,numberOfPoints,matrix);
        }
        break;
      default:
printf("\nWrong Input");
    }
  }
}
I   int main(int argc, char** argv)
{glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(400,400);
glutCreateWindow("Tranformations:");
 
init();
glutDisplayFunc(display);
glutMouseFunc(mousePlotPoint);
glutMainLoop();
  return 0;
}

















