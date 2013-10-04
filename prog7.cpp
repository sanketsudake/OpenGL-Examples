#include <GL/glut.h>
#include <cmath>
#include <cstdio>
#include <GL/gl.h>

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init()
{
	glClearColor (0, 0, 0, 0);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0 );
	glBegin(GL_LINE);
	glVertex3f(0, 0, 0);
	glVertex3f(5, 5, 0);
	glEnd();
	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Prac7");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
	return 0;
}
