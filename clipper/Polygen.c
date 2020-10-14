//Sutherland Hodgeman Polygon Clipping algorithm

#include<stdio.h>
#include<GL/glut.h>
#include<GL/freeglut.h>
#include<math.h>
#include<float.h>

#define MAX 10

int xmin, ymin, xmax, ymax; // Windows boundaries
int n, result, points[MAX][2]; //Storing end-points of lines of polygon
int aux[MAX][2]; //Auxillary array to store new end-points

int leftClip(int total) 
{
	int x1, y1, x2, y2, iterator = 0, i;
	float m;
	for (i = 0; i < total; i++)
	{
		x1 = points[i][0];
		y1 = points[i][1];
		x2 = points[(i + 1) % total][0];
		y2 = points[(i + 1) % total][1];

		if (x2 - x1)
			m = (y2 - y1) * 1.0 / (x2 - x1);
		else
			m = FLT_MAX;

		if (x1 < xmin && x2 < xmin)
			continue;
		if (x1 >= xmin && x2 >= xmin) 
		{
			aux[iterator][0] = x2;
			aux[iterator++][1] = y2;
			continue;
		}
		if (x1 >= xmin && x2 < xmin)
		{
			aux[iterator][0] = xmin;
			aux[iterator++][1] = y1 + m * (xmin - x1);
			continue;
		}
		if (x1 < xmin && x2 >= xmin)
		{
			aux[iterator][0] = xmin;
			aux[iterator++][1] = y1 + m * (xmin - x1);
			aux[iterator][0] = x2;
			aux[iterator++][1] = y2;
		}
	}

	for (i = 0; i < iterator; i++)
	{
		points[i][0] = aux[i][0];
		points[i][1] = aux[i][1];
		aux[i][0] = 0;
		aux[i][1] = 0;
	}

	if (iterator < total)
		while (i < total)
		{
			points[i][0] = 0;
			points[i][1] = 0;
			i++;
		}

	return iterator;
}

int topClip(int total) 
{
	int i, iterator = 0, x1, y1, x2, y2;
	float m;
	for (i = 0; i < total; i++) 
	{
		x1 = points[i][0];
		y1 = points[i][1];
		x2 = points[(i + 1) % total][0];
		y2 = points[(i + 1) % total][1];
		if (x2 - x1)
			m = (y2 - y1) * 1.0 / (x2 - x1);
		else
			m = FLT_MAX;

		if (y1 > ymax && y2 > ymax)
			continue;
		if (y1 <= ymax && y2 <= ymax) 
		{
			aux[iterator][0] = x2;
			aux[iterator++][1] = y2;
			continue;
		}
		if (y1 <= ymax && y2 > ymax) 
		{
			aux[iterator][0] = x1 + (ymax - y1) / m;
			aux[iterator++][1] = ymax;
			continue;
		}
		if (y1 > ymax && y2 <= ymax) 
		{
			aux[iterator][0] = x1 + (ymax - y1) / m;
			aux[iterator++][1] = ymax;
			aux[iterator][0] = x2;
			aux[iterator++][1] = y2;
		}
	}

	for (i = 0; i < iterator; i++) 
	{
		points[i][0] = aux[i][0];
		points[i][1] = aux[i][1];
		aux[i][0] = 0;
		aux[i][1] = 0;
	}

	if (iterator < total)
		while (i < total)
		{
			points[i][0] = 0;
			points[i][1] = 0;
			i++;
		}

	return iterator;
}

int rightClip(int total) 
{
	int i, iterator = 0, x1, y1, x2, y2;
	float m;
	for (i = 0; i < total; i++) 
	{
		x1 = points[i][0];
		y1 = points[i][1];
		x2 = points[(i + 1) % total][0];
		y2 = points[(i + 1) % total][1];
		if (x2 - x1)
			m = (y2 - y1) * 1.0 / (x2 - x1);
		else
			m = FLT_MAX;

		if (x1 > xmax && x2 > xmax)
			continue;
		if (x1 <= xmax && x2 <= xmax)
		{
			aux[iterator][0] = x2;
			aux[iterator++][1] = y2;
			continue;
		}
		if (x1 <= xmax && x2 > xmax) 
		{
			aux[iterator][0] = xmax;
			aux[iterator++][1] = y1 + m * (xmax - x1);
			continue;
		}
		if (x1 > xmax && x2 <= xmax) 
		{
			aux[iterator][0] = xmax;
			aux[iterator++][1] = y1 + m * (xmax - x1);
			aux[iterator][0] = x2;
			aux[iterator++][1] = y2;
		}
	}

	for (i = 0; i < iterator; i++) 
	{
		points[i][0] = aux[i][0];
		points[i][1] = aux[i][1];
		aux[i][0] = 0;
		aux[i][1] = 0;
	}

	if (iterator < total)
		while (i < total)
		{
			points[i][0] = 0;
			points[i][1] = 0;
			i++;
		}

	return iterator;
}

