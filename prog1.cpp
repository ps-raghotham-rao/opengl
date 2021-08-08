#include <GL/glut.h>
#include<math.h>
#include<stdio.h>
#define scanf_s scanf
GLint xOne, yOne, xTwo, yTwo;

void resize(int, int);
void setPixel(GLint, GLint);
void HLine(GLint, GLint, GLint); void VLine(GLint, GLint, GLint);
void lineBres(GLint, GLint, GLint, GLint, GLfloat); 
void display();

int main(int argc, char**argv)
{
printf("*********Bresenham's Line Drawing Algorithm ************"); 
printf("\nEnter starting vertex (x1, y1):");
scanf_s("%d%d", &xOne, &yOne); 
printf("\nEnter ending vertex (x2, y2):"); 
scanf_s("%d%d", &xTwo, &yTwo);

glutInit(&argc, argv); 					//initialize GLUT
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	 //initialize display mode 
glutInitWindowSize(400, 400); 				//set display-window width & height 
glutInitWindowPosition(800, 50); 			//set display-window upper-left position

//create display-window with a title 
glutCreateWindow("Bresenhams Line Drawing Algorithm");
glutDisplayFunc(display); 			//call graphics to be displayed on the window 
glutReshapeFunc(resize); 			//calls whenever frame buffer window is resized 
glutMainLoop(); 				//display everything and wait
}
void resize(int w, int h)
{  
//set projection paramaters
glMatrixMode(GL_PROJECTION); 
glLoadIdentity();
gluOrtho2D(0.0, w, 0.0, h);
glViewport(0.0, 0.0, w, h);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT); 
GLfloat m;
GLint t;
if(xOne == xTwo)
{
if(yOne > yTwo)
{
t = yOne; yOne = yTwo; yTwo =t;
}
VLine(xOne, yOne, yTwo);  //verticalline
}

else if (yOne == yTwo) // horizontal line
{
	HLine(xOne, yOne, xTwo);
}
else
{
 m = (float)(yTwo - yOne) / (xTwo - xOne); 			//compute slope
//call required function based on value of slope 
if (fabs(m) < 1)
lineBres(xOne, yOne, xTwo, yTwo, m); // slope < one
	else
lineBres(yOne, xOne, yTwo, xTwo, m); // slope >= one

}
}
void lineBres(GLint x0, GLint y0, GLint xEnd, GLint yEnd, GLfloat m)
{
GLint dx = abs(xEnd - x0); 
GLint dy = abs(yEnd - y0); 
GLint p = 2 * dy - dx; 
GLint twoDy = 2 * dy;
GLint twoDyMinusDx = 2 * (dy - dx); 
GLint x = x0, y = y0;
// determine which point to use as start position
if (x0 > xEnd) 
{ 
x = xEnd; 
y = yEnd; 
xEnd = x0; 
} 
else
{ 
x = x0; 
y = y0; 
}
setPixel(x, y); 
while (x<xEnd) 
{ 
x++; 
if (p<0) 
p += twoDy; 
else
{
if (m<0) 
y--; 
else
y++; 
p += twoDyMinusDx; 
} 
setPixel(x, y); 
}
}
void VLine(GLint x1, GLint y1, GLint y2) //vertical line 
{ 
GLint x,y;
 x = x1; 
glBegin(GL_POINTS); 
for (y = y1; y <= y2; y++) 
glVertex2d(x, y); 
glEnd(); 
glFlush(); 
}
void HLine(GLint x1, GLint y1, GLint x2) //horizontal line
{ 
GLint x,y; 
y = y1; 
glBegin(GL_POINTS); 
for (x = x1; x <= x2; x++) 
glVertex2d(x, y); 
glEnd(); 
glFlush(); 
}
void setPixel(GLint xCoordinate, GLint yCoordinate) //to plot point on the screen 
{ 
glBegin(GL_POINTS); 
glVertex2i(xCoordinate, yCoordinate); 
glEnd(); 
glFlush(); //executes all OpenGL functions as quickly as possible 
}