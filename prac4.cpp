/* Lighting Effects
 */

#include <GL/glut.h>
#include <cmath>
#include <cstdio>
#include <GL/gl.h>

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
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GLfloat mat_emission[] = { 0.2, 0.2, 0.8, 0.0};
	GLfloat mat_specular[] = { 0.4, 0.4, 0.3, 1.0 };
	GLfloat mat_shininess[] = {  50.0 };
	GLfloat dis[] = { 0.0, 0.0, 0.0, 1.0};
	GLfloat dis_shininess[] = { 0.0 };

	GLfloat light_position[] = { -1.0, -1.0, 0.0, 0.0 };
	GLint x_arr[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1};
	GLint y_arr[] = { 1, 1, 1, 0, 0, 0, -1, -1, -1};

	glColor4f(0.5, 0.5 , 0.5, 0);
	for(int i = 0; i < 9; i++)
	{

		glPushMatrix();
		 if(x_arr[i] == -1)
		 {
		 	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		 	glMaterialfv(GL_FRONT, GL_SPECULAR, dis);
		 	glMaterialfv(GL_FRONT, GL_SHININESS, dis_shininess);
		 }
		 if(x_arr[i] == 0)
		 {
		 	glMaterialfv(GL_FRONT, GL_EMISSION, dis);
		 	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		 	glMaterialfv(GL_FRONT, GL_SHININESS, dis_shininess);
		 }
		 if(x_arr[i] == 1)
		 {
		 	glMaterialfv(GL_FRONT, GL_EMISSION, dis);
		 	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		 	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		 }
		 if(y_arr[i] == 1)
		 {
		 	glLightf(GL_LIGHT0, GL_DIFFUSE, 0.1);
		 }
		 if(y_arr[i] == 0)
		 {
			 glLightf(GL_LIGHT0, GL_DIFFUSE, 0.5);
		 }
		 if(y_arr[i] == -1)
		 {
			 glLightf(GL_LIGHT0, GL_DIFFUSE, 1.0);
		 }
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glTranslatef(4 * x_arr[i],  4 * y_arr[i], 0);
		glutSolidSphere(1.0, 100, 100);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_DEPTH_TEST);
		glPopMatrix();
	}
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Prac4");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
	return 0;
}
