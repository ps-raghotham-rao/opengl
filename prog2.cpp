// #include<windows.h>
#include<GL/glut.h>
#include<iostream>
using namespace std;
GLfloat angle;
void triangle()
{
glBegin(GL_LINE_LOOP);
glVertex2i(100, 250);
glVertex2i(175,350);
glVertex2i(250, 250);
glEnd();
glFlush();
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(1, 1, 1, 1);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
triangle();
glRotatef(angle, 0.0, 0.0, 1.0);
glTranslatef(-100, -250, 0.0);
triangle();
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(100, 250, 0.0);
glRotatef(angle, 0.0, 0.0, 1.0);
glTranslatef(-100, -250, 0.0);
triangle();
}
int main(int argc, char**argv)
{
cout<< "Ënter the angle of rotation";
cin>> angle;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1000, 1000);

glutCreateWindow("Triangle Rotation");
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 500, 0, 500);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}