//Boundary fill algorithm
#include<stdio.h>
#include<GL/glut.h>
#include<GL/freeglut.h>

int xmin, ymin, xmax, ymax; //Polygon boundaries

float FillColor[3] = {1.0, 0.0, 0.0};  
float BorderColor[3] = {0.0, 0.0, 0.0};  

void setPixel(int x, int y)  
{  
    glBegin(GL_POINTS);  
        glColor3fv(FillColor);  
        glVertex2i(x, y);  
    glEnd();  
    glFlush();  
}

void display()  
{  
    glClear(GL_COLOR_BUFFER_BIT);  

    //Drawing polygon
    glColor3fv(BorderColor);  
    glLineWidth(6);
    glBegin(GL_LINES);  
        glVertex2i(xmin, ymin);  
        glVertex2i(xmin, ymax);   
    glEnd();  
    glBegin(GL_LINES);  
        glVertex2i(xmax, ymin);  
        glVertex2i(xmax, ymax);  
    glEnd();  
    glBegin(GL_LINES);  
        glVertex2i(xmin, ymin);  
        glVertex2i(xmax, ymin);  
    glEnd();  
    glBegin(GL_LINES);  
        glVertex2i(xmin, ymax);  
        glVertex2i(xmax, ymax);  
    glEnd();  
    glFlush();  
}

void BoundaryFill(int x,int y)  
{  
    float CurrentColor[3];  
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, CurrentColor);  

    // if CurrentColor != BorderColor and CurrentColor != FillColor 
    if((CurrentColor[0] != BorderColor[0] && (CurrentColor[1]) != BorderColor[1] &&
       (CurrentColor[2])!= BorderColor[2]) && (CurrentColor[0] != FillColor[0] && 
       (CurrentColor[1]) != FillColor[1] && (CurrentColor[2]) != FillColor[2]))  
    {  
        setPixel(x, y);  
        BoundaryFill(x+1, y);  
        BoundaryFill(x-1, y);  
        BoundaryFill(x, y+1);  
        BoundaryFill(x, y-1);  
        //added conditions
        BoundaryFill(x+1, y+1);  
        BoundaryFill(x+1, y-1);  
        BoundaryFill(x-1, y+1);  
        BoundaryFill(x-1, y-1); 
    }  
}  

void mouse(int btn, int state, int x, int y)  
{  
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    {
        printf("%d, %d\n", x, y);  
        BoundaryFill(x, 500-y);  
    }
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
    glutCreateWindow("Boundary-Fill Algorithm");

    init();
    glutDisplayFunc(display);  
    glutMouseFunc(mouse); 
    glutMainLoop();  
    return 0;  
} 


