/*
Assignment No : 1
Title: .
Name : Sanket Sudake
Year : BE 	  Div: D	Roll No: 48
*/
#include <cstdio>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>

const GLfloat PI = 3.1415;
void init();
void display();

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Prac 1");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
    return 0;
}

void init()
{
	/* Set background in window to white
	 */
	glClearColor(47.0/255.0, 79.0/255.0, 79.0/255.0, 0.5);
	glClearColor(108.0/255.0, 123.0/255.0, 139.0/255.0, 0.5);
	/* Set window co-ordinate system
	 */
	glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
}

void display()
{
	/* Clear all pixels
	 */
	glClear(GL_COLOR_BUFFER_BIT);

	GLfloat xt = 1.1, yt = 1.15;
	glColor3f(255.0/255.0, 215.0/255.0, 0.0/255.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(xt + 0, yt + 0.1, 0);
	glVertex3f(xt + 0.4, yt + 0.5, 0);
	glVertex3f(xt + 0.1, yt + 0, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(xt + 0, yt + 0.1, 0);
	glVertex3f(xt + 0.5, yt + 0.4, 0);
	glVertex3f(xt + 0.1, yt + 0, 0);
	glEnd();

	xt = -0.7, yt = 0.0;
	glColor3f(205.0/255.0, 133.0/255.0, 63.0/255.0);
	glBegin(GL_POLYGON);
	glVertex3f(xt + 0.3, yt + 0.1, 0);
	glVertex3f(xt - 0.1, yt + 0.4, 0);
	glVertex3f(xt - 0.9, yt + 0.0, 0);
	glVertex3f(xt + 0.0, yt - 0.3, 0);
	glEnd();


	/* Draw a circle
	 */
	GLint points = 100;
	GLfloat angle;
	glColor3f(130.0/255.0, 69.0/255.0, 19.0/255.0);
	glBegin(GL_POLYGON);
	for(GLint i = 0; i < points; i++)
	{
		angle = (2 * PI * i) / points;
		glVertex3f(cos(angle), sin(angle), 0);
	}
	glEnd();

    /* Draw a circle
	 */
	glColor3f(205.0/255.0, 133.0/255.0, 63.0/255.0);
	glBegin(GL_POLYGON);
	for(GLint i = 0; i < points; i++)
	{
		angle = (2 * PI * i) / points;
		glVertex3f(cos(angle)/2 + 0.8, sin(angle)/2 + 1.0, 0);
	}
	glEnd();

	/* Draw a circle
	 */
	glColor3f(255.0/255.0, 255.0/255.0, 255.0/255.0);
	glBegin(GL_POLYGON);
	for(GLint i = 0; i < points; i++)
	{
		angle = (2 * PI * i) / points;
		glVertex3f(cos(angle)/8 + 1.0, sin(angle)/8 + 1.1, 0);
	}
	glEnd();

	/* Draw a circle
	 */
	glColor3f(0.0/255.0, 0.0/255.0, 0.0/255.0);
	glBegin(GL_POLYGON);
	for(GLint i = 0; i < points; i++)
	{
		angle = (2 * PI * i) / points;
		glVertex3f(cos(angle)/20 + 1.0, sin(angle)/24 + 1.1, 0);
	}
	glEnd();

	glColor3f(205.0/255.0, 133.0/255.0, 63.0/255.0);
	glBegin(GL_POLYGON);
	for(GLint i = 100; i > 0; i--)
	{
		angle = (2 * 2.8 * i) / points;
		glVertex3f(cos(angle)/2, sin(angle)/3, 0);
	}
	glEnd();

	glColor3f(205.0/255.0, 92.0/255.0, 92.0/255.0);
	GLfloat arrx[] = {0.7, 0.8, 0.7, 0.45};
	GLfloat arry[] = {0.35, 0.0, -0.4, -0.7};
	for(GLint i = 0; i < 4; i++){
		xt = arrx[i];
		yt = arry[i];
		glBegin(GL_POLYGON);
		for(GLint i = 0; i < points; i++)
		{
			angle = (2 * PI * i) / points;
			glVertex3f(cos(angle)/12 + xt, sin(angle)/12 + yt, 0);
		}
		glEnd();
	}

	xt = -0.2 , yt = 0.1;
	glColor3f(0.0/255.0, 0.0/255.0, 0.0/255.0);
	glBegin(GL_POLYGON);
	glVertex3f(xt + 0, yt -1, 0);
	glVertex3f(xt + 0, yt -2, 0);
	glVertex3f(xt + 0.1,yt -1, 0);
	glVertex3f(xt + 0.1,yt -1, 0);
	glEnd();

	xt = 0.2 , yt = 0.1;
	glColor3f(0.0/255.0, 0.0/255.0, 0.0/255.0);
	glBegin(GL_POLYGON);
	glVertex3f(xt + 0.1, yt -1, 0);
	glVertex3f(xt + 0.1, yt -2, 0);
	glVertex3f(xt + 0, yt -1, 0);
	glVertex3f(xt + 0, yt -1, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.2, -1.8, 0);
	glVertex3f(-0.0, -1.8, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.2, -1.8, 0);
	glVertex3f(-0.0, -1.9, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.2, -1.8, 0);
	glVertex3f(-0.0, -2.0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.3, -1.8, 0);
	glVertex3f(0.5, -1.8, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.3, -1.8, 0);
	glVertex3f(0.5, -1.9, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.3, -1.8, 0);
	glVertex3f(0.5, -2.0, 0);
	glEnd();

	glFlush();
}
