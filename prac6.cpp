/* Lighting Effects
 */

#include <GL/glut.h>
#include <GL/glu.h>
#include <cmath>
#include <cstdio>
#include <GL/gl.h>
#include <opencv2/opencv.hpp>
#include <
void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-6.0, 6.0, -6.0, 6.0, -6.0, 6.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init()
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Face 1
	GLuint image = loadBMP_custom("paren.bmp");
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);
	glVertex3f(2, 0, 0);
	glVertex3f(2, 2, 0);
	glVertex3f(0, 2, 0);
	glEnd();

	// Face 2
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(2, 0, 0);
	glVertex3f(2, 0, 2);
	glVertex3f(2, 2, 2);
	glVertex3f(2, 2, 0);
	glEnd();

	// Face 3
	glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 2);
	glVertex3f(2, 0, 2);
	glVertex3f(2, 2, 2);
	glVertex3f(0, 2, 2);
	glEnd();

	// Face 4
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 2);
	glVertex3f(0, 2, 2);
	glVertex3f(0, 2, 0);
	glEnd();

	// Face 5
	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(0, 2, 0);
	glVertex3f(0, 2, 2);
	glVertex3f(2, 2, 2);
	glVertex3f(2, 2, 0);
	glEnd();

	// Face 6
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 2);
	glVertex3f(2, 0, 2);
	glVertex3f(2, 0, 0);
	glEnd();

	glFlush();
}

void keyboard(unsigned char c, int x, int y)
{
	switch(c)
	{
	case 'r':
	case 'R':

		glRotatef(10, 1, 0, 1 );
		glutPostRedisplay();
		break;

	}
}

int main(int argc, char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Prac6");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}
