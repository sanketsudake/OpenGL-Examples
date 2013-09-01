#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

int flag = 0;
float dist1 = -1.0, dist2 = 1.0, angle = 0, sc = 1;

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, -3.0, 3.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init()
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(dist1, 0, 0);
	if(flag)
		glRotatef(-angle, 0, 1, 0);
	glColor3f(1, 0, 0);
	glutWireTeapot(0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(dist2, 0, 0);
	if(flag){
		glRotatef(angle, 0, 1, 0);
		flag = 0;
	}
	glColor3f(0, 1, 0);
	glBegin(GL_LINE_STRIP); {
		glColor3f(1, 0, 0);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(0.5, -0.5, -0.5);
		glColor3f(1, 1, 0);
		glVertex3f(-0.5, 0.5, -0.5);
		glVertex3f(-0.5, -0.5, -0.5);
		glColor3f(0, 1, 0);
		glVertex3f(-0.5, 0.5, 0.5);
		glVertex3f(-0.5, -0.5, 0.5);
	}
	glEnd();
	glBegin(GL_LINE_STRIP); {
		glColor3f(0, 1, 1);
		glVertex3f(0.5, -0.5, -.5 );
		glVertex3f(-0.5, -0.5, -.5 );
		glVertex3f(0.5, -0.5, .5 );
		glVertex3f(-0.5, -0.5, .5 );
		glColor3f(0, 0, 1);
		glVertex3f(0.5, 0.5, .5 );
		glVertex3f(-0.5,0.5, .5 );
		glColor3f(1, 1, 1);
		glVertex3f(0.5, 0.5,-.5 );
		glVertex3f(-0.5,0.5, -.5 );

	}
	glEnd();
	glPopMatrix();

	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'r':
		flag = 1;
		angle = angle + 5;
		if(angle >= 360)
			angle = 0;
		break;
	case 'f':
		dist1 = dist1 - 0.1;
		dist2 = dist2 + 0.1;
		break;
	case 'b':
		dist1 = dist1 + 0.1;
		dist2 = dist2 - 0.1;
		break;
	case 's':
		sc = sc - 0.002;
		glScalef(sc, sc, sc);
		break;
	case 'a':
		sc = sc + 0.002;
		glScalef(sc, sc, sc);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Prac2");
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
	return 0;
}