int bottomClip(int total)
{
	int i, iterator = 0, x1, y1, x2, y2;
	float m;
	for (i = 0; i < total; i++) 
	{
		x1 = points[i][0];
		y1 = points[i][1];
		x2 = points[(i + 1) % total][0];
		y2 = points[(i + 1) % total][1];
		if (x2 - x1)
			m = (y2 - y1) * 1.0 / (x2 - x1);
		else
			m = FLT_MAX;

		if (y1 < ymin && y2 < ymin)
			continue;
		if (y1 >= ymin && y2 >= ymin) 
		{
			aux[iterator][0] = x2;
			aux[iterator++][1] = y2;
			continue;
		}
		if (y1 >= ymin && y2 < ymin) 
		{
			aux[iterator][0] = x1 + (ymin - y1) / m;
			aux[iterator++][1] = ymin;
			continue;
		}
		if (y1 < ymin && y2 >= ymin) 
		{
			aux[iterator][0] = x1 + (ymin - y1) / m;
			aux[iterator++][1] = ymin;
			aux[iterator][0] = x2;
			aux[iterator++][1] = y2;
		}
	}

	for (i = 0; i < iterator; i++) 
	{
		points[i][0] = aux[i][0];
		points[i][1] = aux[i][1];
		aux[i][0] = 0;
		aux[i][1] = 0;
	}

	if (iterator < total)
		while (i < total)
		{
			points[i][0] = 0;
			points[i][1] = 0;
			i++;
		}

	return iterator;
}

void Keyboard(unsigned char key, int x, int y)
{
	if(key == 'c')
  {
    //Drawing again with clipped part
    glClearColor(0.8, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    //Sutherland-Hodgeman Algorithm
    result = leftClip(n);
    result = topClip(result);
    result = rightClip(result);
    result = bottomClip(result);
    	  
    //Drawing window again
    glColor3f(0, 1, 0);
    glLineWidth(10);
    glBegin(GL_LINE_LOOP);
      glVertex2f(xmin, ymin);
      glVertex2f(xmin, ymin);
      glVertex2f(xmax, ymin);
      glVertex2f(xmax, ymax);
      glVertex2f(xmin, ymax);
    glEnd();

    //Drawing clipped polygon
    glColor3f(0, 0, 1);
    glLineWidth(10);
    glBegin(GL_LINE_STRIP);
      for(int i = 0; i < result; i++)
        glVertex2d(points[i][0], points[i][1]);
      glVertex2d(points[0][0], points[0][1]);
    glEnd();

    glFlush();
  }
}

void display()
{
  //Drawing without clipping
  glClear(GL_COLOR_BUFFER_BIT);

  //Drawing window
  glColor3f(0, 1, 0);
  glLineWidth(10);
  glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
  glEnd();

  //Drawing polygon
  glColor3f(0, 0, 1);
  glLineWidth(10);
  glBegin(GL_LINE_STRIP);
    for(int i = 0; i < n; i++)
      glVertex2d(points[i][0], points[i][1]);
	glVertex2d(points[0][0], points[0][1]);
  glEnd();

  glFlush();
}

void init()
{
    glClearColor(0.8, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
  printf("Window size - 500x500 i.e. range of x and y is 0 -> 500\n");

  printf("\nEnter window boundaries:-\n");
  printf("Enter xmin: ");
  scanf("%d", &xmin);
  printf("Enter ymin: ");
  scanf("%d", &ymin);
  printf("Enter xmax: ");
  scanf("%d", &xmax);
  printf("Enter ymax: ");
  scanf("%d", &ymax);

  printf("\nEnter number of points: ");
  scanf("%d", &n);

  if(n < 3)
  {
    printf("Number of points should be equal to or greater than 3!\n");
    exit(0);
  }
  else
    printf("Enter points in clock-wise/anti-clock-wise order!\n");

  for(int i = 0; i < n; i++)
  {
    printf("Enter point-%d: ", i+1);
    scanf("%d %d", &points[i][0], &points[i][1]);
  }

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Sutherland Hodgeman Polygon Clipping");

  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(Keyboard);
  glutMainLoop();

  return 0;
}

