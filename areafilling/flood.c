//Flood fill algorithm
#include<stdio.h>
#include<GL/glut.h>
#include<GL/freeglut.h>

int xmin, ymin, xmax, ymax;  //Polygon boundaries

float OldColor[3] = {0.0, 0.0, 0.0};  //Color of the polygon - black
float NewColor[3] = {1.0, 0.0, 0.0};  //Color to be filled - red

void setPixel(int x, int y)   
{   
    glBegin(GL_POINTS);   
        glColor3fv(NewColor);   
        glVertex2i(x, y);   
    glEnd();   
    glFlush();   
}   

void display()   
{    
    glClear(GL_COLOR_BUFFER_BIT);   

    //Drawing polygon
    glColor3fv(OldColor);   
    glBegin(GL_POLYGON);   
        glVertex2i(xmin, ymin);    
        glVertex2i(xmin, ymax);   
        glVertex2i(xmax, ymax);   
        glVertex2i(xmax, ymin);   
    glEnd();   
    glFlush();     
}   

void FloodFill(int x,int y)   
{   
    float CurrentColor[3];   
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, CurrentColor);  

    // if CurrentColor == OldColor
    if(CurrentColor[0] == OldColor[0] && (CurrentColor[1]) == OldColor[1] && (CurrentColor[2]) == OldColor[2])   
    {   
        setPixel(x, y);   
        FloodFill(x+1, y);   
        FloodFill(x-1, y);   
        FloodFill(x, y+1);   
        FloodFill(x, y-1);   
        //Using 4-connected approach, remove comment from below lines to make it 8-connected approach
        FloodFill(x+1, y+1);  
        FloodFill(x+1, y-1);  
        FloodFill(x-1, y+1);  
        FloodFill(x-1, y-1); 
    }   
}   

void mouse(int btn, int state, int x, int y)   
{   
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)       
        FloodFill(x, 500-y);   
}   

void init()
{
    glClearColor(0.101, 1.0, 0.980, 1.0); //Background color - cyan
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)  
{  
    printf("Window size - 500x500 i.e. range of x and y is 0 -> 500\n");
    printf("\nEnter polygon boundaries:-\n");
    printf("Enter xmin: ");
    scanf("%d", &xmin);
    printf("Enter ymin: ");
    scanf("%d", &ymin);
    printf("Enter xmax: ");
    scanf("%d", &xmax);
    printf("Enter ymax: ");
    scanf("%d", &ymax);

    glutInit(&argc, argv);  
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(500, 500);  
    glutCreateWindow("Flood-Fill Algorithm");

    init();
    glutDisplayFunc(display);  
    glutMouseFunc(mouse); 
    glutMainLoop();  
    return 0;  
} 
