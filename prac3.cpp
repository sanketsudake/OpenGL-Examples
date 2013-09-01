#include <GL/glut.h>
#include <cmath>
#include <cstdio>
#include <GL/gl.h>



int flag = 0;
float dist1 = -4.0, dist2 = 1.5, angle = 0, sc = 1;

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
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}

void display()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor4f(0.0, 1.0, 0.0, 0.4);
	glPushMatrix();
	glTranslatef(dist1, 0, 0);
	if(flag)
		glRotatef(-angle, 1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(1,-1,0);
	glVertex3f(2,0,0);
	glVertex3f(2,2,0);
	glVertex3f(1,3,0);
	glVertex3f(0,2,0);
	glEnd();
	glPopMatrix();

	glColor4f(0.0, 0.0, 1.0, 0.5);
	glPushMatrix();
	glTranslatef(dist2, 0, 0);
	if(flag){
		glRotatef(angle, 1, 0, 0);
		flag = 0;
	}
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(1,-1,0);
	glVertex3f(2,0,0);
	glVertex3f(2,2,0);
	glVertex3f(1,3,0);
	glVertex3f(0,2,0);
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
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Prac3");
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
	return 0;
}
