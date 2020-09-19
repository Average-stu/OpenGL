#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>

int del_x, del_y, temp, pk, x, y;
float m, c, x_0, y_0, x_1, y_1;

void init()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
}

void swap(float *a, float *b)
{
	temp = *a; 
	*a = *b; 
	*b = temp;
}

void display() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0.023, 0);
	glPointSize(4.0);	
	glBegin(GL_POINTS);
	
	if(x_0!=x_1)
	{
		m=(y_1-y_0)/(x_1-x_0);
	}
	
	if(x_0==x_1)							//Infinite Slope, Vertical Line
	{
		if(y_0>y_1)
		{
			swap(&y_0,&y_1);
		}
		for(y=y_0; y<=y_1; y++)
		{
			glVertex2f((int)x_0, (int)y);
   		}
	}

	if(m==0)								//m = 0, Horizontal Line
	{
		if(x_0>x_1)
		{
			swap(&x_0,&x_1);
			swap(&y_0,&y_1);
		}
		y=y_0;

		for(x=x_0; x<=x_1; x++)
		{
			glVertex2f(x,y);
		}
	}

	else if(m>0)							//Positive Slope
	{
		if(x_0>x_1)
		{
			swap(&x_0,&x_1);
			swap(&y_0,&y_1);
		}
		del_x=x_1-x_0;
	    del_y=y_1-y_0;
		pk= (2*del_y)-del_x;				
		y=y_0;

		for(x=x_0; x<=x_1; x++)
		{
			if(pk>=0)
			{	
				glVertex2f(x,y);
				pk = pk + 2*del_y - 2*del_x;
				y = y + 1;
			}
			else 
			{
				glVertex2f(x,y);
				pk = pk + 2*del_y;
			}
		}
	}

	else if(m<0)							//Negative Slope		
	{
		if(x_0<x_1)
		{
			swap(&x_0,&x_1);
			swap(&y_0,&y_1);
		}
		del_x=x_1-x_0;
	    del_y=y_1-y_0;
		pk= (2*del_y)-del_x;				
		y=y_0;

		for(x=x_0; x>=x_1; x--)
		{
			if(pk>=0)
			{	
				glVertex2f(x,y);
				pk = pk + 2*del_y - 2*del_x;
				y = y + 1;
			}
			else 
			{
				glVertex2f(x,y);
				pk = pk + 2*del_y;
			}
		}
	}
	glEnd();
	glFlush();
}

int main(int argc,char** argv) 
{ 
	glutInit(&argc,argv);
	printf("Enter coordinates of First line: ");
	scanf("%f %f",&x_0,&y_0); 
	printf("Enter coordinates of Second line: ");
	scanf("%f %f",&x_1,&y_1); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500,300);
	glutInitWindowSize(500,500);
	glutCreateWindow("Bresenham's Algorithm");
	glClearColor(0, 0, 0, 1);
	init();	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0; 
}